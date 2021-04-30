#include "Pupils.h"
#include "Teachers.h"
#include "ProgressTeachers.h"
#include "ProgressPupils.h"
#include "QuarterMarks.h"
#include "Subjects.h"
#include "ProgressClasses.h"
#include "ProgressSubjects.h"

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

    //����������� � ��
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������    

    //������ ��� ������
    String^ query = 
        "SELECT id_teacher " +
        "FROM Teacher " +
        "WHERE name_teacher LIKE '" + textBoxName->Text + "' " +
        "AND surname_teacher LIKE '" + textBoxSurname->Text + "' " +
        "AND patronymic_teacher LIKE '" + textBoxPatronymic->Text + "' ;";;
        //������ ������ ��� ���������� id ������
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    auto dbReaderTeacher = dbCommand->ExecuteReader();

    //��������� ���� �� ����� �������
    if (!dbReaderTeacher->HasRows) {
        //���� ��� �� ���������
        dbReaderTeacher->Close();

        dbCommand->CommandText = 
            "INSERT INTO Teacher(name_teacher, surname_teacher, patronymic_teacher, classroom) "+
            "VALUES ('"+textBoxName->Text+"', '"+textBoxSurname->Text+"', '"+textBoxPatronymic->Text+"', '"+textBoxClassroom->Text+"');";
        dbCommand->ExecuteNonQuery();

        dbCommand->CommandText = "SELECT MAX(id_teacher) FROM Teacher";
        dbReaderTeacher = dbCommand->ExecuteReader();
    }

    dbReaderTeacher->Read();
    id_teacher = dbReaderTeacher[0]->ToString();
    dbReaderTeacher->Close();

  
    //������ ��� ������
    dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "' ;"; //������ ������ ��� ���������� id ������
    auto dbReaderClass = dbCommand->ExecuteReader();

    //������ �����
    dbReaderClass->Read();
    id_class = dbReaderClass[0]->ToString();
    dbReaderClass->Close();
    
    //������ ������� �� �������

    dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text + "' ;"; //������ ������ ��� ���������� id ������
    auto dbReaderSubject = dbCommand->ExecuteReader();

    //������ �������
    dbReaderSubject->Read();
    id_subject = dbReaderSubject[0]->ToString();
    dbReaderSubject->Close();
    
    //��������� ���� �� ����� ������ � Class_to_teacher
    
    dbCommand->CommandText = "SELECT * " +
        "FROM Class_to_teacher " +
        "WHERE " +
        "id_class = " + id_class + " AND " +
        "id_teacher = " + id_teacher + " AND " +
        "id_subject = " + id_subject + ";";

    if(dbCommand->ExecuteNonQuery() < 1)
    {     
        dbCommand->CommandText =
            "INSERT INTO Class_to_teacher (id_class, id_teacher, id_subject) " +
            "VALUES (" + id_class + "," + id_teacher + ", "+id_subject+");";
        dbCommand->ExecuteNonQuery();
    }
    else 
    {
        MessageBox::Show("����� ������ ��� ����!","��������!");
        return;
    }

    MessageBox::Show("������ ������� ���������!");

    dataGridViewTeachers->Rows->Clear();
    Teachers_Load(nullptr, nullptr); 

    ClearTextBoxTeachers();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
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

    //��������� ���� �� ��������� ������
    if (dataGridViewTeachers->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }
    int index = dataGridViewTeachers->SelectedRows[0]->Index;

    String^ id_teacherTB = textBoxID->Text->ToString();
    String^ id_classTB;
    String^ id_subjectTB;
    String^ id_teacherSG = dataGridViewTeachers->Rows[index]->Cells["ID"]->Value->ToString();
    String^ id_classSG;
    String^ id_subjectSG;
    String^ id_class_teacher;

    if (id_teacherTB != id_teacherSG) {
        MessageBox::Show("�������� ���� ������!", "��������!");
        return;
    }

    //����������� � ��
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������
    
     //������ �� ���������� �������
    String^ query =
        "UPDATE Teacher " +
        "SET name_teacher = '" + textBoxName->Text + "', " +
        "surname_teacher = '" + textBoxSurname->Text + "', " +
        "patronymic_teacher = '" + textBoxPatronymic->Text + "', " +
        "classroom = " + textBoxClassroom->Text +" "+
        "WHERE id_teacher = " + id_teacherSG + ";";
    
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    dbCommand->ExecuteNonQuery();

    /*-----------------------------�� ������� ���������� ������ -----------------------------------*/

    //������ ��� ������ �� ������� ���������� ������ 
    
        dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text + "' ;"; //������ ������ ��� ���������� id ������
        auto dbReaderClass = dbCommand->ExecuteReader();

    //������ �����
        dbReaderClass->Read();
        id_classTB = dbReaderClass[0]->ToString();
        dbReaderClass->Close();
    
    //������ ������� �� ������� �� ������� ���������� ������
    
        dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text + "' ;"; //������ ������ ��� ���������� id ������
        auto dbReaderSubject = dbCommand->ExecuteReader();

    //������ �������
        dbReaderSubject->Read();
        id_subjectTB = dbReaderSubject[0]->ToString();
        dbReaderSubject->Close();
    
  /*----------------------������� ������----------------------------*/

    dbCommand->CommandText = "SELECT id_class FROM Class WHERE number_class LIKE '" + dataGridViewTeachers->Rows[index]->Cells["Class"]->Value->ToString() + "' ;"; //������ ������ ��� ���������� id ������
    dbReaderClass = dbCommand->ExecuteReader();

    //������ �����
    if (dbReaderClass->HasRows)
    {
        dbReaderClass->Read();
        id_classSG = dbReaderClass[0]->ToString();
        dbReaderClass->Close();
    }
    else 
    {
        id_classSG = "0";
    }

    //������ ������� �� ������� ������� ������

    dbCommand->CommandText = "SELECT id_subject FROM Subject WHERE name_subject LIKE '" + dataGridViewTeachers->Rows[index]->Cells["Subject"]->Value->ToString() + "' ;"; //������ ������ ��� ���������� id ������
    dbReaderSubject = dbCommand->ExecuteReader();

    //������ �������
    if (dbReaderSubject->HasRows)
    {
        dbReaderSubject->Read();
        id_subjectSG = dbReaderSubject[0]->ToString();
        dbReaderSubject->Close();
    }
    else
    {
        id_subjectSG = "0";
    }
    //���� id ������ ������� ����� ��������

    dbCommand->CommandText = "SELECT id_class_teacher " +
        "FROM Class_to_teacher " +
        "WHERE id_teacher = " + id_teacherSG + 
        " AND id_class = " + id_classSG + 
        " AND id_subject = " + id_subjectSG + ";";
    auto dbReaderClassTeacher = dbCommand->ExecuteReader();

    dbReaderClassTeacher->Read();
    id_class_teacher = dbReaderClassTeacher[0]->ToString();
    dbReaderClassTeacher->Close();

    //��������� ������
    dbCommand->CommandText =
        "UPDATE Class_to_teacher " +
        " SET id_class = " + id_classTB + ", id_subject = " + id_subjectTB +
        " WHERE id_class_teacher = " + id_class_teacher + ";";

    dbCommand->ExecuteNonQuery();
    //��������� ����������
    dbConnection->Close();

    //��������� �������
    dataGridViewTeachers->Rows->Clear();
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

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query =
        "DELETE FROM Class_to_teacher WHERE id_teacher =" + textBoxID->Text + " " +
        " AND id_class IN (SELECT id_class FROM Class WHERE number_class LIKE '" + domainUpDownClasses->Text->ToString() + "') " +
        " AND id_subject IN(SELECT id_subject FROM Subject WHERE name_subject LIKE '" + domainUpDownSubjects->Text->ToString() + "');";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("������ �������� ���������� �� �������");
        dbConnection->Close();
        return;
    }


    dbCommand->CommandText="DELETE FROM Teacher WHERE id_teacher =" + textBoxID->Text +" " +
        " AND id_teacher NOT IN(SELECT id_teacher FROM Class_to_teacher) ";
    dbCommand->ExecuteNonQuery();

    MessageBox::Show("������ ������� �������", "��������!");

    //��������� ������ � �������
    dataGridViewTeachers->Rows->Clear();
    Teachers_Load(nullptr, nullptr);
    ClearTextBoxTeachers();

    dbConnection->Close();
    return System::Void();
}

System::Void schoolcourseProject::Teachers::Teachers_Load(System::Object^ sender, System::EventArgs^ e)
{
    //����������� � ��
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.16.0;Data Source=school.accdb"; //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������


    String^ query = 
        "SELECT "+
        "Teacher.id_teacher, "+
        "surname_teacher, "+
        "name_teacher, "+ 
        "patronymic_teacher, "+
        "name_subject, "+
        "classroom, "+
        "number_class "+
        "FROM "+
        "( "+
            "( "+
                "( "+
                    "Class_to_teacher "+
                    "INNER JOIN Teacher ON Teacher.id_teacher = Class_to_teacher.id_teacher "+
                    ") "+ 
                "LEFT JOIN Class ON Class_to_teacher.id_class = Class.id_class "+
                ") "+
            "INNER JOIN Subject ON Subject.id_subject = Class_to_teacher.id_subject "+
        "); "; //������ ������
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    OleDbDataReader^ dbReaderTeacher = dbCommand->ExecuteReader(); //����� ���������� �������

    while (dbReaderTeacher->Read())
    {
        dataGridViewTeachers->Rows->Add(
            dbReaderTeacher[0],
            dbReaderTeacher[1],
            dbReaderTeacher[2],
            dbReaderTeacher[3],
            dbReaderTeacher[4],
            dbReaderTeacher[5],
            dbReaderTeacher[6]);//������ ������ � �������
    }

    //��������� ����������
    dbReaderTeacher->Close();

    if (domainUpDownSubjects->Items->Count == 1)
    {
        //������ �� ������� ���� ��������
        dbCommand->CommandText = "SELECT name_subject FROM Subject";
        auto dbReaderSubject = dbCommand->ExecuteReader();

        while (dbReaderSubject->Read())
        {
            domainUpDownSubjects->Items->Add(dbReaderSubject[0]->ToString());
        }

        //��������� ����������
        dbReaderSubject->Close();
    }

    if (domainUpDownClasses->Items->Count == 1)
    {
        dbCommand->CommandText = "SELECT number_class FROM Class ORDER BY 1"; //������ ������

        //��������� ������ 
        auto dbReaderClass = dbCommand->ExecuteReader();

        if (!dbReaderClass->HasRows)
        {
            MessageBox::Show("������ ������!", "��������!");
            dbConnection->Close();//��������� ����������
            return;
        }

        while (dbReaderClass->Read())
        {
            domainUpDownClasses->Items->Add(dbReaderClass[0]);//���������� ������ �� �� �
        }
        dbReaderClass->Close();
    }
 

    //��������� ����������
    dbConnection->Close();

    return System::Void();
}

System::Void schoolcourseProject::Teachers::FillingTextBoxTeachers(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //��������� ��������� ������
    if (dataGridViewTeachers->SelectedRows->Count == 0)
    {
        return;
    }

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
