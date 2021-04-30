#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"

System::Void schoolcourseProject::Teachers::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length) &&
        textBoxClassroom->Text->Length)
    {
        MessageBox::Show("Вы не ввели все данные!", "Внимание!");
        return;
    }

    //проверяем, чтобы был выбран конкретный класс
    if (domainUpDownClasses->Text == "Все")
    {
        MessageBox::Show("Вы не выбрали конкретный класс!", "Внимание!");
        return;
    }

    //проверяем, чтобы был выбран конкретный предмет
    if (domainUpDownSubjects->Text == "Все")
    {
        MessageBox::Show("Вы не выбрали конкретный предмет!", "Внимание!");
        return;
    }

    String^ id_teacher;
    String^ id_class;
    String^ id_subject;

    //подключение к БД
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение    

    //запрос для класса
    String^ query = 
        "SELECT id_teacher " +
        "FROM Teacher " +
        "WHERE name_teacher LIKE '" + textBoxName->Text + "' " +
        "AND surname_teacher LIKE '" + textBoxSurname->Text + "' " +
        "AND patronymic_teacher LIKE '" + textBoxPatronymic->Text + "' ;";;
        //делаем запрос для нахождение id класса
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    auto dbReaderTeacher = dbCommand->ExecuteReader();

    //Проверяем есть ли такой учитель
    if (!dbReaderTeacher->HasRows) {
        //Если нет то добавляем
        dbReaderTeacher->Close();

        dbCommand->CommandText = 
            "INSERT INTO Teacher(name_teacher, surname_teacher, patronymic_teacher, classroom) "+
            "VALUES ('"+textBoxName->Text+"', '"+textBoxSurname->Text+"', '"+textBoxPatronymic->Text+"', '"+textBoxClassroom->Text+"');";
        dbCommand->ExecuteNonQuery();

        dbCommand->CommandText = "SELECT MAX(id_teacher) FROM Teacher";
        dbReaderTeacher = dbCommand->ExecuteReader();
    }

    dbReaderTeacher->Read();
    id_teacher = dbReaderTeacher[0]->ToString();
    dbReaderTeacher->Close();

  
    //запрос для класса
    dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "' ;"; //делаем запрос для нахождение id класса
    auto dbReaderClass = dbCommand->ExecuteReader();

    //читаем класс
    dbReaderClass->Read();
    id_class = dbReaderClass[0]->ToString();
    dbReaderClass->Close();
    
    //меняем команду на предмет

    dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text + "' ;"; //делаем запрос для нахождение id класса
    auto dbReaderSubject = dbCommand->ExecuteReader();

    //читаем предмет
    dbReaderSubject->Read();
    id_subject = dbReaderSubject[0]->ToString();
    dbReaderSubject->Close();
    
    //Проверяем есть ли такая запись в Class_to_teacher
    
    dbCommand->CommandText = "SELECT * " +
        "FROM Class_to_teacher " +
        "WHERE " +
        "id_class = " + id_class + " AND " +
        "id_teacher = " + id_teacher + " AND " +
        "id_subject = " + id_subject + ";";

    if(dbCommand->ExecuteNonQuery() < 1)
    {     
        dbCommand->CommandText =
            "INSERT INTO Class_to_teacher (id_class, id_teacher, id_subject) " +
            "VALUES (" + id_class + "," + id_teacher + ", "+id_subject+");";
        dbCommand->ExecuteNonQuery();
    }
    else 
    {
        MessageBox::Show("Такая запись уже есть!","Внимание!");
        return;
    }

    MessageBox::Show("Запись успешно добавлена!");

    dataGridViewTeachers->Rows->Clear();
    Teachers_Load(nullptr, nullptr); 

    ClearTextBoxTeachers();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length) &&
        textBoxClassroom->Text->Length)
    {
        MessageBox::Show("Вы не ввели все данные!", "Внимание!");
        return;
    }

    //проверяем, чтобы был выбран конкретный класс
    if (domainUpDownClasses->Text == "Все")
    {
        MessageBox::Show("Вы не выбрали конкретный класс!", "Внимание!");
        return;
    }

    //проверяем, чтобы был выбран конкретный предмет
    if (domainUpDownSubjects->Text == "Все")
    {
        MessageBox::Show("Вы не выбрали конкретный предмет!", "Внимание!");
        return;
    }

    //Проверяем есть ли выбранные строки
    if (dataGridViewTeachers->SelectedRows->Count != 1) {
        MessageBox::Show("Выбирите одну строку!", "Внимание!");
        return;
    }
    int index = dataGridViewTeachers->SelectedRows[0]->Index;

    String^ id_teacherTB = textBoxID->Text->ToString();
    String^ id_classTB;
    String^ id_subjectTB;
    String^ id_teacherSG = dataGridViewTeachers->Rows[index]->Cells["ID"]->Value->ToString();
    String^ id_classSG;
    String^ id_subjectSG;
    String^ id_class_teacher;

    if (id_teacherTB != id_teacherSG) {
        MessageBox::Show("Выбирите одну строку!", "Внимание!");
        return;
    }

    //подключение к БД
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение
    
     //запрос на обновление таблицы
    String^ query =
        "UPDATE Teacher " +
        "SET name_teacher = '" + textBoxName->Text + "', " +
        "surname_teacher = '" + textBoxSurname->Text + "', " +
        "patronymic_teacher = '" + textBoxPatronymic->Text + "', " +
        "classroom = " + textBoxClassroom->Text +" "+
        "WHERE id_teacher = " + id_teacherSG + ";";
    
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    dbCommand->ExecuteNonQuery();

    /*-----------------------------НА КОТОРЫЙ ПРОИСХОДИТ ЗАМЕНА -----------------------------------*/

    //запрос для класса НА КОТОРЫЙ ПРОИСХОДИТ ЗАМЕНА 
    
        dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "' ;"; //делаем запрос для нахождение id класса
        auto dbReaderClass = dbCommand->ExecuteReader();

    //читаем класс
        dbReaderClass->Read();
        id_classTB = dbReaderClass[0]->ToString();
        dbReaderClass->Close();
    
    //меняем команду на предмет НА КОТОРЫЙ ПРОИСХОДИТ ЗАМЕНА
    
        dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text + "' ;"; //делаем запрос для нахождение id класса
        auto dbReaderSubject = dbCommand->ExecuteReader();

    //читаем предмет
        dbReaderSubject->Read();
        id_subjectTB = dbReaderSubject[0]->ToString();
        dbReaderSubject->Close();
    
  /*----------------------КОТОРЫЙ МЕНЯЕМ----------------------------*/

    dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + dataGridViewTeachers->Rows[index]->Cells["Class"]->Value->ToString() + "' ;"; //делаем запрос для нахождение id класса
    dbReaderClass = dbCommand->ExecuteReader();

    //читаем класс
    if (dbReaderClass->HasRows)
    {
        dbReaderClass->Read();
        id_classSG = dbReaderClass[0]->ToString();
        dbReaderClass->Close();
    }
    else 
    {
        id_classSG = "0";
    }

    //меняем команду на предмет КОТОРЫЙ МЕНЯЕМ

    dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + dataGridViewTeachers->Rows[index]->Cells["Subject"]->Value->ToString() + "' ;"; //делаем запрос для нахождение id класса
    dbReaderSubject = dbCommand->ExecuteReader();

    //читаем предмет
    if (dbReaderSubject->HasRows)
    {
        dbReaderSubject->Read();
        id_subjectSG = dbReaderSubject[0]->ToString();
        dbReaderSubject->Close();
    }
    else
    {
        id_subjectSG = "0";
    }
    //Ищем id строки которую нужно изменить

    dbCommand->CommandText = "SELECT id_class_teacher " +
        "FROM Class_to_teacher " +
        "WHERE id_teacher = " + id_teacherSG + 
        " AND id_class = " + id_classSG + 
        " AND id_subject = " + id_subjectSG + ";";
    auto dbReaderClassTeacher = dbCommand->ExecuteReader();

    dbReaderClassTeacher->Read();
    id_class_teacher = dbReaderClassTeacher[0]->ToString();
    dbReaderClassTeacher->Close();

    //Обновляем строку
    dbCommand->CommandText =
        "UPDATE Class_to_teacher " +
        " SET id_class = " + id_classTB + ", id_subject = " + id_subjectTB +
        " WHERE id_class_teacher = " + id_class_teacher + ";";

    dbCommand->ExecuteNonQuery();
    //Закрываем соединение
    dbConnection->Close();

    //Обновляем таблицу
    dataGridViewTeachers->Rows->Clear();
    Teachers_Load(nullptr,nullptr);

    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    //проверяем выбрана ли строка для удаления
    if (dataGridViewTeachers->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите строку для удаления", "Внимание!");
        return;
    }

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query =
        "DELETE FROM Class_to_teacher WHERE id_teacher =" + textBoxID->Text + " " +
        " AND id_class IN (SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text->ToString() + "') " +
        " AND id_subject IN(SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text->ToString() + "');";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка удаления информации об учителе");
        dbConnection->Close();
        return;
    }


    dbCommand->CommandText="DELETE FROM Teacher WHERE id_teacher =" + textBoxID->Text +" " +
        " AND id_teacher NOT IN(SELECT id_teacher FROM Class_to_teacher) ";
    dbCommand->ExecuteNonQuery();

    MessageBox::Show("Запись успешно удалена", "Внимание!");

    //обновляем записи в таблица
    dataGridViewTeachers->Rows->Clear();
    Teachers_Load(nullptr, nullptr);
    ClearTextBoxTeachers();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::Teachers_Load(System::Object^ sender, System::EventArgs^ e)
{
    //подключение к БД
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение


    String^ query = 
        "SELECT "+
        "Teacher.id_teacher, "+
        "surname_teacher, "+
        "name_teacher, "+ 
        "patronymic_teacher, "+
        "name_subject, "+
        "classroom, "+
        "number_class "+
        "FROM "+
        "( "+
            "( "+
                "( "+
                    "Class_to_teacher "+
                    "INNER JOIN Teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher "+
                    ") "+ 
                "LEFT JOIN Class ON Class_to_teacher.id_class = Class.id_class "+
                ") "+
            "INNER JOIN Subject ON Subject.id_subject = Class_to_teacher.id_subject "+
        "); "; //делаем запрос
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    OleDbDataReader^ dbReaderTeacher = dbCommand->ExecuteReader(); //вызов предыдущей команды

    while (dbReaderTeacher->Read())
    {
        dataGridViewTeachers->Rows->Add(
            dbReaderTeacher[0],
            dbReaderTeacher[1],
            dbReaderTeacher[2],
            dbReaderTeacher[3],
            dbReaderTeacher[4],
            dbReaderTeacher[5],
            dbReaderTeacher[6]);//вносим строки в таблицу
    }

    //закрываем соединения
    dbReaderTeacher->Close();

    if (domainUpDownSubjects->Items->Count == 1)
    {
        //Запрос на выборку всех предмеов
        dbCommand->CommandText = "SELECT name_subject FROM Subject";
        auto dbReaderSubject = dbCommand->ExecuteReader();

        while (dbReaderSubject->Read())
        {
            domainUpDownSubjects->Items->Add(dbReaderSubject[0]->ToString());
        }

        //закрываем соединения
        dbReaderSubject->Close();
    }

    if (domainUpDownClasses->Items->Count == 1)
    {
        dbCommand->CommandText = "SELECT number_class FROM Class ORDER BY 1"; //делаем запрос

        //считываем данные 
        auto dbReaderClass = dbCommand->ExecuteReader();

        if (!dbReaderClass->HasRows)
        {
            MessageBox::Show("Ошибка чтения!", "Внимание!");
            dbConnection->Close();//закрываем соединение
            return;
        }

        while (dbReaderClass->Read())
        {
            domainUpDownClasses->Items->Add(dbReaderClass[0]);//записываем данные из бд д
        }
        dbReaderClass->Close();
    }
 

    //Закрываем соединение
    dbConnection->Close();

    return System::Void();
}

System::Void schoolcourseProject::Teachers::FillingTextBoxTeachers(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //проверяем выбранные строки
    if (dataGridViewTeachers->SelectedRows->Count == 0)
    {
        return;
    }

    int index = dataGridViewTeachers->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewTeachers->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBoxTeachers(); //очистка полей ввода
        return;
    }

    //заполнение текстбоксов
    textBoxID->Text = dataGridViewTeachers->Rows[index]->Cells[0]->Value->ToString();
    textBoxSurname->Text = dataGridViewTeachers->Rows[index]->Cells[1]->Value->ToString();
    textBoxName->Text = dataGridViewTeachers->Rows[index]->Cells[2]->Value->ToString();
    textBoxPatronymic->Text = dataGridViewTeachers->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownSubjects->Text = dataGridViewTeachers->Rows[index]->Cells[4]->Value->ToString();
    textBoxClassroom->Text = dataGridViewTeachers->Rows[index]->Cells[5]->Value->ToString();
    domainUpDownClasses->Text = dataGridViewTeachers->Rows[index]->Cells[6]->Value->ToString();

    return System::Void();
}

System::Void schoolcourseProject::Teachers::ClearTextBoxTeachers()
{
    textBoxID->Text = "";
    textBoxSurname->Text = "";
    textBoxName->Text = "";
    textBoxPatronymic->Text = "";
    textBoxClassroom->Text = "";

    return System::Void();
}

System::Void schoolcourseProject::Teachers::domainUpDownSubjects_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{

    if (dataGridViewTeachers->SelectedRows->Count == 1)
        return;


    auto rows = dataGridViewTeachers->Rows;
    int selectedIndex = domainUpDownSubjects->SelectedIndex;

    for (int i = 0; i < rows->Count - 1; i++) {
        rows[i]->Visible = true;
    }

    if (domainUpDownSubjects->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownSubjects->Text)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownClasses->Text)
                rows[i]->Visible = false;
        }
    }
    return System::Void();
}

System::Void schoolcourseProject::Teachers::domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewTeachers->SelectedRows->Count == 1)
        return;

    auto rows = dataGridViewTeachers->Rows;

    for (int i = 0; i < rows->Count - 1; i++) {
        rows[i]->Visible = true;
    }

    if (domainUpDownSubjects->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownSubjects->Text)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Class"]->Value->ToString() != domainUpDownClasses->Text)
                rows[i]->Visible = false;
        }
    }
    return System::Void();
}
