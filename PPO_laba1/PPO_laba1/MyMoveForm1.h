#pragma once

#include <cliext/vector>
#include <cliext/algorithm>

namespace PPOlaba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;

	/// <summary>
	/// Summary for MyMoveForm1
	/// </summary>
	public ref class MyMoveForm1 : public System::Windows::Forms::Form
	{
	public:
		MyMoveForm1(void)
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
		~MyMoveForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Accept;
	protected:

	protected:
	private: System::Windows::Forms::Label^  dx;
	private: System::Windows::Forms::Label^  dy;
	private: System::Windows::Forms::TextBox^  dxText;
	private: System::Windows::Forms::TextBox^  dyText;

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
			this->Accept = (gcnew System::Windows::Forms::Button());
			this->dx = (gcnew System::Windows::Forms::Label());
			this->dy = (gcnew System::Windows::Forms::Label());
			this->dxText = (gcnew System::Windows::Forms::TextBox());
			this->dyText = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Accept
			// 
			this->Accept->Location = System::Drawing::Point(83, 87);
			this->Accept->Name = L"Accept";
			this->Accept->Size = System::Drawing::Size(75, 23);
			this->Accept->TabIndex = 0;
			this->Accept->Text = L"Accept";
			this->Accept->UseVisualStyleBackColor = true;
			this->Accept->Click += gcnew System::EventHandler(this, &MyMoveForm1::Accept_Click);
			// 
			// dx
			// 
			this->dx->AutoSize = true;
			this->dx->Location = System::Drawing::Point(22, 21);
			this->dx->MinimumSize = System::Drawing::Size(60, 20);
			this->dx->Name = L"dx";
			this->dx->Size = System::Drawing::Size(61, 20);
			this->dx->TabIndex = 1;
			this->dx->Text = L"сдвиг по X";
			// 
			// dy
			// 
			this->dy->AutoSize = true;
			this->dy->Location = System::Drawing::Point(22, 47);
			this->dy->MinimumSize = System::Drawing::Size(60, 20);
			this->dy->Name = L"dy";
			this->dy->Size = System::Drawing::Size(61, 20);
			this->dy->TabIndex = 2;
			this->dy->Text = L"сдвиг по Y";
			// 
			// dxText
			// 
			this->dxText->Location = System::Drawing::Point(122, 21);
			this->dxText->MaxLength = 4;
			this->dxText->Name = L"dxText";
			this->dxText->Size = System::Drawing::Size(100, 20);
			this->dxText->TabIndex = 3;
			// 
			// dyText
			// 
			this->dyText->Location = System::Drawing::Point(122, 47);
			this->dyText->MaxLength = 4;
			this->dyText->Name = L"dyText";
			this->dyText->Size = System::Drawing::Size(100, 20);
			this->dyText->TabIndex = 4;
			// 
			// MyMoveForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 131);
			this->Controls->Add(this->dyText);
			this->Controls->Add(this->dxText);
			this->Controls->Add(this->dy);
			this->Controls->Add(this->dx);
			this->Controls->Add(this->Accept);
			this->MaximumSize = System::Drawing::Size(275, 170);
			this->MinimumSize = System::Drawing::Size(275, 170);
			this->Name = L"MyMoveForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyMoveForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: 
		pair<float, float> mover;

	public: 
		pair<float, float> EditDialog()
		{
			mover.first = 0;
			mover.second = 0;

			this->ShowDialog();
			return mover;
		}

	private:
		System::Void Accept_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			try
			{
				mover.first = Convert::ToDouble(dxText->Text);
				mover.second = Convert::ToDouble(dyText->Text);
			}
			catch (System::FormatException ^ex)
			{
				mover.first = 0;
				mover.second = 0;
			}

			this->Close();
		}
	};

}
