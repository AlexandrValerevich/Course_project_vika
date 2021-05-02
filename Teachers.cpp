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

System::Void schoolcourseProject::Teachers::buttonPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pupils^ form = gcnew Pupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    Subjects^ form = gcnew Subjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    Teachers^ form = gcnew Teachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonMarks_Click(System::Object^ sender, System::EventArgs^ e)
{
    QuarterMarks^ form = gcnew QuarterMarks();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgress_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressTeachers^ form = gcnew ProgressTeachers();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressPupils^ form = gcnew ProgressPupils();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressClasses^ form = gcnew ProgressClasses();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e)
{
    ProgressSubjects^ form = gcnew ProgressSubjects();
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------������ �������� ������� ��������----------------------------------------*/

System::Void schoolcourseProject::Teachers::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length) &&
        textBoxClassroom->Text->Length)
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

    //���������, ����� ��� ������ ���������� �������
    if (domainUpDownSubjects->Text == "���")
    {
        MessageBox::Show("�� �� ������� ���������� �������!", "��������!");
        return;
    }

    String^ id_teacher;
    String^ id_class;
    String^ id_subject;
    String^ id_class_teacher;
    String^ Name = "'" + textBoxName->Text + "'";
    String^ Surname = "'" + textBoxSurname->Text + "'";
    String^ Patronymic = "'" + textBoxPatronymic->Text + "'";
    String^ Classroom = textBoxClassroom->Text;
    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";
    String^ Subject = "'" + domainUpDownSubjects->Text+ "'";

    int CountRow = dataGridViewTeachers->Rows->Count - 1;
    auto Rows = dataGridViewTeachers->Rows;

    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["Class"]->Value->ToString() == domainUpDownClasses->Text)
            if (Rows[i]->Cells["Subject"]->Value->ToString() == domainUpDownSubjects->Text)
            {
                MessageBox::Show("� ����� ������ ��� ���� �������\n�� ����� ��������","��������!");
                return;
            }

    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["NameTeacher"]->Value->ToString() == textBoxName->Text)
            if (Rows[i]->Cells["SurnameTeacher"]->Value->ToString() == textBoxSurname->Text)
                if (Rows[i]->Cells["PatronymicTeacher"]->Value->ToString() == textBoxPatronymic->Text)
                    if (Rows[i]->Cells["Classroom"]->Value->ToString() == textBoxClassroom->Text)
                        if (Rows[i]->Cells["Class"]->Value->ToString() == domainUpDownClasses->Text)
                            if (Rows[i]->Cells["Subject"]->Value->ToString() == domainUpDownSubjects->Text)
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
    String^ SELECT = "id_teacher";
    String^ FROM = "Teacher";
    String^ WHERE = "name_teacher LIKE " + Name + " AND surname_teacher LIKE " + Surname + " AND patronymic_teacher LIKE " + Patronymic;

    id_teacher = SelectID(dbConnection, SELECT, FROM, WHERE);

    //��������� ���� �� ����� �������
    if (String::IsNullOrEmpty(id_teacher)) {
        //���� ��� �� ���������

        TABLE = "Teacher";
        COLUMN = "name_teacher, surname_teacher, patronymic_teacher, classroom";
        VALUES = Name + ", " + Surname + ", " + Patronymic + ", " + Classroom;

        if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        {
            MessageBox::Show("������ ���������� �������!", "��������!");
            dbConnection->Close();
            return;
        }

        id_teacher = SelectID(dbConnection, SELECT, FROM, WHERE);
    }
       
    SELECT = "id_class";
    FROM = "Class";
    WHERE = "number_class LIKE " + NumberClass;

    id_class = SelectID(dbConnection, SELECT, FROM, WHERE);
    
    //������ ������� �� �������

    SELECT = "id_subject";
    FROM = "Subject";
    WHERE = "name_subject LIKE " + Subject;

    id_subject = SelectID(dbConnection, SELECT, FROM, WHERE);

    //��������� ���� �� ����� ������ � Class_to_teacher
    
    TABLE = "Class_to_teacher";
    COLUMN = "id_class, id_teacher, id_subject";
    VALUES = id_class + ", " + id_teacher + ", " + id_subject;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
    {
        MessageBox::Show("������ ���������� ��������!", "��������!");
        dbConnection->Close();
        return;
    }

    MessageBox::Show("������ ������� ���������!");

    Teachers_Load(nullptr, nullptr); 

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewTeachers->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }

    if (!(textBoxSurname->Text->Length &&
        textBoxName->Text->Length &&
        textBoxPatronymic->Text->Length) &&
        textBoxClassroom->Text->Length)
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

    //���������, ����� ��� ������ ���������� �������
    if (domainUpDownSubjects->Text == "���")
    {
        MessageBox::Show("�� �� ������� ���������� �������!", "��������!");
        return;
    }

    //��������� ���� �� ��������� ������
    if (dataGridViewTeachers->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }
    int index = dataGridViewTeachers->SelectedRows[0]->Index;

    String^ id_teacher = textBoxID->Text->ToString();
    String^ id_classTB;
    String^ id_subjectTB;
    String^ id_classSG;
    String^ id_subjectSG;
    String^ id_class_teacher;
    String^ Name = "'" + textBoxName->Text + "'";
    String^ Surname = "'" + textBoxSurname->Text + "'";
    String^ Patronymic = "'" + textBoxPatronymic->Text + "'";
    String^ Classroom = textBoxClassroom->Text;
    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";
    String^ Subject = "'" + domainUpDownSubjects->Text + "'";

    int CountRow = dataGridViewTeachers->Rows->Count - 1;
    auto Rows = dataGridViewTeachers->Rows;

    /*��������� ���� �� ��� ����� ������*/
    for (int i = 0; i < CountRow; i++)
        if (Rows[i]->Cells["NameTeacher"]->Value->ToString() == textBoxName->Text)
            if (Rows[i]->Cells["SurnameTeacher"]->Value->ToString() == textBoxSurname->Text)
                if (Rows[i]->Cells["PatronymicTeacher"]->Value->ToString() == textBoxPatronymic->Text)
                    if (Rows[i]->Cells["Classroom"]->Value->ToString() == textBoxClassroom->Text)
                        if (Rows[i]->Cells["Class"]->Value->ToString() == domainUpDownClasses->Text)
                            if (Rows[i]->Cells["Subject"]->Value->ToString() == domainUpDownSubjects->Text)
                            {
                                MessageBox::Show("����� ������ ��� ����!", "��������!");
                                return;
                            }
    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������
    
    String^ TABLE = "Teacher";
    String^ SET =
        "name_teacher = " + Name +
        ", surname_teacher = " + Surname +
        ", patronymic_teacher = " + Patronymic +
        ", classroom = " + Classroom;
    String^ WHERE = "id_teacher = " + id_teacher;
    String^ SELECT;
    String^ FROM;

     //������ �� ���������� �������
    if (!UpdateRow(dbConnection, TABLE, SET, WHERE)) {
        MessageBox::Show("������ ��������� �������!", "��������!");
        dbConnection->Close();
        return;
    }

    if (String::IsNullOrEmpty(dataGridViewTeachers->Rows[index]->Cells["Class"]->Value->ToString()) ||
        String::IsNullOrEmpty(dataGridViewTeachers->Rows[index]->Cells["Subject"]->Value->ToString()))
    {
        buttonAdd_Click(nullptr, nullptr);
        return;
    }


    /*-----------------------------�� ������� ���������� ������ -----------------------------------*/

    //������ ��� ������ �� ������� ���������� ������ 
    
    SELECT = "id_class";
    FROM = "Class";
    WHERE = "number_class LIKE " + NumberClass;

    id_classTB = SelectID(dbConnection, SELECT, FROM, WHERE);
    
    //������ ������� �� ������� �� ������� ���������� ������
    
    SELECT = "id_subject";
    FROM = "Subject";
    WHERE = "name_subject LIKE " + Subject;

    id_subjectTB = SelectID(dbConnection, SELECT, FROM, WHERE);
    
  /*----------------------������� ������----------------------------*/

    SELECT = "id_class";
    FROM = "Class";
    WHERE = "number_class LIKE " + dataGridViewTeachers->Rows[index]->Cells["Class"]->Value->ToString();

    id_classSG = SelectID(dbConnection, SELECT, FROM, WHERE);


    //������ ������� �� ������� ������� ������
    
    SELECT = "id_subject";
    FROM = "Subject";
    WHERE = "name_subject LIKE " + dataGridViewTeachers->Rows[index]->Cells["Subject"]->Value->ToString();

    id_subjectSG = SelectID(dbConnection, SELECT, FROM, WHERE);


    /*-----------------------------------���� id ������ ������� ����� ��������-------------------------------------*/

    SELECT = "id_class_teacher";
    FROM = "Class_to_teacher";
    WHERE = 
        "id_teacher = " + id_teacher +
        " AND id_class = "+id_classSG +
        " AND id_subject = " + id_subjectSG;
    
    id_class_teacher = SelectID(dbConnection, SELECT, FROM, WHERE);;

    //��������� ������

    TABLE = "Class_to_teacher";
    SET = "id_class = " + id_classTB +
        ", id_subject = " + id_subjectTB;
    WHERE = "id_class_teacher = " + id_class_teacher;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE)) {
        MessageBox::Show("������ ��������� ��������!", "��������!");
        dbConnection->Close();
        return;
    }
    //��������� ����������
    dbConnection->Close();

    //��������� �������
    Teachers_Load(nullptr,nullptr);

    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    //��������� ������� �� ������ ��� ��������
    if (dataGridViewTeachers->SelectedRows->Count != 1)
    {
        MessageBox::Show("�������� ������ ��� ��������", "��������!");
        return;
    }

    String^ id_teacher  = textBoxID->Text->ToString();
    String^ NumberClass = "'" + domainUpDownClasses->Text + "'";
    String^ Subject     = "'" + domainUpDownSubjects->Text + "'";

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ FROM;
    String^ WHERE;
    /*�������� ���� �������� ������� �� ������� � ������������ ������� ��� ���������*/
    FROM = "Teacher";
    WHERE = "id_teacher NOT IN(SELECT id_teacher FROM Class_to_teacher) AND id_teacher = " + id_teacher;

    if (DeleteRow(dbConnection, FROM, WHERE)) {
        MessageBox::Show("������� ��������� ������ �� ��!");
        Teachers_Load(nullptr, nullptr);
        dbConnection->Close();
        return;
    }

    /*�������� �� Class_to_teacher*/
    FROM = "Class_to_teacher";
    WHERE = "id_teacher = " + id_teacher +
        ((NumberClass != "''")?" AND id_class IN (SELECT id_class FROM Class WHERE number_class LIKE " + NumberClass + ")":" AND id_class IS NULL") +
        ((Subject != "''")?" AND id_subject IN(SELECT id_subject FROM Subject WHERE name_subject LIKE " + Subject + ")":" AND id_subject IS NULL");

    if (!DeleteRow(dbConnection, FROM, WHERE))
    {
        MessageBox::Show("������ �������� ���������� �� �������");
        Teachers_Load(nullptr, nullptr);
        dbConnection->Close();
        return;
    }

    MessageBox::Show("������ ������� �������", "��������!");

    //��������� ������ � �������
    Teachers_Load(nullptr, nullptr);
    ClearTextBoxTeachers();

    dbConnection->Close();
    return System::Void();
}

/*-------------------------------������� ���������� ���������� �����----------------------------------------*/

System::Void schoolcourseProject::Teachers::Teachers_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewTeachers->Rows->Clear();

    //����������� � ��
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������
    
    String^ SELECT = "Teacher.id_teacher, surname_teacher, name_teacher, patronymic_teacher, name_subject, classroom, number_class";
    String^ FROM = 
        "((Teacher "+
        "LEFT JOIN Class_to_teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher) "+
        "LEFT JOIN Subject  ON Subject.id_subject = Class_to_teacher.id_subject) "+
        "LEFT JOIN Class ON Class.id_class = Class_to_teacher.id_class";
    String^ ORDER_BY = "surname_teacher, name_teacher";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, ORDER_BY); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewTeachers->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5]->ToString(),
            dbReader[6]);//������ ������ � �������
    }

    //��������� ����������
    dbReader->Close();

    if (domainUpDownSubjects->Items->Count == 1)
    {
        //������ �� ������� ���� ��������
        SELECT = "name_subject";
        FROM = "Subject";
        
        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
        {
            domainUpDownSubjects->Items->Add(dbReader[0]->ToString());
        }

        //��������� ����������
        dbReader->Close();
    }

    if (domainUpDownClasses->Items->Count == 1)
    {
        SELECT = "number_class";
        FROM = "Class";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
        {
            domainUpDownClasses->Items->Add(dbReader[0]);//���������� ������ �� �� �
        }
        dbReader->Close();
    }
 

    //��������� ����������
    dbConnection->Close();

    return System::Void();
}

System::Void schoolcourseProject::Teachers::FillingTextBoxTeachers(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //��������� ��������� ������
    if (dataGridViewTeachers->SelectedRows->Count == 0)
        return;
    

    int index = dataGridViewTeachers->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewTeachers->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBoxTeachers(); //������� ����� �����
        return;
    }

    //���������� �����������
    textBoxID->Text = dataGridViewTeachers->Rows[index]->Cells[0]->Value->ToString();
    textBoxSurname->Text = dataGridViewTeachers->Rows[index]->Cells[1]->Value->ToString();
    textBoxName->Text = dataGridViewTeachers->Rows[index]->Cells[2]->Value->ToString();
    textBoxPatronymic->Text = dataGridViewTeachers->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownSubjects->Text = dataGridViewTeachers->Rows[index]->Cells[4]->Value->ToString();
    textBoxClassroom->Text = dataGridViewTeachers->Rows[index]->Cells[5]->Value->ToString();
    domainUpDownClasses->Text = dataGridViewTeachers->Rows[index]->Cells[6]->Value->ToString();

    return System::Void();
}

System::Void schoolcourseProject::Teachers::ClearTextBoxTeachers()
{
    textBoxID->Text = "";
    textBoxSurname->Text = "";
    textBoxName->Text = "";
    textBoxPatronymic->Text = "";
    textBoxClassroom->Text = "";

    domainUpDownClasses->SelectedIndex = 0;
    domainUpDownSubjects->SelectedIndex = 0;

    return System::Void();
}

System::Void schoolcourseProject::Teachers::domainUpDownSubjects_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{

    if (dataGridViewTeachers->SelectedRows->Count == 1)
        return;


    auto rows = dataGridViewTeachers->Rows;
    int selectedIndex = domainUpDownSubjects->SelectedIndex;

    for (int i = 0; i < rows->Count - 1; i++) {
        rows[i]->Visible = true;
    }

    if (domainUpDownSubjects->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownSubjects->Text)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownClasses->Text)
                rows[i]->Visible = false;
        }
    }
    return System::Void();
}

System::Void schoolcourseProject::Teachers::domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewTeachers->SelectedRows->Count == 1)
        return;

    auto rows = dataGridViewTeachers->Rows;

    for (int i = 0; i < rows->Count - 1; i++) {
        rows[i]->Visible = true;
    }

    if (domainUpDownSubjects->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Subject"]->Value->ToString() != domainUpDownSubjects->Text)
                rows[i]->Visible = false;
        }
    }

    if (domainUpDownClasses->Text != "���")
    {
        for (int i = 0; i < rows->Count - 1; i++) {
            if (rows[i]->Cells["Class"]->Value->ToString() != domainUpDownClasses->Text)
                rows[i]->Visible = false;
        }
    }
    return System::Void();
}
