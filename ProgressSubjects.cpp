#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"
#include "dbQuery.h"

/*-------------------------------ÊÍÎÏÊÈ ÏÅÐÅÊËÞ×ÅÍÈß ÌÅÆÄÓ ÔÎÐÌÀÌÈ È ÊÍÎÏÊÀ ÂÛÕÎÄÀ----------------------------------------*/

System::Void schoolcourseProject::ProgressSubjects::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::ProgressSubjects::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------ÑÎÁÛÒÈß ÓÏÐÀÂËÅÍÈß ÏÎÂÅÄÅÍÈÅÌ ÔÎÐÌÛ----------------------------------------*/

System::Void schoolcourseProject::ProgressSubjects::ProgressSubjects_Load(System::Object^ sender, System::EventArgs^ e)
{
    //ïîäêëþ÷åíèå ê ÁÄ
    String^ connectionString = StringConnection(); //ñòðîêà ïîäêëþ÷åíèÿ
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//îòêðûâàåì ñîåäèíåíèå

    /*Çàïðîñ íà âûáîðêó ñðåäíåãî áàëà ïðåäìåòîâ*/
    /*
SELECT
    Subject.id_subject,
    name_subject,
    AVG(mark)
FROM
    (Subject INNER JOIN Class_to_teacher ON Subject.id_subject = Class_to_teacher.id_subject)
    INNER JOIN Mark ON Mark.id_class_teacher = Class_to_teacher.id_class_teacher
GROUP BY 
    Subject.id_subject,
    name_subject
    */

    String^ SELECT =
        "Subject.id_subject, " +
        "name_subject, " +
        "AVG(mark) ";
    String^ FROM =
        "(Subject INNER JOIN Class_to_teacher ON Subject.id_subject = Class_to_teacher.id_subject) " +
        "INNER JOIN Mark ON Mark.id_class_teacher = Class_to_teacher.id_class_teacher";
    String^ GROUP_BY =
        "Subject.id_subject, " +
        "name_subject";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //âûçîâ ïðåäûäóùåé êîìàíäû

    while (dbReader->Read())
    {
        dataGridViewAll->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//âíîñèì ñòðîêè â òàáëèöó
    }
    //çàêðûâàåì ñîåäèíåíèÿ
    dbReader->Close();

    dbConnection->Close();
    return System::Void();
}
