#pragma once

namespace PPOlaba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyTurnForm
	/// </summary>
	public ref class MyTurnForm : public System::Windows::Forms::Form
	{
	public:
		MyTurnForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyTurnForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  TurnLabel;
	protected:

	private: System::Windows::Forms::TextBox^  TurnText;
	private: System::Windows::Forms::Button^  ConfButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TurnLabel = (gcnew System::Windows::Forms::Label());
			this->TurnText = (gcnew System::Windows::Forms::TextBox());
			this->ConfButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// TurnLabel
			// 
			this->TurnLabel->AutoSize = true;
			this->TurnLabel->Location = System::Drawing::Point(38, 26);
			this->TurnLabel->MaximumSize = System::Drawing::Size(40, 20);
			this->TurnLabel->MinimumSize = System::Drawing::Size(40, 20);
			this->TurnLabel->Name = L"TurnLabel";
			this->TurnLabel->Size = System::Drawing::Size(40, 20);
			this->TurnLabel->TabIndex = 0;
			this->TurnLabel->Text = L"Angle:";
			this->TurnLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TurnText
			// 
			this->TurnText->Location = System::Drawing::Point(84, 26);
			this->TurnText->MaximumSize = System::Drawing::Size(128, 20);
			this->TurnText->MaxLength = 3;
			this->TurnText->MinimumSize = System::Drawing::Size(128, 20);
			this->TurnText->Name = L"TurnText";
			this->TurnText->Size = System::Drawing::Size(128, 20);
			this->TurnText->TabIndex = 1;
			// 
			// ConfButton
			// 
			this->ConfButton->Location = System::Drawing::Point(84, 56);
			this->ConfButton->Name = L"ConfButton";
			this->ConfButton->Size = System::Drawing::Size(75, 23);
			this->ConfButton->TabIndex = 2;
			this->ConfButton->Text = L"Confirm";
			this->ConfButton->UseVisualStyleBackColor = true;
			this->ConfButton->Click += gcnew System::EventHandler(this, &MyTurnForm::ConfButton_Click);
			// 
			// MyTurnForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 91);
			this->Controls->Add(this->ConfButton);
			this->Controls->Add(this->TurnText);
			this->Controls->Add(this->TurnLabel);
			this->MaximumSize = System::Drawing::Size(275, 130);
			this->MinimumSize = System::Drawing::Size(275, 130);
			this->Name = L"MyTurnForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyTurnForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Int32 angle;

	public: Int32 EditDialog()
	{
		angle = 0;		// по умолчанию
		
		this->ShowDialog();
		return angle;
	}

	private: System::Void ConfButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			angle = Convert::ToInt32(TurnText->Text);		//сохраняем значение угла
		}
		catch (System::FormatException ^ex)
		{
			angle = 0;
		}
		
		this->Close();
	}

	};
}
