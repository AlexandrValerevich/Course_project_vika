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

System::Void schoolcourseProject::ProgressPupils::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::ProgressPupils::ProgressPupils_Load(System::Object^ sender, System::EventArgs^ e)
{

    //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    /*Запрос на выборку среднего бала учеников*/
    /*SELECT 
      Pupil.id_pupil, 
      number_class, 
      surname_pupil, 
      name_pupil, 
      patronymic_pupil, 
      AVG(mark) 
    FROM 
      (
        Pupil 
        INNER JOIN Class ON Pupil.id_class = Class.id_class
      ) 
      INNER JOIN Mark ON Pupil.id_pupil = Mark.id_pupil 
    GROUP BY 
      Pupil.id_pupil, 
      number_class, 
      surname_pupil, 
      name_pupil, 
      patronymic_pupil
    */

    String^ SELECT = 
        "Pupil.id_pupil, "+
        "number_class, "+
        "surname_pupil, "+
        "name_pupil, "+ 
        "patronymic_pupil, "+
        "AVG(mark) "; 
    String^ FROM =
        "( "+
        "Pupil "+
        "INNER JOIN Class ON Pupil.id_class = Class.id_class "+
      ") "+ 
      "INNER JOIN Mark ON Pupil.id_pupil = Mark.id_pupil ";
    String^ GROUP_BY = 
        "Pupil.id_pupil, " +
        "number_class, " +
        "surname_pupil, " +
        "name_pupil, " +
        "patronymic_pupil";
    String^ HAVING;

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewAll->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();

    HAVING = "AVG(mark)>8";
    dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY, HAVING); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewHighPupil->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();

    HAVING = "AVG(mark)<4";
    dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY, HAVING); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewLowPupil->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();

    SELECT = "number_class";
    FROM = "Class";

    dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        domainUpDownAll->Items->Add(dbReader[0]);
        domainUpDownHighPupil->Items->Add(dbReader[0]);
        domainUpDownLowPupil->Items->Add(dbReader[0]);
    }

    dbConnection->Close();
	return System::Void();
}

/*--------------------------------СОБЫТИЯ ОТВЕЧАЮЩИЕ ЗА ВЫБОРКУ ЭЛЕМЕНТОВ----------------------------------------------------*/

System::Void schoolcourseProject::ProgressPupils::domainUpDownHighPupil_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    auto rows = dataGridViewHighPupil->Rows;
    int countRows = rows->Count - 1;

    for (int i = 0; i < countRows; i++)
        rows[i]->Visible = true;


    if (domainUpDownHighPupil->Text != "Все")
        for (int i = 0; i < countRows; i++)
            if(rows[i]->Cells[1]->Value->ToString() != domainUpDownHighPupil->Text)
                rows[i]->Visible = false;

    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::domainUpDownLowPupil_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    auto rows = dataGridViewLowPupil->Rows;
    int countRows = rows->Count - 1;

    for (int i = 0; i < countRows; i++)
        rows[i]->Visible = true;


    if (domainUpDownLowPupil->Text != "Все")
        for (int i = 0; i < countRows; i++)
            if (rows[i]->Cells[1]->Value->ToString() != domainUpDownLowPupil->Text)
                rows[i]->Visible = false;

    return System::Void();
}

System::Void schoolcourseProject::ProgressPupils::domainUpDownAll_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    auto rows = dataGridViewAll->Rows;
    int countRows = rows->Count - 1;

    for (int i = 0; i < countRows; i++)
        rows[i]->Visible = true;


    if (domainUpDownAll->Text != "Все")
        for (int i = 0; i < countRows; i++)
            if (rows[i]->Cells[1]->Value->ToString() != domainUpDownAll->Text)
                rows[i]->Visible = false;
    return System::Void();
}