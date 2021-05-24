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

/*-------------------------------������ ������������ ����� ������� � ������ ������----------------------------------------*/

System::Void schoolcourseProject::Pupils::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();

    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------������ �������� ������� ��������----------------------------------------*/

System::Void schoolcourseProject::Pupils::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{

    //���������, ����� ���������� �� ���� �������
    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length))
    {
        MessageBox::Show("�� �� ����� ��� ������!", "��������!");
        return;
    }

    //���������, ����� ��� ������ ���������� �����
    if (domainUpDownClasses->Text == "���")
    {
        MessageBox::Show("�� �� ������� ���������� �����!", "��������!");
        return;
    }

    String^ id_class;
    String^ Name = "'" + textBoxName->Text + "'";
    String^ Surname = "'" + textBoxSurname->Text + "'";
    String^ Patronymic = "'" + textBoxPatronymic->Text + "'";
    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";

    int CountRow = dataGridViewPupils->Rows->Count - 1;
    auto Rows = dataGridViewPupils->Rows;

    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["NamePupil"]->Value->ToString() == textBoxName->Text)
            if (Rows[i]->Cells["SurnamePupil"]->Value->ToString() == textBoxSurname->Text)
                if (Rows[i]->Cells["PatronymicPupil"]->Value->ToString() == textBoxPatronymic->Text)
                    if (Rows[i]->Cells["ClassPupil"]->Value->ToString() == domainUpDownClasses->Text)
                    {
                        MessageBox::Show("����� ������ ��� ����!", "��������!");
                        return;
                    }

    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;
    String^ SELECT = "id_class";
    String^ FROM = "Class";
    String^ WHERE = "number_class LIKE " + NumberClass ;

    id_class = SelectID(dbConnection, SELECT, FROM, WHERE);

    //��������� ������� ������, ���� ��� ���,�� ���������
    if (String::IsNullOrEmpty(id_class))
    {
        TABLE = "Class";
        COLUMN= "number_class";
        VALUES = NumberClass;
       
        if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        {
            MessageBox::Show("������ ���������� ������!", "��������!");
            dbConnection->Close();
            return;
        }

        id_class = SelectID(dbConnection, SELECT, FROM, WHERE);
    }
   
    TABLE = "Pupil";
    COLUMN = "surname_pupil, name_pupil, patronymic_pupil, id_class";
    VALUES = Surname + "," + Name + "," + Patronymic + "," + id_class;

    
    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("������ ��� ���������� �������!", "��������!");
        dbConnection->Close();
        return;
    }
    else
        MessageBox::Show("������ ������� ���������", "��������!");
   
    dbConnection->Close();

    //��������� ������� � ����������� �������
    Pupils_Load(nullptr, nullptr);
    
    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    //���������, ����� ���������� �� ���� �������
    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length))
    {
        MessageBox::Show("�� �� ����� ��� ������!", "��������!");
        return;
    }

    //���������, ����� ��� ������ ���������� �����
    if (domainUpDownClasses->Text == "���")
    {
        MessageBox::Show("�� �� ������� ���������� �����!", "��������!");
        return;
    }

    String^ id_class;
    String^ id_pupil = textBoxID->Text;
    String^ Name = "'" + textBoxName->Text + "'";
    String^ Surname = "'" + textBoxSurname->Text + "'";
    String^ Patronymic = "'" + textBoxPatronymic->Text + "'";
    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";

    int CountRow = dataGridViewPupils->Rows->Count - 1;
    auto Rows = dataGridViewPupils->Rows;

    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["NamePupil"]->Value->ToString() == textBoxName->Text)
            if (Rows[i]->Cells["SurnamePupil"]->Value->ToString() == textBoxSurname->Text)
                if (Rows[i]->Cells["PatronymicPupil"]->Value->ToString() == textBoxPatronymic->Text)
                    if (Rows[i]->Cells["ClassPupil"]->Value->ToString() == domainUpDownClasses->Text)
                    {
                        MessageBox::Show("����� ������ ��� ����!", "��������!");
                        return;
                    }

    //����������� � ��
    String^ connectionString = StringConnection();; //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;
    String^ SET;
    String^ SELECT = "id_class";
    String^ FROM = "Class";
    String^ WHERE = "number_class LIKE " + NumberClass;

    id_class = SelectID(dbConnection, SELECT, FROM, WHERE);

    //��������� ������� ������, ���� ��� ���,�� ���������
    if (String::IsNullOrEmpty(id_class))
    {
        TABLE = "Class";
        COLUMN = "number_class";
        VALUES = NumberClass;

        if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        {
            MessageBox::Show("������ ���������� ������!", "��������!");
            dbConnection->Close();
            return;
        }

        id_class = SelectID(dbConnection, SELECT, FROM, WHERE);
    }

    TABLE = "Pupil";
    SET = 
        "surname_pupil = " + Surname + 
        ", name_pupil = " + Name +
        ", patronymic_pupil = " + Patronymic +
        ", id_class =" + id_class;
    WHERE = "id_pupil = " + id_pupil;

    if (!UpdateRow(dbConnection,TABLE, SET, WHERE))
    {
        MessageBox::Show("������ ��� ���������� ���������� �� �������!", "��������!");
        dbConnection->Close();
        return;
    }

    dbConnection->Close();
    MessageBox::Show("������ ������� ��������", "��������!");

    //��������� ������� � ����������� �������
    Pupils_Load(nullptr, nullptr);

    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    //��������� ������� �� ������ ��� ��������
    if (dataGridViewPupils->SelectedRows->Count != 1)
    {
        MessageBox::Show("�������� ������ ��� ��������", "��������!");
        return;
    }

    String^ id_pupil = textBoxID->Text;

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ FROM = "Pupil";
    String^ WHERE = "id_pupil = " + id_pupil;

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("������ �������� ���������� �� �������");
        dbConnection->Close();
        return;
    }
    MessageBox::Show("������ ������� �������", "��������!");

    //��������� ������ � �������
    Pupils_Load(nullptr, nullptr);

    dbConnection->Close();
    return System::Void();
}

/*-------------------------------������� ���������� ���������� �����----------------------------------------*/

/*�������� �����*/
System::Void schoolcourseProject::Pupils::Pupils_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewPupils->Rows->Clear();
    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "number_class";
    String^ FROM = "Class";
    String^ ORDER_BY = "number_class";

    OleDbDataReader^ dbReader;

    if (domainUpDownClasses->Items->Count == 1) {

        //��������� ������ 
        dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY);

        if (!dbReader->HasRows)
        {
            MessageBox::Show("������ ������!", "��������!");
            dbConnection->Close();//��������� ����������
            return;
        }

        while (dbReader->Read())
        {
            domainUpDownClasses->Items->Add(dbReader[0]);//���������� ������ �� �� �
        }

        domainUpDownClasses->Text = domainUpDownClasses->Items[0]->ToString(); //������� �� ���������

        //���������� ������ ����������
        dbReader->Close();
    }

    SELECT = "id_pupil, surname_pupil, name_pupil, patronymic_pupil, number_class";
    FROM = "Pupil INNER JOIN Class ON Pupil.id_class=Class.id_class";
    ORDER_BY = "number_class, surname_pupil, name_pupil, patronymic_pupil";

    dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewPupils->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4]);//������ ������ � �������
    }

    //��������� ����������
    dbReader->Close();
    dbConnection->Close(); 
    
    return System::Void();
}
/*���������� ���������*/
System::Void schoolcourseProject::Pupils::FillngTextBoxPupils(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //��������� ��������� ������
    if (dataGridViewPupils->SelectedRows->Count == 0)
        return;
    
    int index = dataGridViewPupils->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewPupils->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBoxPupils(); //������� ����� �����
        return;
    }

    //���������� �����������
    textBoxID->Text = dataGridViewPupils->Rows[index]->Cells[0]->Value->ToString();
    textBoxSurname->Text = dataGridViewPupils->Rows[index]->Cells[1]->Value->ToString();
    textBoxName->Text = dataGridViewPupils->Rows[index]->Cells[2]->Value->ToString();
    textBoxPatronymic->Text = dataGridViewPupils->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownClasses->Text=dataGridViewPupils->Rows[index]->Cells[4]->Value->ToString();

    return System::Void();
}
/*������� �����������*/
System::Void schoolcourseProject::Pupils::ClearTextBoxPupils()
{
    textBoxID->Text = "";
    textBoxSurname->Text = "";
    textBoxName->Text = "";
    textBoxPatronymic->Text = "";
    return System::Void();
}
/*������� �� ������*/
System::Void schoolcourseProject::Pupils::domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (domainUpDownClasses->SelectedIndex == -1)
        return;
    if (dataGridViewPupils->SelectedRows->Count == 1)
        return;

    String^ NameClass = domainUpDownClasses->SelectedItem->ToString();

    int CountRow = dataGridViewPupils->Rows->Count - 1;
    auto Rows = dataGridViewPupils->Rows;

    for (int i = 0; i < CountRow; i++) 
        Rows[i]->Visible = true;


    if (domainUpDownClasses->Text == "���")
        return;

    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["ClassPupil"]->Value->ToString() != NameClass)
            Rows[i]->Visible = false;

    return System::Void();
}

System::Void schoolcourseProject::Pupils::buttonAbout_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormAbout^ form = gcnew MyFormAbout(this);
    form->Show();
    return System::Void();
}
