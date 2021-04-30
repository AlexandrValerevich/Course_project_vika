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
	public ref class ProgressTeachers : public System::Windows::Forms::Form
	{
	public:
		ProgressTeachers(void)
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
		~ProgressTeachers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridViewHigh;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SurnameTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PatronymicTeacher;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AverageMark;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridViewLow;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridViewAll;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::Button^ buttonSubjects;
	private: System::Windows::Forms::Button^ buttonProgress;
	private: System::Windows::Forms::Button^ buttonProgressClasses;
	private: System::Windows::Forms::Button^ buttonProgressSubjects;
	private: System::Windows::Forms::Button^ buttonProgressPupils;
	private: System::Windows::Forms::Button^ buttonProgressTeachers;
	private: System::Windows::Forms::Button^ buttonMarks;
	private: System::Windows::Forms::Button^ buttonTeachers;
	private: System::Windows::Forms::Button^ buttonPupils;
	private: System::Windows::Forms::Button^ buttonExit;

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
			this->SurnameTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PatronymicTeacher = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AverageMark = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewLow = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewAll = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHigh))->BeginInit();
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
			this->buttonSubjects->TabIndex = 18;
			this->buttonSubjects->Text = L"Предметы";
			this->buttonSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonSubjects->UseVisualStyleBackColor = false;
			this->buttonSubjects->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonSubjects_Click);
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
			this->buttonProgress->TabIndex = 17;
			this->buttonProgress->Text = L"Рейтинг";
			this->buttonProgress->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgress->UseVisualStyleBackColor = false;
			this->buttonProgress->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonProgress_Click);
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
			this->buttonProgressClasses->Location = System::Drawing::Point(-1, 442);
			this->buttonProgressClasses->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressClasses->Name = L"buttonProgressClasses";
			this->buttonProgressClasses->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressClasses->Size = System::Drawing::Size(161, 45);
			this->buttonProgressClasses->TabIndex = 16;
			this->buttonProgressClasses->Text = L"по классам";
			this->buttonProgressClasses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressClasses->UseVisualStyleBackColor = false;
			this->buttonProgressClasses->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonProgressClasses_Click);
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
			this->buttonProgressSubjects->Location = System::Drawing::Point(-3, 487);
			this->buttonProgressSubjects->Margin = System::Windows::Forms::Padding(0);
			this->buttonProgressSubjects->Name = L"buttonProgressSubjects";
			this->buttonProgressSubjects->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->buttonProgressSubjects->Size = System::Drawing::Size(161, 45);
			this->buttonProgressSubjects->TabIndex = 15;
			this->buttonProgressSubjects->Text = L"по предметам";
			this->buttonProgressSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressSubjects->UseVisualStyleBackColor = false;
			this->buttonProgressSubjects->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonProgressSubjects_Click);
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
			this->buttonProgressPupils->TabIndex = 14;
			this->buttonProgressPupils->Text = L"по ученикам";
			this->buttonProgressPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressPupils->UseVisualStyleBackColor = false;
			this->buttonProgressPupils->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonProgressPupils_Click);
			// 
			// buttonProgressTeachers
			// 
			this->buttonProgressTeachers->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonProgressTeachers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(112)));
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
			this->buttonProgressTeachers->TabIndex = 13;
			this->buttonProgressTeachers->Text = L"по учителям";
			this->buttonProgressTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonProgressTeachers->UseVisualStyleBackColor = false;
			this->buttonProgressTeachers->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonProgressTeachers_Click);
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
			this->buttonMarks->TabIndex = 12;
			this->buttonMarks->Text = L"Успеваемость";
			this->buttonMarks->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonMarks->UseVisualStyleBackColor = false;
			this->buttonMarks->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonMarks_Click);
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
			this->buttonTeachers->TabIndex = 11;
			this->buttonTeachers->Text = L"Учителя";
			this->buttonTeachers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTeachers->UseVisualStyleBackColor = false;
			this->buttonTeachers->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonTeachers_Click);
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
			this->buttonPupils->TabIndex = 10;
			this->buttonPupils->Text = L"Ученики";
			this->buttonPupils->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPupils->UseVisualStyleBackColor = false;
			this->buttonPupils->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonPupils_Click);
			// 
			// dataGridViewHigh
			// 
			this->dataGridViewHigh->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewHigh->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewHigh->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->SurnameTeacher,
					this->NameTeacher, this->PatronymicTeacher, this->Subject, this->AverageMark
			});
			this->dataGridViewHigh->Location = System::Drawing::Point(202, 56);
			this->dataGridViewHigh->Name = L"dataGridViewHigh";
			this->dataGridViewHigh->RowHeadersWidth = 51;
			this->dataGridViewHigh->RowTemplate->Height = 24;
			this->dataGridViewHigh->Size = System::Drawing::Size(836, 88);
			this->dataGridViewHigh->TabIndex = 1;
			// 
			// SurnameTeacher
			// 
			this->SurnameTeacher->HeaderText = L"Фамилия";
			this->SurnameTeacher->MinimumWidth = 6;
			this->SurnameTeacher->Name = L"SurnameTeacher";
			// 
			// NameTeacher
			// 
			this->NameTeacher->HeaderText = L"Имя";
			this->NameTeacher->MinimumWidth = 6;
			this->NameTeacher->Name = L"NameTeacher";
			// 
			// PatronymicTeacher
			// 
			this->PatronymicTeacher->HeaderText = L"Отчество";
			this->PatronymicTeacher->MinimumWidth = 6;
			this->PatronymicTeacher->Name = L"PatronymicTeacher";
			// 
			// Subject
			// 
			this->Subject->HeaderText = L"Предмет";
			this->Subject->MinimumWidth = 6;
			this->Subject->Name = L"Subject";
			// 
			// AverageMark
			// 
			this->AverageMark->HeaderText = L"Оценка";
			this->AverageMark->MinimumWidth = 6;
			this->AverageMark->Name = L"AverageMark";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(208, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(362, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Учитель с самой высокой успеваемостью";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(208, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(348, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Учитель с самой низкой успеваемостью";
			// 
			// dataGridViewLow
			// 
			this->dataGridViewLow->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewLow->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLow->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridViewLow->Location = System::Drawing::Point(202, 196);
			this->dataGridViewLow->Name = L"dataGridViewLow";
			this->dataGridViewLow->RowHeadersWidth = 51;
			this->dataGridViewLow->RowTemplate->Height = 24;
			this->dataGridViewLow->Size = System::Drawing::Size(836, 96);
			this->dataGridViewLow->TabIndex = 4;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Фамилия";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Отчество";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Предмет";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Оценка";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(212, 311);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(287, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Успеваемость по всем учителям";
			// 
			// dataGridViewAll
			// 
			this->dataGridViewAll->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewAll->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAll->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn6,
					this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10
			});
			this->dataGridViewAll->Location = System::Drawing::Point(202, 350);
			this->dataGridViewAll->Name = L"dataGridViewAll";
			this->dataGridViewAll->RowHeadersWidth = 51;
			this->dataGridViewAll->RowTemplate->Height = 24;
			this->dataGridViewAll->Size = System::Drawing::Size(836, 214);
			this->dataGridViewAll->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Фамилия";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Отчество";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"Предмет";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"Оценка";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			// 
			// buttonExit
			// 
			this->buttonExit->FlatAppearance->BorderSize = 0;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Location = System::Drawing::Point(1039, 0);
			this->buttonExit->Margin = System::Windows::Forms::Padding(0);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(33, 29);
			this->buttonExit->TabIndex = 21;
			this->buttonExit->Text = L"x";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &ProgressTeachers::buttonExit_Click);
			// 
			// ProgressTeachers
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1071, 663);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->dataGridViewAll);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridViewLow);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewHigh);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"ProgressTeachers";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &ProgressTeachers::ProgressTeachers_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHigh))->EndInit();
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
private: System::Void ProgressTeachers_Load(System::Object^ sender, System::EventArgs^ e);
};
}
