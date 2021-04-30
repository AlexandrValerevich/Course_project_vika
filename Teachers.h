#pragma once

namespace schoolcourseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Teachers : public System::Windows::Forms::Form
	{
	public:
		Teachers(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Teachers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonPupils;
	private: System::Windows::Forms::Button^ buttonProgress;
	protected:


	private: System::Windows::Forms::Button^ buttonTeachers;
	private: System::Windows::Forms::DataGridView^ dataGridViewTeachers;



	private: System::Windows::Forms::TextBox^ textBoxSurname;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonChange;






	private: System::Windows::Forms::TextBox^ textBoxPatronymic;

	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxClassroom;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonDelete;

	private: System::Windows::Forms::Button^ buttonProgressSubjects;






	private: System::Windows::Forms::Button^ buttonProgressPupils;

	private: System::Windows::Forms::Button^ buttonProgressTeachers;
	private: System::Windows::Forms::Button^ buttonProgressClasses;







	private: System::Windows::Forms::Button^ buttonMarks;

	private: System::Windows::Forms::Button^ buttonSubjects;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxID;







	private: System::Windows::Forms::DomainUpDown^ domainUpDownSubjects;







	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownClasses;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SurnameTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PatronymicTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Classroom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Class;






















































	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonMarks = (gcnew System::Windows::Forms::Button());
			this->buttonProgressClasses = (gcnew System::Windows::Forms::Button());
			this->buttonProgressSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonProgressPupils = (gcnew System::Windows::Forms::Button());
			this->buttonProgressTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonProgress = (gcnew System::Windows::Forms::Button());
			this->buttonTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonPupils = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTeachers = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SurnameTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PatronymicTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Classroom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Class = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->textBoxPatronymic = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxClassroom = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->domainUpDownSubjects = (gcnew System::Windows::Forms::DomainUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownClasses = (gcnew System::Windows::Forms::DomainUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTeachers))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->buttonSubjects);
			this->panel1->Controls->Add(this->buttonMarks);
			this->panel1->Controls->Add(this->buttonProgressClasses);
			this->panel1->Controls->Add(this->buttonProgressSubjects);
			this->panel1->Controls->Add(this->buttonProgressPupils);
			this->panel1->Controls->Add(this->buttonProgressTeachers);
			this->panel1->Controls->Add(this->buttonProgress);
			this->panel1->Controls->Add(this->buttonTeachers);
			this->panel1->Controls->Add(this->buttonPupils);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(158, 663);
			this->panel1->TabIndex = 0;
			// 
			// buttonSubjects
			// 
			this->buttonSubjects->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonSubjects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonSubjects->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonSubjects->FlatAppearance->BorderSize = 0;
			this->buttonSubjects->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSubjects->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonSubjects->Location = System::Drawing::Point(0, 205);
			this->buttonSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonSubjects->Name = L"buttonSubjects";
			this->buttonSubjects->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonSubjects->Size = System::Drawing::Size(156, 45);
			this->buttonSubjects->TabIndex = 12;
			this->buttonSubjects->Text = L"Предметы";
			this->buttonSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonSubjects->UseVisualStyleBackColor = false;
			this->buttonSubjects->Click += gcnew System::EventHandler(this, &Teachers::buttonSubjects_Click);
			// 
			// buttonMarks
			// 
			this->buttonMarks->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonMarks->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonMarks->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonMarks->FlatAppearance->BorderSize = 0;
			this->buttonMarks->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMarks->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMarks->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonMarks->Location = System::Drawing::Point(0, 291);
			this->buttonMarks->Margin = System::Windows::Forms::Padding(0);
			this->buttonMarks->Name = L"buttonMarks";
			this->buttonMarks->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonMarks->Size = System::Drawing::Size(156, 45);
			this->buttonMarks->TabIndex = 11;
			this->buttonMarks->Text = L"Успеваемость";
			this->buttonMarks->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonMarks->UseVisualStyleBackColor = false;
			this->buttonMarks->Click += gcnew System::EventHandler(this, &Teachers::buttonMarks_Click);
			// 
			// buttonProgressClasses
			// 
			this->buttonProgressClasses->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressClasses->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressClasses->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->FlatAppearance->BorderSize = 0;
			this->buttonProgressClasses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressClasses->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressClasses->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->Location = System::Drawing::Point(0, 471);
			this->buttonProgressClasses->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressClasses->Name = L"buttonProgressClasses";
			this->buttonProgressClasses->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressClasses->Size = System::Drawing::Size(161, 45);
			this->buttonProgressClasses->TabIndex = 10;
			this->buttonProgressClasses->Text = L"по классам";
			this->buttonProgressClasses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressClasses->UseVisualStyleBackColor = false;
			this->buttonProgressClasses->Click += gcnew System::EventHandler(this, &Teachers::buttonProgressClasses_Click);
			// 
			// buttonProgressSubjects
			// 
			this->buttonProgressSubjects->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressSubjects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressSubjects->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->FlatAppearance->BorderSize = 0;
			this->buttonProgressSubjects->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressSubjects->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->Location = System::Drawing::Point(0, 516);
			this->buttonProgressSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressSubjects->Name = L"buttonProgressSubjects";
			this->buttonProgressSubjects->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressSubjects->Size = System::Drawing::Size(161, 45);
			this->buttonProgressSubjects->TabIndex = 9;
			this->buttonProgressSubjects->Text = L"по предметам";
			this->buttonProgressSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressSubjects->UseVisualStyleBackColor = false;
			this->buttonProgressSubjects->Click += gcnew System::EventHandler(this, &Teachers::buttonProgressSubjects_Click);
			// 
			// buttonProgressPupils
			// 
			this->buttonProgressPupils->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressPupils->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressPupils->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressPupils->FlatAppearance->BorderSize = 0;
			this->buttonProgressPupils->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressPupils->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressPupils->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressPupils->Location = System::Drawing::Point(0, 426);
			this->buttonProgressPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressPupils->Name = L"buttonProgressPupils";
			this->buttonProgressPupils->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressPupils->Size = System::Drawing::Size(161, 45);
			this->buttonProgressPupils->TabIndex = 8;
			this->buttonProgressPupils->Text = L"по ученикам";
			this->buttonProgressPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressPupils->UseVisualStyleBackColor = false;
			this->buttonProgressPupils->Click += gcnew System::EventHandler(this, &Teachers::buttonProgressPupils_Click);
			// 
			// buttonProgressTeachers
			// 
			this->buttonProgressTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->FlatAppearance->BorderSize = 0;
			this->buttonProgressTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressTeachers->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->Location = System::Drawing::Point(0, 381);
			this->buttonProgressTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressTeachers->Name = L"buttonProgressTeachers";
			this->buttonProgressTeachers->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressTeachers->Size = System::Drawing::Size(161, 45);
			this->buttonProgressTeachers->TabIndex = 7;
			this->buttonProgressTeachers->Text = L"по учителям";
			this->buttonProgressTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressTeachers->UseVisualStyleBackColor = false;
			this->buttonProgressTeachers->Click += gcnew System::EventHandler(this, &Teachers::buttonProgressTeachers_Click);
			// 
			// buttonProgress
			// 
			this->buttonProgress->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgress->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->FlatAppearance->BorderSize = 0;
			this->buttonProgress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgress->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgress->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->Location = System::Drawing::Point(0, 336);
			this->buttonProgress->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgress->Name = L"buttonProgress";
			this->buttonProgress->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonProgress->Size = System::Drawing::Size(161, 45);
			this->buttonProgress->TabIndex = 3;
			this->buttonProgress->Text = L"Рейтинг";
			this->buttonProgress->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgress->UseVisualStyleBackColor = false;
			this->buttonProgress->Click += gcnew System::EventHandler(this, &Teachers::buttonProgress_Click);
			// 
			// buttonTeachers
			// 
			this->buttonTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(112)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->buttonTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->FlatAppearance->BorderSize = 0;
			this->buttonTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTeachers->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->Location = System::Drawing::Point(0, 246);
			this->buttonTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonTeachers->Name = L"buttonTeachers";
			this->buttonTeachers->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonTeachers->Size = System::Drawing::Size(156, 45);
			this->buttonTeachers->TabIndex = 2;
			this->buttonTeachers->Text = L"Учителя";
			this->buttonTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTeachers->UseVisualStyleBackColor = false;
			this->buttonTeachers->Click += gcnew System::EventHandler(this, &Teachers::buttonTeachers_Click);
			// 
			// buttonPupils
			// 
			this->buttonPupils->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonPupils->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonPupils->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonPupils->FlatAppearance->BorderSize = 0;
			this->buttonPupils->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPupils->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPupils->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonPupils->Location = System::Drawing::Point(0, 159);
			this->buttonPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonPupils->Name = L"buttonPupils";
			this->buttonPupils->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonPupils->Size = System::Drawing::Size(156, 45);
			this->buttonPupils->TabIndex = 1;
			this->buttonPupils->Text = L"Ученики";
			this->buttonPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPupils->UseVisualStyleBackColor = false;
			this->buttonPupils->Click += gcnew System::EventHandler(this, &Teachers::buttonPupils_Click);
			// 
			// dataGridViewTeachers
			// 
			this->dataGridViewTeachers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTeachers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ID,
					this->SurnameTeacher, this->NameTeacher, this->PatronymicTeacher, this->Subject, this->Classroom, this->Class
			});
			this->dataGridViewTeachers->Location = System::Drawing::Point(447, 71);
			this->dataGridViewTeachers->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridViewTeachers->Name = L"dataGridViewTeachers";
			this->dataGridViewTeachers->RowHeadersWidth = 51;
			this->dataGridViewTeachers->RowTemplate->Height = 24;
			this->dataGridViewTeachers->Size = System::Drawing::Size(602, 567);
			this->dataGridViewTeachers->TabIndex = 1;
			this->dataGridViewTeachers->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Teachers::FillingTextBoxTeachers);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 110;
			this->ID->Name = L"ID";
			this->ID->Visible = false;
			this->ID->Width = 125;
			// 
			// SurnameTeacher
			// 
			this->SurnameTeacher->HeaderText = L"Фамилия";
			this->SurnameTeacher->MinimumWidth = 105;
			this->SurnameTeacher->Name = L"SurnameTeacher";
			this->SurnameTeacher->Width = 105;
			// 
			// NameTeacher
			// 
			this->NameTeacher->HeaderText = L"Имя";
			this->NameTeacher->MinimumWidth = 100;
			this->NameTeacher->Name = L"NameTeacher";
			this->NameTeacher->Width = 105;
			// 
			// PatronymicTeacher
			// 
			this->PatronymicTeacher->HeaderText = L"Отчество";
			this->PatronymicTeacher->MinimumWidth = 100;
			this->PatronymicTeacher->Name = L"PatronymicTeacher";
			this->PatronymicTeacher->Width = 105;
			// 
			// Subject
			// 
			this->Subject->HeaderText = L"Предмет";
			this->Subject->MinimumWidth = 135;
			this->Subject->Name = L"Subject";
			this->Subject->Width = 135;
			// 
			// Classroom
			// 
			this->Classroom->HeaderText = L"Кабинет";
			this->Classroom->MinimumWidth = 85;
			this->Classroom->Name = L"Classroom";
			this->Classroom->Width = 85;
			// 
			// Class
			// 
			this->Class->HeaderText = L"Класс";
			this->Class->MinimumWidth = 70;
			this->Class->Name = L"Class";
			this->Class->Width = 80;
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSurname->Location = System::Drawing::Point(270, 144);
			this->textBoxSurname->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(151, 26);
			this->textBoxSurname->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(178, 147);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Фамилия";
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(270, 193);
			this->textBoxName->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(151, 26);
			this->textBoxName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(178, 196);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Имя";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(272, 461);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(150, 31);
			this->buttonAdd->TabIndex = 10;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Teachers::buttonAdd_Click);
			// 
			// buttonChange
			// 
			this->buttonChange->Location = System::Drawing::Point(272, 513);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(150, 31);
			this->buttonChange->TabIndex = 11;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &Teachers::buttonChange_Click);
			// 
			// textBoxPatronymic
			// 
			this->textBoxPatronymic->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPatronymic->Location = System::Drawing::Point(270, 246);
			this->textBoxPatronymic->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxPatronymic->Name = L"textBoxPatronymic";
			this->textBoxPatronymic->Size = System::Drawing::Size(151, 26);
			this->textBoxPatronymic->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(178, 248);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Отчество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(178, 302);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Предмет";
			// 
			// textBoxClassroom
			// 
			this->textBoxClassroom->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxClassroom->Location = System::Drawing::Point(272, 356);
			this->textBoxClassroom->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxClassroom->Name = L"textBoxClassroom";
			this->textBoxClassroom->Size = System::Drawing::Size(150, 26);
			this->textBoxClassroom->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(178, 358);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 20);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Кабинет";
			// 
			// buttonDelete
			// 
			this->buttonDelete->Location = System::Drawing::Point(273, 568);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(150, 31);
			this->buttonDelete->TabIndex = 18;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &Teachers::buttonDelete_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->FlatAppearance->BorderSize = 0;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Location = System::Drawing::Point(1039, 0);
			this->buttonExit->Margin = System::Windows::Forms::Padding(0);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(33, 29);
			this->buttonExit->TabIndex = 19;
			this->buttonExit->Text = L"x";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Teachers::buttonExit_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(179, 74);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(25, 20);
			this->label6->TabIndex = 21;
			this->label6->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxID->Location = System::Drawing::Point(271, 71);
			this->textBoxID->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->ReadOnly = true;
			this->textBoxID->Size = System::Drawing::Size(151, 26);
			this->textBoxID->TabIndex = 20;
			// 
			// domainUpDownSubjects
			// 
			this->domainUpDownSubjects->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownSubjects->Items->Add(L"Все");
			this->domainUpDownSubjects->Location = System::Drawing::Point(273, 299);
			this->domainUpDownSubjects->Name = L"domainUpDownSubjects";
			this->domainUpDownSubjects->ReadOnly = true;
			this->domainUpDownSubjects->Size = System::Drawing::Size(150, 26);
			this->domainUpDownSubjects->TabIndex = 22;
			this->domainUpDownSubjects->Text = L"Все";
			this->domainUpDownSubjects->SelectedItemChanged += gcnew System::EventHandler(this, &Teachers::domainUpDownSubjects_SelectedItemChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(178, 407);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 20);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Класс";
			// 
			// domainUpDownClasses
			// 
			this->domainUpDownClasses->Font = (gcnew System::Drawing::Font(L"Inter", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownClasses->Items->Add(L"Все");
			this->domainUpDownClasses->Location = System::Drawing::Point(271, 406);
			this->domainUpDownClasses->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->domainUpDownClasses->Name = L"domainUpDownClasses";
			this->domainUpDownClasses->ReadOnly = true;
			this->domainUpDownClasses->Size = System::Drawing::Size(150, 26);
			this->domainUpDownClasses->TabIndex = 23;
			this->domainUpDownClasses->Text = L"Все";
			this->domainUpDownClasses->SelectedItemChanged += gcnew System::EventHandler(this, &Teachers::domainUpDownClasses_SelectedItemChanged);
			// 
			// Teachers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1071, 663);
			this->ControlBox = false;
			this->Controls->Add(this->label7);
			this->Controls->Add(this->domainUpDownClasses);
			this->Controls->Add(this->domainUpDownSubjects);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxClassroom);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxPatronymic);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxSurname);
			this->Controls->Add(this->dataGridViewTeachers);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Teachers";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Teachers::Teachers_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTeachers))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void buttonPupils_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonMarks_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgress_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Teachers_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void FillingTextBoxTeachers(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void ClearTextBoxTeachers();
private: System::Void domainUpDownSubjects_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
};
}
