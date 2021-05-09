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

/*-------------------------------������ �������� ������� ��������----------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (domainUpDownClasses->SelectedIndex == 0)
    {
        MessageBox::Show("�� �� ����� �����!", "��������!");
        return;
    }

    if (domainUpDownPupil->SelectedIndex == 0)
    {
        MessageBox::Show("�� �� ������� �������!", "��������!");
        return;
    }

    if (domainUpDownSubjects->SelectedIndex == 0)
    {
        MessageBox::Show("�� �� ������� �������!", "��������!");
        return;
    }

    int Mark;    
    auto isNum = Int32::TryParse(textBoxMark->Text, Mark);

    if (!isNum) {
        MessageBox::Show("������ ������ ���� ������!", "��������!");
        return;
    }

    if (Mark < 0 || Mark > 10)
    {
        MessageBox::Show("������ ������ ���� � ��������� �� 0 �� 10!", "��������!");
        return;
    }

    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";
    String^ Pupil = "'" + domainUpDownPupil->Text + "'";
    String^ Subject = "'" + domainUpDownSubjects->Text + "'";

    String^ id_pupil;
    String^ id_class_teahcer;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    /*�������� id �������*/
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;
    String^ SELECT = "id_pupil";
    String^ FROM = "Pupil";
    String^ WHERE = 
        "surname_pupil & ' ' & name_pupil LIKE " + Pupil + 
        " AND id_class IN (SELECT id_class FROM Class WHERE number_class LIKE " + NumberClass + ")";

    id_pupil = SelectID(dbConnection, SELECT, FROM, WHERE);

    /*������� id_class_teacher �� �������� ������ � �������� 
    � ������ ���� ��� � ������ ����� ���� 
    ������� ����� ����� ������ ���� �������������*/
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
        MessageBox::Show("� ������� ��� ����� ������!","��������!");
        return;
    }

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("������ ���������� �������!", "��������!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("������ ������� ���������!");

    QuarterMarks_Load(nullptr, nullptr);
    //��������� ����������
    dbConnection->Close();

	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }

    int Mark;
    auto isNum = Int32::TryParse(textBoxMark->Text, Mark);

    if (!isNum) {
        MessageBox::Show("������ ������ ���� ������!", "��������!");
        return;
    }

    if (Mark < 0 || Mark > 10)
    {
        MessageBox::Show("������ ������ ���� � ��������� �� 0 �� 10!", "��������!");
        return;
    }

    String^ id_mark = textBoxID->Text;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    /*�������� id �������*/
    String^ TABLE = "Mark";
    String^ SET = "mark = "+ Mark;
    String^ WHERE = "id_mark = " + id_mark;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
    {
        MessageBox::Show("������ ���������� �������!", "��������!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("������ ������� ����������!");

    QuarterMarks_Load(nullptr, nullptr);
    //��������� ����������
    dbConnection->Close();
	return System::Void();
}

System::Void schoolcourseProject::QuarterMarks::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }

    String^ id_mark = textBoxID->Text;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    /*�������� id �������*/
    String^ FROM = "Mark";
    String^ WHERE = "id_mark = " + id_mark;

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("������ �������� ������!", "��������!");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("������ ������� �������!");

    QuarterMarks_Load(nullptr, nullptr);
    //��������� ����������
    dbConnection->Close();
	return System::Void();
}

/*-------------------------------������� ���������� ���������� �����----------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::QuarterMarks_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewMarks->Rows->Clear();

    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "id_mark, number_class, surname_pupil, name_pupil, name_subject, mark";
    String^ FROM =
        "(((Pupil " +
        "INNER JOIN Class ON Pupil.id_class = Class.id_Class) " +
        "INNER JOIN Mark ON Pupil.id_pupil = Mark.id_pupil) " +
        "INNER JOIN Class_to_teacher ON Mark.id_class_teacher = Class_to_teacher.id_class_teacher) " +
        "INNER JOIN Subject ON Class_to_teacher.id_subject = Subject.id_subject";
    String^ ORDER_BY = "number_class,surname_pupil, name_pupil";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewMarks->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]);//������ ������ � �������
    }

    //��������� ����������
    dbReader->Close();

    if (domainUpDownClasses->Items->Count == 1)
    {
        SELECT = "number_class";
        FROM = "Class";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownClasses->Items->Add(dbReader[0]);//���������� ������ �� �� �
        domainUpDownClasses->SelectedIndex = 0;

        dbReader->Close();
    }

    if (domainUpDownSubjects->Items->Count == 1)
    {
        //������ �� ������� ���� ��������
        SELECT = "name_subject";
        FROM = "Subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());
        domainUpDownSubjects->SelectedIndex = 0;
        //��������� ����������
        dbReader->Close();
    }

    if (domainUpDownPupil->Items->Count == 1)
    {
        //������ �� ������� ���� ��������
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());
        domainUpDownPupil->SelectedIndex = 0;
        //��������� ����������
        dbReader->Close();
    }

    //��������� ����������
    dbConnection->Close();
}

System::Void schoolcourseProject::QuarterMarks::FillingTextBoxQuarterMarks(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count != 1)
        return;

    int index = dataGridViewMarks->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewMarks->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBoxQuarterMarks(); //������� ����� �����
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

/*-------------------------------------------������� ���������� �� ������� ���������----------------------------------------------------*/

System::Void schoolcourseProject::QuarterMarks::domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewMarks->SelectedRows->Count == 1)
        return;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

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

    if (domainUpDownClasses->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            NumberClass = rows[i]->Cells["NumberClass"]->Value->ToString();
            if (domainUpDownClasses->Text != NumberClass)
                rows[i]->Visible = false;
        }

        domainUpDownPupil->Items->Clear();
        domainUpDownPupil->Items->Add("���");
        //������ �� ������� ���� ��������
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";
        WHERE = "id_class IN (SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "')";

        auto dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());
       
        domainUpDownPupil->SelectedIndex = 0;
        //��������� ����������
        dbReader->Close();

        domainUpDownSubjects->Items->Clear();
        domainUpDownSubjects->Items->Add("���");

        SELECT = "name_subject";
        FROM = "Subject";
        WHERE = "id_subject IN(SELECT id_subject FROM Class_to_teacher WHERE id_class IN(SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "'))";
        
        dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());

        domainUpDownSubjects->SelectedIndex = 0;
        //��������� ����������
        dbReader->Close();
    }
    else {
        //������ �� ������� ���� ��������
        SELECT = "surname_pupil & ' ' & name_pupil";
        FROM = "Pupil";

        auto dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownPupil->Items->Add(dbReader[0]->ToString());

        //��������� ����������
        dbReader->Close();

        SELECT = "name_subject";
        FROM = "Subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());
        domainUpDownSubjects->SelectedIndex = 0;
        //��������� ����������
        dbReader->Close();
    }

    //��������� ����������
    dbConnection->Close();

    if (domainUpDownPupil->Text != "���") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Pupil = rows[i]->Cells["SurnameStudent"]->Value->ToString() + " " + rows[i]->Cells["NameStudent"]->Value->ToString();
            if (domainUpDownPupil->Text != Pupil)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownSubjects->Text != "���") {
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

    if (domainUpDownPupil->Text != "���") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Pupil = rows[i]->Cells["SurnameStudent"]->Value->ToString() + " " + rows[i]->Cells["NameStudent"]->Value->ToString();
            if (domainUpDownPupil->Text != Pupil)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            NumberClass = rows[i]->Cells["NumberClass"]->Value->ToString();
            if (domainUpDownClasses->Text != NumberClass)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownSubjects->Text != "���") {
        for (int i = 0; i < rows->Count - 1; i++) {
            Subject = rows[i]->Cells["Subject"]->Value->ToString();
            if (domainUpDownSubjects->Text != Subject)
                rows[i]->Visible = false;
        }
    }

    return System::Void();
}
