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

System::Void schoolcourseProject::ProgressClasses::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::ProgressClasses::ProgressClasses_Load(System::Object^ sender, System::EventArgs^ e)
{ //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    /*Запрос на выборку среднего бала предметов*/
    /*SELECT 
      Class.id_class, 
      number_class, 
      AVG(mark) AS avg_mark 
    FROM 
      (
        Class 
        INNER JOIN Class_to_teacher ON Class.id_class = Class_to_teacher.id_class
      ) 
      INNER JOIN Mark ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher 
    GROUP BY 
      Class.id_class, 
      number_class

    */

    String^ SELECT =
        "Class.id_class, "+
        "number_class, "+
        "AVG(mark) ";
    String^ FROM =
        "(Class "+
            "INNER JOIN Class_to_teacher ON Class.id_class = Class_to_teacher.id_class) "+
            "INNER JOIN Mark ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher";
    String^ GROUP_BY =
        "Class.id_class, "+
        "number_class";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewAll->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::ProgressClasses::domainUpDownSubjects_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

/*--------------------------------СОБЫТИЯ ОТВЕЧАЮЩИЕ ЗА ВЫБОРКУ ЭЛЕМЕНТОВ----------------------------------------------------*/

