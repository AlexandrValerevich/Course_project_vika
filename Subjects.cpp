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

System::Void schoolcourseProject::Subjects::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------КНОПКИ ДОБАВИТЬ УДАЛИТЬ ИЗМЕНИТЬ----------------------------------------*/

System::Void schoolcourseProject::Subjects::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    //проверяем, чтобы текстбокс не был пустым
    if (!textBoxSubject->Text->Length )
    {
        MessageBox::Show("Вы не ввели все данные!", "Внимание!");
        return;
    }

    String^ NameSubject = "'" + textBoxSubject->Text + "'";

    int CountRow = dataGridViewSubjects->Rows->Count - 1;
    auto Rows = dataGridViewSubjects->Rows;

    for (int i = 0; i < CountRow;i++)
        if (Rows[i]->Cells["NameSubject"]->Value->ToString() == textBoxSubject->Text)
        {
            MessageBox::Show("Такаой предмет уже есть!","Внимание!");
            return;
        }
       
    //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "Subject";
    String^ COLUMN = "name_subject";
    String^ VALUES = NameSubject;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("Ошибка добавления предмета!", "Внимание!");
        dbConnection->Close();
        return;
    }

    dbConnection->Close();

    MessageBox::Show("Запись успешно добавлена!", "Внимание!");

    Subjects_Load(nullptr, nullptr);
	return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    //проверяем, чтобы текстбоксы не были пустыми
    if (!textBoxSubject->Text->Length)
    {
        MessageBox::Show("Вы не ввели все данные!", "Внимание!");
        return;
    }

    String^ id_subject = textBoxID->Text;
    String^ NameSubject = "'" + textBoxSubject->Text + "'";

    //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "Subject";
    String^ SET = "name_sublect = " + NameSubject;
    String^ WHERE = "id_subject = " + id_subject;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE)){
        MessageBox::Show("Ошибка изменения предмета!", "Внимание!");
        dbConnection->Close();
        return;
    }

    dbConnection->Close();

    MessageBox::Show("Запись успешно изменена!", "Внимание!");

    Subjects_Load(nullptr, nullptr);

	return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    //проверяем выбрана ли строка для удаления
    if (dataGridViewSubjects->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите строку для удаления", "Внимание!");
        return;
    }

    String^ id_subject = textBoxID->Text;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ FROM = "Subject";
    String^ WHERE = "id_subject = " + id_subject;

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("Ошибка удаления информации об ученике");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("Запись успешно удалена", "Внимание!");

    //обновляем записи в таблица
    Subjects_Load(nullptr, nullptr);

    dbConnection->Close();
	return System::Void();
}

/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::Subjects::Subjects_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSubjects->Rows->Clear();
    //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "id_subject, name_subject";
    String^ FROM = "Subject";
    String^ ORDER_BY = "name_subject";

    //считываем данные 
    auto dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY);

    while (dbReader->Read())
    {
        dataGridViewSubjects->Rows->Add(dbReader[0], dbReader[1]);//вносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();
    dbConnection->Close();

	return System::Void();
}

System::Void schoolcourseProject::Subjects::FillingTextBoxSubjects(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //проверяем выбранные строки
    if (dataGridViewSubjects->SelectedRows->Count == 0)
    {
        return;
    }

    int index = dataGridViewSubjects->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewSubjects->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBoxSubjects(); //очистка полей ввода
        return;
    }

    //заполнение текстбоксов
    textBoxID->Text = dataGridViewSubjects->Rows[index]->Cells[0]->Value->ToString();
    textBoxSubject->Text = dataGridViewSubjects->Rows[index]->Cells[1]->Value->ToString();

	return System::Void();
}

System::Void schoolcourseProject::Subjects::ClearTextBoxSubjects()
{
    textBoxID->Text = "";
    textBoxSubject->Text = "";

	return System::Void();
}

