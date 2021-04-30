#include <Windows.h>
#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"

using namespace schoolcourseProject;
using namespace System::Data::OleDb;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew schoolcourseProject::Pupils());

}
