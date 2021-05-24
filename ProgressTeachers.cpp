#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"
#include "dbQuery.h"
#include "About.h"


/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::ProgressTeachers::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------СОБЫТИЯ УПРАВЛЕНИЯ ПОВЕДЕНИЕМ ФОРМЫ----------------------------------------*/

System::Void schoolcourseProject::ProgressTeachers::ProgressTeachers_Load(System::Object^ sender, System::EventArgs^ e)
{
     //подключение к БД
    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "Teacher.id_teacher, surname_teacher, name_teacher, patronymic_teacher, name_subject, AVG(mark)";
    String^ FROM =
        "((Teacher " +
        "INNER JOIN Class_to_teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher) " +
        "INNER JOIN Subject ON Class_to_teacher.id_subject = Subject.id_subject) " +
        "INNER JOIN Mark ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher";
    String^ GROUP_BY = "Teacher.id_teacher, surname_teacher, name_teacher, patronymic_teacher, name_subject";
    String^ WHERE;

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


    //Закрыываем соединение

    /*Запрос на выборку учителся с лучшей успеваемостью*/
    /*SELECT 
  id_teacher, 
  surname_teacher, 
  name_teacher, 
  patronymic_teacher, 
  name_subject, 
  avg_mark 
FROM 
  (
    SELECT 
      Teacher.id_teacher AS id_teacher, 
      surname_teacher, 
      name_teacher, 
      patronymic_teacher, 
      name_subject, 
      AVG(mark) AS avg_mark 
    FROM 
      (
        (
          Teacher 
          INNER JOIN Class_to_teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher
        ) 
        INNER JOIN Subject ON Class_to_teacher.id_subject = Subject.id_subject
      ) 
      INNER JOIN Mark ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher 
    GROUP BY 
      Teacher.id_teacher, 
      surname_teacher, 
      name_teacher, 
      patronymic_teacher, 
      name_subject
  ) 
WHERE 
  avg_mark IN(
    SELECT 
      MAX(avg_mark) 
    FROM 
      (
        SELECT 
          AVG(mark) AS avg_mark
        FROM 
          Mark 
        GROUP BY 
          id_class_teacher
      ) AS qmax
  )
*/
    SELECT = " id_teacher, " +
        "surname_teacher, " +
        "name_teacher, "+
        "patronymic_teacher, "+
        "name_subject, "+
        "avg_mark ";
    FROM = "( "+
        "SELECT "+
        "Teacher.id_teacher AS id_teacher, "+
        "surname_teacher, "+
        "name_teacher, "+
        "patronymic_teacher, "+
        "name_subject, "+
        "AVG(mark) AS avg_mark "+
        "FROM "+
        "( "+
            "( "+
                "Teacher "+
                "INNER JOIN Class_to_teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher "+
                ") "+
            "INNER JOIN Subject ON Class_to_teacher.id_subject = Subject.id_subject "+
        ") "+
        "INNER JOIN Mark ON Class_to_teacher.id_class_teacher = Mark.id_class_teacher "+
        "GROUP BY " 
        "Teacher.id_teacher, "
        "surname_teacher, "+
        "name_teacher, "+
        "patronymic_teacher, "+
        "name_subject "+
        ") ";
    WHERE = "avg_mark IN( "+
        "SELECT "+
        "MAX(avg_mark) "+
        "FROM "+
        "( "+
            "SELECT "+
            "AVG(mark) AS avg_mark "+
            "FROM "+
            "Mark "+
            "GROUP BY "+
            "id_class_teacher "+
        ") AS qmax "+
    ") ";

    dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewHigh->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();


    WHERE = "avg_mark IN( "+
        "SELECT "+
        "MIN(avg_mark) "+
        "FROM "+
        "( "+
            "SELECT "+
            "AVG(mark) AS avg_mark "+
            "FROM "+
            "Mark "+
            "GROUP BY "+
            "id_class_teacher "+
        ") AS qmin "+
    ") ";

    dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewLow->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//вносим строки в таблицу
    }
    //закрываем соединения
    dbReader->Close();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::ProgressTeachers::buttonAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormAbout^ form = gcnew MyFormAbout(this);
    form->Show();
    return System::Void();
}
