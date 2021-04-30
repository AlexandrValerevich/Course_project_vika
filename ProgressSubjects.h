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
	public ref class ProgressSubjects : public System::Windows::Forms::Form
	{
	public:
		ProgressSubjects(void)
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
		~ProgressSubjects()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

























	private: System::Windows::Forms::DataGridView^ dataGridViewHigh;






	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;






	private: System::Windows::Forms::Label^ label3;








































	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;











private: System::Windows::Forms::DataGridViewTextBoxColumn^ SubjectMarks;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ MarkToSubject;
private: System::Windows::Forms::DataGridView^ dataGridViewLow;

private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridView^ dataGridViewAll;

private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;









private: System::Windows::Forms::Button^ buttonExit;
private: System::Windows::Forms::Button^ buttonSubjects;
private: System::Windows::Forms::Button^ buttonProgress;
private: System::Windows::Forms::Button^ buttonProgressClasses;
private: System::Windows::Forms::Button^ buttonProgressSubjects;
private: System::Windows::Forms::Button^ buttonProgressPupils;
private: System::Windows::Forms::Button^ buttonProgressTeachers;
private: System::Windows::Forms::Button^ buttonMarks;
private: System::Windows::Forms::Button^ buttonTeachers;
private: System::Windows::Forms::Button^ buttonPupils;






















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
			this->buttonProgress = (gcnew System::Windows::Forms::Button());
			this->buttonProgressClasses = (gcnew System::Windows::Forms::Button());
			this->buttonProgressSubjects = (gcnew System::Windows::Forms::Button());
			this->buttonProgressPupils = (gcnew System::Windows::Forms::Button());
			this->buttonProgressTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonMarks = (gcnew System::Windows::Forms::Button());
			this->buttonTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonPupils = (gcnew System::Windows::Forms::Button());
			this->dataGridViewHigh = (gcnew System::Windows::Forms::DataGridView());
			this->SubjectMarks = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MarkToSubject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->dataGridViewLow = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewAll = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHigh))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAll))->BeginInit();
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
			this->buttonSubjects->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonSubjects->Location = System::Drawing::Point(2, 174);
			this->buttonSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonSubjects->Name = L"buttonSubjects";
			this->buttonSubjects->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonSubjects->Size = System::Drawing::Size(156, 45);
			this->buttonSubjects->TabIndex = 27;
			this->buttonSubjects->Text = L"Предметы";
			this->buttonSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonSubjects->UseVisualStyleBackColor = false;
			this->buttonSubjects->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonSubjects_Click);
			// 
			// buttonProgress
			// 
			this->buttonProgress->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(112)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->buttonProgress->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->FlatAppearance->BorderSize = 0;
			this->buttonProgress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgress->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgress->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgress->Location = System::Drawing::Point(1, 307);
			this->buttonProgress->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgress->Name = L"buttonProgress";
			this->buttonProgress->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonProgress->Size = System::Drawing::Size(161, 45);
			this->buttonProgress->TabIndex = 26;
			this->buttonProgress->Text = L"Рейтинг";
			this->buttonProgress->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgress->UseVisualStyleBackColor = false;
			this->buttonProgress->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonProgress_Click);
			// 
			// buttonProgressClasses
			// 
			this->buttonProgressClasses->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressClasses->BackColor = System::Drawing::Color::Transparent;
			this->buttonProgressClasses->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->FlatAppearance->BorderSize = 0;
			this->buttonProgressClasses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressClasses->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressClasses->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressClasses->Location = System::Drawing::Point(-1, 442);
			this->buttonProgressClasses->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressClasses->Name = L"buttonProgressClasses";
			this->buttonProgressClasses->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressClasses->Size = System::Drawing::Size(161, 45);
			this->buttonProgressClasses->TabIndex = 25;
			this->buttonProgressClasses->Text = L"по классам";
			this->buttonProgressClasses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressClasses->UseVisualStyleBackColor = false;
			this->buttonProgressClasses->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonProgressClasses_Click);
			// 
			// buttonProgressSubjects
			// 
			this->buttonProgressSubjects->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressSubjects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->buttonProgressSubjects->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->FlatAppearance->BorderSize = 0;
			this->buttonProgressSubjects->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressSubjects->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressSubjects->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressSubjects->Location = System::Drawing::Point(-3, 487);
			this->buttonProgressSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressSubjects->Name = L"buttonProgressSubjects";
			this->buttonProgressSubjects->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressSubjects->Size = System::Drawing::Size(161, 45);
			this->buttonProgressSubjects->TabIndex = 24;
			this->buttonProgressSubjects->Text = L"по предметам";
			this->buttonProgressSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressSubjects->UseVisualStyleBackColor = false;
			this->buttonProgressSubjects->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonProgressSubjects_Click);
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
			this->buttonProgressPupils->Location = System::Drawing::Point(-1, 397);
			this->buttonProgressPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressPupils->Name = L"buttonProgressPupils";
			this->buttonProgressPupils->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressPupils->Size = System::Drawing::Size(161, 45);
			this->buttonProgressPupils->TabIndex = 23;
			this->buttonProgressPupils->Text = L"по ученикам";
			this->buttonProgressPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressPupils->UseVisualStyleBackColor = false;
			this->buttonProgressPupils->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonProgressPupils_Click);
			// 
			// buttonProgressTeachers
			// 
			this->buttonProgressTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressTeachers->BackColor = System::Drawing::Color::Transparent;
			this->buttonProgressTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->FlatAppearance->BorderSize = 0;
			this->buttonProgressTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProgressTeachers->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonProgressTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonProgressTeachers->Location = System::Drawing::Point(-1, 352);
			this->buttonProgressTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressTeachers->Name = L"buttonProgressTeachers";
			this->buttonProgressTeachers->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressTeachers->Size = System::Drawing::Size(161, 45);
			this->buttonProgressTeachers->TabIndex = 22;
			this->buttonProgressTeachers->Text = L"по учителям";
			this->buttonProgressTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressTeachers->UseVisualStyleBackColor = false;
			this->buttonProgressTeachers->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonProgressTeachers_Click);
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
			this->buttonMarks->Location = System::Drawing::Point(-1, 264);
			this->buttonMarks->Margin = System::Windows::Forms::Padding(0);
			this->buttonMarks->Name = L"buttonMarks";
			this->buttonMarks->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonMarks->Size = System::Drawing::Size(161, 45);
			this->buttonMarks->TabIndex = 21;
			this->buttonMarks->Text = L"Успеваемость";
			this->buttonMarks->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonMarks->UseVisualStyleBackColor = false;
			this->buttonMarks->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonMarks_Click);
			// 
			// buttonTeachers
			// 
			this->buttonTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->buttonTeachers->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->FlatAppearance->BorderSize = 0;
			this->buttonTeachers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTeachers->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTeachers->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->buttonTeachers->Location = System::Drawing::Point(2, 219);
			this->buttonTeachers->Margin = System::Windows::Forms::Padding(0);
			this->buttonTeachers->Name = L"buttonTeachers";
			this->buttonTeachers->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonTeachers->Size = System::Drawing::Size(156, 45);
			this->buttonTeachers->TabIndex = 20;
			this->buttonTeachers->Text = L"Учителя";
			this->buttonTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTeachers->UseVisualStyleBackColor = false;
			this->buttonTeachers->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonTeachers_Click);
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
			this->buttonPupils->Location = System::Drawing::Point(4, 130);
			this->buttonPupils->Margin = System::Windows::Forms::Padding(0);
			this->buttonPupils->Name = L"buttonPupils";
			this->buttonPupils->Padding = System::Windows::Forms::Padding(6, 0, 0, 0);
			this->buttonPupils->Size = System::Drawing::Size(156, 45);
			this->buttonPupils->TabIndex = 19;
			this->buttonPupils->Text = L"Ученики";
			this->buttonPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPupils->UseVisualStyleBackColor = false;
			this->buttonPupils->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonPupils_Click);
			// 
			// dataGridViewHigh
			// 
			this->dataGridViewHigh->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewHigh->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewHigh->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->SubjectMarks,
					this->MarkToSubject
			});
			this->dataGridViewHigh->Location = System::Drawing::Point(206, 99);
			this->dataGridViewHigh->Name = L"dataGridViewHigh";
			this->dataGridViewHigh->RowHeadersWidth = 51;
			this->dataGridViewHigh->RowTemplate->Height = 24;
			this->dataGridViewHigh->Size = System::Drawing::Size(530, 132);
			this->dataGridViewHigh->TabIndex = 1;
			// 
			// SubjectMarks
			// 
			this->SubjectMarks->HeaderText = L"Предмет";
			this->SubjectMarks->MinimumWidth = 6;
			this->SubjectMarks->Name = L"SubjectMarks";
			// 
			// MarkToSubject
			// 
			this->MarkToSubject->HeaderText = L"Оценка";
			this->MarkToSubject->MinimumWidth = 6;
			this->MarkToSubject->Name = L"MarkToSubject";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(202, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(348, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Предмет с наивысшим средним баллом";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(202, 261);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(354, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Предмет с самой низкой успеваемостью";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(202, 463);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(316, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Общая успеваемость по предметам";
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// dataGridViewLow
			// 
			this->dataGridViewLow->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewLow->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLow->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridViewLow->Location = System::Drawing::Point(206, 301);
			this->dataGridViewLow->Name = L"dataGridViewLow";
			this->dataGridViewLow->RowHeadersWidth = 51;
			this->dataGridViewLow->RowTemplate->Height = 24;
			this->dataGridViewLow->Size = System::Drawing::Size(530, 130);
			this->dataGridViewLow->TabIndex = 23;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Предмет";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Оценка";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewAll
			// 
			this->dataGridViewAll->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewAll->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAll->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn3,
					this->dataGridViewTextBoxColumn4
			});
			this->dataGridViewAll->Location = System::Drawing::Point(206, 501);
			this->dataGridViewAll->Name = L"dataGridViewAll";
			this->dataGridViewAll->RowHeadersWidth = 51;
			this->dataGridViewAll->RowTemplate->Height = 24;
			this->dataGridViewAll->Size = System::Drawing::Size(530, 128);
			this->dataGridViewAll->TabIndex = 24;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Предмет";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Оценка";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// buttonExit
			// 
			this->buttonExit->FlatAppearance->BorderSize = 0;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Location = System::Drawing::Point(1039, 0);
			this->buttonExit->Margin = System::Windows::Forms::Padding(0);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(33, 29);
			this->buttonExit->TabIndex = 25;
			this->buttonExit->Text = L"x";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &ProgressSubjects::buttonExit_Click);
			// 
			// ProgressSubjects
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1071, 663);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->dataGridViewAll);
			this->Controls->Add(this->dataGridViewLow);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewHigh);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"ProgressSubjects";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &ProgressSubjects::ProgressSubjects_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHigh))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAll))->EndInit();
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
private: System::Void ProgressSubjects_Load(System::Object^ sender, System::EventArgs^ e);
};
}
