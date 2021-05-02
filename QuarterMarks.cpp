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
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
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

    String^ SELECT = "Pupil.id_pupil, number_class, surname_pupil, name_pupil, name_subject, mark";
    String^ FROM =
        "(((Pupil "+
        "INNER JOIN Class ON Pupil.id_class = Class.id_class) "+
        "INNER JOIN Mark ON Mark.id_pupil = Pupil.id_pupil) "+
        "INNER JOIN Class_to_teacher ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher) "+
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
        dataGridViewMarks->Rows[index]->Cells[2]->Value->ToString() + 
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

