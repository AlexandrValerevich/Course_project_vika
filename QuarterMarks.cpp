#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"
#include "dbQuery.h"

/*-------------------------------КНОПКИ ПЕРЕКЛЮЧЕНИЯ МЕЖДУ ФОРМАМИ И КНОПКА ВЫХОДА----------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------КНОПКИ ДОБАВИТЬ УДАЛИТЬ ИЗМЕНИТЬ----------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (domainUpDownClasses->SelectedIndex == 0)
    {
        MessageBox::Show("Вы не ввели класс!", "Внимание!");
        return;
    }

    if (domainUpDownPupil->SelectedIndex == 0)
    {
        MessageBox::Show("Вы не выбрали ученика!", "Внимание!");
        return;
    }

    if (domainUpDownSubjects->SelectedIndex == 0)
    {
        MessageBox::Show("Вы не выбрали предмет!", "Внимание!");
        return;
    }

    int Mark;    
    auto isNum = Int32::TryParse(textBoxMark->Text, Mark);

    if (!isNum) {
        MessageBox::Show("Оценка должна быть числом!", "Внимание!");
        return;
    }

    if (Mark < 0 || Mark > 10)
    {
        MessageBox::Show("Оценка должна быть в диапазоне от 0 до 10!", "Внимание!");
        return;
    }

    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";
    String^ Pupil = "'" + domainUpDownPupil->Text + "'";
    String^ Subject = "'" + domainUpDownSubjects->Text + "'";

    String^ id_pupil;
    String^ id_class_teahcer;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    /*Выбираем id ученика*/
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;
    String^ SELECT = "id_pupil";
    String^ FROM = "Pupil";
    String^ WHERE = 
        "surname_pupil & ' ' & name_pupil LIKE " + Pupil + 
        " AND id_class IN (SELECT id_class FROM Class WHERE number_class LIKE " + NumberClass + ")";

    id_pupil = SelectID(dbConnection, SELECT, FROM, WHERE);

    /*Находим id_class_teacher по признака класса и предмета 
    с учетом того что у одного класс один 
    предмет может вести только один преподаватель*/
    SELECT = "id_class_teacher";
    FROM = "Class_to_teacher";
    WHERE = "id_class IN (SELECT id_class FROM Class WHERE number_class LIKE " + NumberClass + ")" +
        " AND id_subject IN(SELECT id_subject FROM Subject WHERE name_subject LIKE " + Subject + ")";

    id_class_teahcer = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "Mark";
    COLUMN = "mark, id_pupil, id_class_teacher";
    VALUES = Mark + "," + id_pupil + "," + id_class_teahcer;
    WHERE = "id_pupil = " + id_pupil + " AND id_class_teacher = "+ id_class_teahcer;

    if (!String::IsNullOrEmpty(SelectID(dbConnection, COLUMN, TABLE, WHERE))) {
        MessageBox::Show("У ученика уже стоит оценка!","Внимание!");
        return;
    }

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("Ошибка добавления учителя!", "Внимание!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("Оценка успешно добавлена!");

    QuarterMarks_Load(nullptr, nullptr);
    //Закрываем соединение
    dbConnection->Close();

	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите одну строку!", "Внимание!");
        return;
    }

    int Mark;
    auto isNum = Int32::TryParse(textBoxMark->Text, Mark);

    if (!isNum) {
        MessageBox::Show("Оценка должна быть числом!", "Внимание!");
        return;
    }

    if (Mark < 0 || Mark > 10)
    {
        MessageBox::Show("Оценка должна быть в диапазоне от 0 до 10!", "Внимание!");
        return;
    }

    String^ id_mark = textBoxID->Text;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    /*Выбираем id ученика*/
    String^ TABLE = "Mark";
    String^ SET = "mark = "+ Mark;
    String^ WHERE = "id_mark = " + id_mark;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
    {
        MessageBox::Show("Ошибка обновления ученика!", "Внимание!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("Оценка успешно Измененена!");

    QuarterMarks_Load(nullptr, nullptr);
    //Закрываем соединение
    dbConnection->Close();
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите одну строку!", "Внимание!");
        return;
    }

    String^ id_mark = textBoxID->Text;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    /*Выбираем id ученика*/
    String^ FROM = "Mark";
    String^ WHERE = "id_mark = " + id_mark;

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("Ошибка удаления оценки!", "Внимание!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("Оценка успешно удалена!");

    QuarterMarks_Load(nullptr, nullptr);
    //Закрываем соединение
    dbConnection->Close();
	return System::Void();
}

/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::QuarterMarks_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewMarks->Rows->Clear();

    //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "id_mark, number_class, surname_pupil, name_pupil, name_subject, mark";
    String^ FROM =
        "(((Pupil " +
        "INNER JOIN Class ON Pupil.id_class = Class.id_Class) " +
        "INNER JOIN Mark ON Pupil.id_pupil = Mark.id_pupil) " +
        "INNER JOIN Class_to_teacher ON Mark.id_class_teacher = Class_to_teacher.id_class_teacher) " +
        "INNER JOIN Subject ON Class_to_teacher.id_subject = Subject.id_subject";
    String^ ORDER_BY = "number_class,surname_pupil, name_pupil";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewMarks->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();

    if (domainUpDownClasses->Items->Count == 1)
    {
        SELECT = "number_class";
        FROM = "Class";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownClasses->Items->Add(dbReader[0]);//записываем данные из бд д
        domainUpDownClasses->SelectedIndex = 0;

        dbReader->Close();
    }

    if (domainUpDownSubjects->Items->Count == 1)
    {
        //Запрос на выборку всех предмеов
        SELECT = "name_subject";
        FROM = "Subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());
        domainUpDownSubjects->SelectedIndex = 0;
        //закрываем соединения
        dbReader->Close();
    }

    if (domainUpDownPupil->Items->Count == 1)
    {
        //Запрос на выборку всех предмеов
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());
        domainUpDownPupil->SelectedIndex = 0;
        //закрываем соединения
        dbReader->Close();
    }

    //Закрываем соединение
    dbConnection->Close();
}

System::Void schoolcourseProject::QuarterMarks::FillingTextBoxQuarterMarks(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1)
        return;

    int index = dataGridViewMarks->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewMarks->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBoxQuarterMarks(); //очистка полей ввода
        return;
    }

    textBoxID->Text = dataGridViewMarks->Rows[index]->Cells[0]->Value->ToString();
    domainUpDownClasses->Text = dataGridViewMarks->Rows[index]->Cells[1]->Value->ToString();
    domainUpDownPupil->Text =
        dataGridViewMarks->Rows[index]->Cells[2]->Value->ToString() + " "+
        dataGridViewMarks->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownSubjects->Text = dataGridViewMarks->Rows[index]->Cells[4]->Value->ToString();
    textBoxMark->Text = dataGridViewMarks->Rows[index]->Cells[5]->Value->ToString();

	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::ClearTextBoxQuarterMarks()
{
    textBoxID->Text = nullptr;
    textBoxMark->Text = nullptr;

    domainUpDownClasses->SelectedIndex = 0;
    domainUpDownPupil->SelectedIndex = 0;
    domainUpDownSubjects->SelectedIndex = 0;

	return System::Void();
}

/*-------------------------------------------СОБЫТИЯ ОТВЕЧАЮЩИЕ ЗА ВЫБОРКУ ЭЛЕМЕНТОВ----------------------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count == 1)
        return;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT;
    String^ FROM;
    String^ WHERE;

    auto rows = dataGridViewMarks->Rows;
    int selectedIndex = domainUpDownSubjects->SelectedIndex;

    String^ Pupil;
    String^ NumberClass;
    String^ Subject;

    for (int i = 0; i < rows->Count - 1; i++)
        rows[i]->Visible = true;

    if (domainUpDownClasses->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            NumberClass = rows[i]->Cells["NumberClass"]->Value->ToString();
            if (domainUpDownClasses->Text != NumberClass)
                rows[i]->Visible = false;
        }

        domainUpDownPupil->Items->Clear();
        domainUpDownPupil->Items->Add("Все");
        //Запрос на выборку всех предмеов
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";
        WHERE = "id_class IN (SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "')";

        auto dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());
       
        domainUpDownPupil->SelectedIndex = 0;
        //закрываем соединения
        dbReader->Close();

        domainUpDownSubjects->Items->Clear();
        domainUpDownSubjects->Items->Add("Все");

        SELECT = "name_subject";
        FROM = "Subject";
        WHERE = "id_subject IN(SELECT id_subject FROM Class_to_teacher WHERE id_class IN(SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "'))";
        
        dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());

        domainUpDownSubjects->SelectedIndex = 0;
        //закрываем соединения
        dbReader->Close();
    }
    else {
        //Запрос на выборку всех предмеов
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";

        auto dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());

        //закрываем соединения
        dbReader->Close();

        SELECT = "name_subject";
        FROM = "Subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());
        domainUpDownSubjects->SelectedIndex = 0;
        //закрываем соединения
        dbReader->Close();
    }

    //Закрываем соединение
    dbConnection->Close();

    if (domainUpDownPupil->Text != "Все") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Pupil = rows[i]->Cells["SurnameStudent"]->Value->ToString() + " " + rows[i]->Cells["NameStudent"]->Value->ToString();
            if (domainUpDownPupil->Text != Pupil)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownSubjects->Text != "Все") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Subject = rows[i]->Cells["Subject"]->Value->ToString();
            if (domainUpDownSubjects->Text != Subject)
                rows[i]->Visible = false;
        }
    }

    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::domainUpDownPupil_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    domainUpDown_SelectedItemChanged();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::domainUpDownSubjects_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    domainUpDown_SelectedItemChanged();
    return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::domainUpDown_SelectedItemChanged()
{
    if (dataGridViewMarks->SelectedRows->Count == 1)
        return;

    String^ Pupil;
    String^ NumberClass;
    String^ Subject;

    auto rows = dataGridViewMarks->Rows;
    int selectedIndex = domainUpDownSubjects->SelectedIndex;

    for (int i = 0; i < rows->Count - 1; i++)
        rows[i]->Visible = true;

    if (domainUpDownPupil->Text != "Все") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Pupil = rows[i]->Cells["SurnameStudent"]->Value->ToString() + " " + rows[i]->Cells["NameStudent"]->Value->ToString();
            if (domainUpDownPupil->Text != Pupil)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "Все")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            NumberClass = rows[i]->Cells["NumberClass"]->Value->ToString();
            if (domainUpDownClasses->Text != NumberClass)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownSubjects->Text != "Все") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Subject = rows[i]->Cells["Subject"]->Value->ToString();
            if (domainUpDownSubjects->Text != Subject)
                rows[i]->Visible = false;
        }
    }

    return System::Void();
}
