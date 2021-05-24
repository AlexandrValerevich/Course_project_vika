#pragma once

namespace schoolcourseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyFormAbout : public System::Windows::Forms::Form
	{
	public:
		MyFormAbout(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormAbout(System::Windows::Forms::Form^ parent)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			this->Owner = parent;
			parent->Hide();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyFormAbout()
		{
			if (components)
			{
				delete components;
			}

			this->Owner->Show();
		}
	private: System::Windows::Forms::RichTextBox^ richTextBoxAbout;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBoxAbout = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBoxAbout
			// 
			this->richTextBoxAbout->Cursor = System::Windows::Forms::Cursors::Default;
			this->richTextBoxAbout->Location = System::Drawing::Point(13, 13);
			this->richTextBoxAbout->Name = L"richTextBoxAbout";
			this->richTextBoxAbout->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBoxAbout->Size = System::Drawing::Size(814, 450);
			this->richTextBoxAbout->TabIndex = 0;
			this->richTextBoxAbout->Text = L"ќб авторе:\n\n\n\nќб программе:\n\n";
			// 
			// MyFormAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 475);
			this->Controls->Add(this->richTextBoxAbout);
			this->Font = (gcnew System::Drawing::Font(L"Open Sans", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyFormAbout";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
