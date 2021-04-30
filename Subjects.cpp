#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"
#include "dbQuery.h"

/*-------------------------------������ ������������ ����� ������� � ������ ������----------------------------------------*/

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

/*-------------------------------������ �������� ������� ��������----------------------------------------*/

System::Void schoolcourseProject::Subjects::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    //���������, ����� ��������� �� ��� ������
    if (!textBoxSubject->Text->Length )
    {
        MessageBox::Show("�� �� ����� ��� ������!", "��������!");
        return;
    }

    String^ NameSubject = "'" + textBoxSubject->Text + "'";

    int CountRow = dataGridViewSubjects->Rows->Count - 1;
    auto Rows = dataGridViewSubjects->Rows;

    for (int i = 0; i < CountRow;i++)
        if (Rows[i]->Cells["NameSubject"]->Value->ToString() == textBoxSubject->Text)
        {
            MessageBox::Show("������ ������� ��� ����!","��������!");
            return;
        }
       
    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "Subject";
    String^ COLUMN = "name_subject";
    String^ VALUES = NameSubject;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("������ ���������� ��������!", "��������!");
        dbConnection->Close();
        return;
    }

    dbConnection->Close();

    MessageBox::Show("������ ������� ���������!", "��������!");

    Subjects_Load(nullptr, nullptr);
	return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    //���������, ����� ���������� �� ���� �������
    if (!textBoxSubject->Text->Length)
    {
        MessageBox::Show("�� �� ����� ��� ������!", "��������!");
        return;
    }

    String^ id_subject = textBoxID->Text;
    String^ NameSubject = "'" + textBoxSubject->Text + "'";

    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "Subject";
    String^ SET = "name_sublect = " + NameSubject;
    String^ WHERE = "id_subject = " + id_subject;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE)){
        MessageBox::Show("������ ��������� ��������!", "��������!");
        dbConnection->Close();
        return;
    }

    dbConnection->Close();

    MessageBox::Show("������ ������� ��������!", "��������!");

    Subjects_Load(nullptr, nullptr);

	return System::Void();
}

System::Void schoolcourseProject::Subjects::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    //��������� ������� �� ������ ��� ��������
    if (dataGridViewSubjects->SelectedRows->Count != 1)
    {
        MessageBox::Show("�������� ������ ��� ��������", "��������!");
        return;
    }

    String^ id_subject = textBoxID->Text;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ FROM = "Subject";
    String^ WHERE = "id_subject = " + id_subject;

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("������ �������� ���������� �� �������");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("������ ������� �������", "��������!");

    //��������� ������ � �������
    Subjects_Load(nullptr, nullptr);

    dbConnection->Close();
	return System::Void();
}

/*-------------------------------������� ���������� ���������� �����----------------------------------------*/

System::Void schoolcourseProject::Subjects::Subjects_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSubjects->Rows->Clear();
    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "id_subject, name_subject";
    String^ FROM = "Subject";
    String^ ORDER_BY = "name_subject";

    //��������� ������ 
    auto dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY);

    while (dbReader->Read())
    {
        dataGridViewSubjects->Rows->Add(dbReader[0], dbReader[1]);//������ ������ � �������
    }

    //��������� ����������
    dbReader->Close();
    dbConnection->Close();

	return System::Void();
}

System::Void schoolcourseProject::Subjects::FillingTextBoxSubjects(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //��������� ��������� ������
    if (dataGridViewSubjects->SelectedRows->Count == 0)
    {
        return;
    }

    int index = dataGridViewSubjects->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewSubjects->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBoxSubjects(); //������� ����� �����
        return;
    }

    //���������� �����������
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

