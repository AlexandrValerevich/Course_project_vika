#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"

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

System::Void schoolcourseProject::QuarterMarks::FillingTextBoxQuarterMarks(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::ClearTextBoxQuarterMarks()
{
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::QuarterMarks_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
