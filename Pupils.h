#pragma once

namespace schoolcourseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Pupils : public System::Windows::Forms::Form
	{
	public:
		Pupils(void)
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
		~Pupils()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonPupils;
	protected:

	private: System::Windows::Forms::Button^ buttonMarks;

	private: System::Windows::Forms::Button^ buttonTeachers;
	private: System::Windows::Forms::DataGridView^ dataGridViewPupils;


	private: System::Windows::Forms::TextBox^ textBoxSurname;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownClasses;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonProgressTeachers;
	private: System::Windows::Forms::Button^ buttonProgressSubjects;
	private: System::Windows::Forms::Button^ buttonProgressPupils;
	private: System::Windows::Forms::Button^ buttonProgressClasses;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxPatronymic;



	private: System::Windows::Forms::Button^ buttonProgress;
	private: System::Windows::Forms::Button^ buttonSubjects;
	private: System::Windows::Forms::Button^ buttonExit;



	private: System::Windows::Forms::Label^ labelID;
	private: System::Windows::Forms::TextBox^ textBoxID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SurnamePupil;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NamePupil;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PatronymicPupil;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ClassPupil;










	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonProgress = (gcnew System::Windows::Forms::Button());
			this->buttonProgressClasses = (gcnew System::Windows::Forms::Button());
			this->buttonProgressSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonProgressPupils = (gcnew System::Windows::Forms::Button());
			this->buttonProgressTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonMarks = (gcnew System::Windows::Forms::Button());
			this->buttonTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonPupils = (gcnew System::Windows::Forms::Button());
			this->dataGridViewPupils = (gcnew System::Windows::Forms::DataGridView());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownClasses = (gcnew System::Windows::Forms::DomainUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxPatronymic = (gcnew System::Windows::Forms::TextBox());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SurnamePupil = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NamePupil = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PatronymicPupil = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ClassPupil = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPupils))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->buttonSubjects);
			this->panel1->Controls->Add(this->buttonProgress);
			this->panel1->Controls->Add(this->buttonProgressClasses);
			this->panel1->Controls->Add(this->buttonProgressSubjects);
			this->panel1->Controls->Add(this->buttonProgressPupils);
			this->panel1->Controls->Add(this->buttonProgressTeachers);
			this->panel1->Controls->Add(this->buttonMarks);
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
			this->buttonSubjects->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonSubjects->Location = System::Drawing::Point(0, 199);
			this->buttonSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonSubjects->Name = L"buttonSubjects";
			this->buttonSubjects->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonSubjects->Size = System::Drawing::Size(156, 45);
			this->buttonSubjects->TabIndex = 9;
			this->buttonSubjects->Text = L"Предметы";
			this->buttonSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonSubjects->UseVisualStyleBackColor = false;
			this->buttonSubjects->Click += gcnew System::EventHandler(this, &Pupils::buttonSubjects_Click);
			// 
			// buttonProgress
			// 
			this->buttonProgress->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgress->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->FlatAppearance->BorderSize = 0;
			this->buttonProgress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgress->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->Location = System::Drawing::Point(-1, 332);
			this->buttonProgress->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgress->Name = L"buttonProgress";
			this->buttonProgress->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonProgress->Size = System::Drawing::Size(161, 45);
			this->buttonProgress->TabIndex = 8;
			this->buttonProgress->Text = L"Рейтинг";
			this->buttonProgress->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgress->UseVisualStyleBackColor = false;
			this->buttonProgress->Click += gcnew System::EventHandler(this, &Pupils::buttonProgress_Click);
			// 
			// buttonProgressClasses
			// 
			this->buttonProgressClasses->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressClasses->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressClasses->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->FlatAppearance->BorderSize = 0;
			this->buttonProgressClasses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressClasses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonProgressClasses->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->Location = System::Drawing::Point(-3, 467);
			this->buttonProgressClasses->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressClasses->Name = L"buttonProgressClasses";
			this->buttonProgressClasses->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressClasses->Size = System::Drawing::Size(161, 45);
			this->buttonProgressClasses->TabIndex = 7;
			this->buttonProgressClasses->Text = L"по классам";
			this->buttonProgressClasses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressClasses->UseVisualStyleBackColor = false;
			this->buttonProgressClasses->Click += gcnew System::EventHandler(this, &Pupils::buttonProgressClasses_Click);
			// 
			// buttonProgressSubjects
			// 
			this->buttonProgressSubjects->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressSubjects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressSubjects->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->FlatAppearance->BorderSize = 0;
			this->buttonProgressSubjects->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressSubjects->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonProgressSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->Location = System::Drawing::Point(-5, 512);
			this->buttonProgressSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressSubjects->Name = L"buttonProgressSubjects";
			this->buttonProgressSubjects->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressSubjects->Size = System::Drawing::Size(161, 45);
			this->buttonProgressSubjects->TabIndex = 6;
			this->buttonProgressSubjects->Text = L"по предметам";
			this->buttonProgressSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressSubjects->UseVisualStyleBackColor = false;
			this->buttonProgressSubjects->Click += gcnew System::EventHandler(this, &Pupils::buttonProgressSubjects_Click);
			// 
			// buttonProgressPupils
			// 
			this->buttonProgressPupils->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressPupils->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressPupils->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressPupils->FlatAppearance->BorderSize = 0;
			this->buttonProgressPupils->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressPupils->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonProgressPupils->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressPupils->Location = System::Drawing::Point(-3, 422);
			this->buttonProgressPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressPupils->Name = L"buttonProgressPupils";
			this->buttonProgressPupils->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressPupils->Size = System::Drawing::Size(161, 45);
			this->buttonProgressPupils->TabIndex = 5;
			this->buttonProgressPupils->Text = L"по ученикам";
			this->buttonProgressPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressPupils->UseVisualStyleBackColor = false;
			this->buttonProgressPupils->Click += gcnew System::EventHandler(this, &Pupils::buttonProgressPupils_Click);
			// 
			// buttonProgressTeachers
			// 
			this->buttonProgressTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonProgressTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->FlatAppearance->BorderSize = 0;
			this->buttonProgressTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonProgressTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->Location = System::Drawing::Point(-3, 377);
			this->buttonProgressTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressTeachers->Name = L"buttonProgressTeachers";
			this->buttonProgressTeachers->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressTeachers->Size = System::Drawing::Size(161, 45);
			this->buttonProgressTeachers->TabIndex = 4;
			this->buttonProgressTeachers->Text = L"по учителям";
			this->buttonProgressTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressTeachers->UseVisualStyleBackColor = false;
			this->buttonProgressTeachers->Click += gcnew System::EventHandler(this, &Pupils::buttonProgressTeachers_Click);
			// 
			// buttonMarks
			// 
			this->buttonMarks->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonMarks->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonMarks->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonMarks->FlatAppearance->BorderSize = 0;
			this->buttonMarks->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMarks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMarks->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonMarks->Location = System::Drawing::Point(-3, 289);
			this->buttonMarks->Margin = System::Windows::Forms::Padding(0);
			this->buttonMarks->Name = L"buttonMarks";
			this->buttonMarks->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonMarks->Size = System::Drawing::Size(161, 45);
			this->buttonMarks->TabIndex = 3;
			this->buttonMarks->Text = L"Успеваемость";
			this->buttonMarks->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonMarks->UseVisualStyleBackColor = false;
			this->buttonMarks->Click += gcnew System::EventHandler(this, &Pupils::buttonMarks_Click);
			// 
			// buttonTeachers
			// 
			this->buttonTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->FlatAppearance->BorderSize = 0;
			this->buttonTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->Location = System::Drawing::Point(0, 244);
			this->buttonTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonTeachers->Name = L"buttonTeachers";
			this->buttonTeachers->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonTeachers->Size = System::Drawing::Size(156, 45);
			this->buttonTeachers->TabIndex = 2;
			this->buttonTeachers->Text = L"Учителя";
			this->buttonTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTeachers->UseVisualStyleBackColor = false;
			this->buttonTeachers->Click += gcnew System::EventHandler(this, &Pupils::buttonTeachers_Click);
			// 
			// buttonPupils
			// 
			this->buttonPupils->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonPupils->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(112)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->buttonPupils->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonPupils->FlatAppearance->BorderSize = 0;
			this->buttonPupils->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPupils->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPupils->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonPupils->Location = System::Drawing::Point(2, 155);
			this->buttonPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonPupils->Name = L"buttonPupils";
			this->buttonPupils->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonPupils->Size = System::Drawing::Size(156, 45);
			this->buttonPupils->TabIndex = 1;
			this->buttonPupils->Text = L"Ученики";
			this->buttonPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPupils->UseVisualStyleBackColor = false;
			this->buttonPupils->Click += gcnew System::EventHandler(this, &Pupils::buttonPupils_Click);
			// 
			// dataGridViewPupils
			// 
			this->dataGridViewPupils->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewPupils->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPupils->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id,
					this->SurnamePupil, this->NamePupil, this->PatronymicPupil, this->ClassPupil
			});
			this->dataGridViewPupils->Location = System::Drawing::Point(468, 70);
			this->dataGridViewPupils->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridViewPupils->Name = L"dataGridViewPupils";
			this->dataGridViewPupils->RowHeadersWidth = 51;
			this->dataGridViewPupils->RowTemplate->Height = 24;
			this->dataGridViewPupils->Size = System::Drawing::Size(576, 567);
			this->dataGridViewPupils->TabIndex = 1;
			this->dataGridViewPupils->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Pupils::FillngTextBoxPupils);
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSurname->Location = System::Drawing::Point(278, 218);
			this->textBoxSurname->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(151, 21);
			this->textBoxSurname->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(186, 221);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Фамилия";
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(278, 267);
			this->textBoxName->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(151, 21);
			this->textBoxName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(186, 270);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Имя";
			// 
			// domainUpDownClasses
			// 
			this->domainUpDownClasses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownClasses->Items->Add(L"Все");
			this->domainUpDownClasses->Location = System::Drawing::Point(278, 144);
			this->domainUpDownClasses->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->domainUpDownClasses->Name = L"domainUpDownClasses";
			this->domainUpDownClasses->Size = System::Drawing::Size(150, 21);
			this->domainUpDownClasses->TabIndex = 8;
			this->domainUpDownClasses->SelectedItemChanged += gcnew System::EventHandler(this, &Pupils::domainUpDownClasses_SelectedItemChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(186, 144);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Класс";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(279, 388);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(150, 31);
			this->buttonAdd->TabIndex = 10;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Pupils::buttonAdd_Click);
			// 
			// buttonChange
			// 
			this->buttonChange->Location = System::Drawing::Point(279, 440);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(150, 31);
			this->buttonChange->TabIndex = 11;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &Pupils::buttonChange_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Location = System::Drawing::Point(279, 492);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(150, 31);
			this->buttonDelete->TabIndex = 12;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &Pupils::buttonDelete_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(186, 322);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Отчество";
			// 
			// textBoxPatronymic
			// 
			this->textBoxPatronymic->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPatronymic->Location = System::Drawing::Point(278, 320);
			this->textBoxPatronymic->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxPatronymic->Name = L"textBoxPatronymic";
			this->textBoxPatronymic->Size = System::Drawing::Size(151, 21);
			this->textBoxPatronymic->TabIndex = 14;
			// 
			// buttonExit
			// 
			this->buttonExit->FlatAppearance->BorderSize = 0;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Location = System::Drawing::Point(1039, 0);
			this->buttonExit->Margin = System::Windows::Forms::Padding(0);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(33, 29);
			this->buttonExit->TabIndex = 15;
			this->buttonExit->Text = L"x";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Pupils::buttonExit_Click);
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelID->Location = System::Drawing::Point(187, 84);
			this->labelID->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(19, 17);
			this->labelID->TabIndex = 17;
			this->labelID->Text = L"id";
			// 
			// textBoxID
			// 
			this->textBoxID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxID->Location = System::Drawing::Point(279, 81);
			this->textBoxID->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->ReadOnly = true;
			this->textBoxID->Size = System::Drawing::Size(151, 21);
			this->textBoxID->TabIndex = 16;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->Visible = false;
			// 
			// SurnamePupil
			// 
			this->SurnamePupil->FillWeight = 256.6845F;
			this->SurnamePupil->HeaderText = L"Фамилия";
			this->SurnamePupil->MinimumWidth = 140;
			this->SurnamePupil->Name = L"SurnamePupil";
			// 
			// NamePupil
			// 
			this->NamePupil->FillWeight = 19.98947F;
			this->NamePupil->HeaderText = L"Имя";
			this->NamePupil->MinimumWidth = 140;
			this->NamePupil->Name = L"NamePupil";
			// 
			// PatronymicPupil
			// 
			this->PatronymicPupil->FillWeight = 58.99557F;
			this->PatronymicPupil->HeaderText = L"Отчество";
			this->PatronymicPupil->MinimumWidth = 140;
			this->PatronymicPupil->Name = L"PatronymicPupil";
			// 
			// ClassPupil
			// 
			this->ClassPupil->FillWeight = 64.33047F;
			this->ClassPupil->HeaderText = L"Класс";
			this->ClassPupil->MinimumWidth = 100;
			this->ClassPupil->Name = L"ClassPupil";
			// 
			// Pupils
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1071, 663);
			this->ControlBox = false;
			this->Controls->Add(this->labelID);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->textBoxPatronymic);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->domainUpDownClasses);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxSurname);
			this->Controls->Add(this->dataGridViewPupils);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Pupils";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Pupils::Pupils_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPupils))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonSubjects_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonTeachers_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonMarks_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgress_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressTeachers_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressPupils_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressClasses_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonProgressSubjects_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Pupils_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void FillngTextBoxPupils(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void ClearTextBoxPupils();
private: System::Void buttonPupils_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownClasses_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
};
}
