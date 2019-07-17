#pragma once

#include "MyTurnForm.h"
#include "MyMoveForm1.h"
#include "Dot.h"
#include "Section.h"
#include "EqTriangle.h"
#include "Triangle.h"
#include <cliext/vector>

namespace PPOlaba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//
			angle = 0;
			color = Brushes::White;
			figure = gcnew Dot(panel);
			points.clear();
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  figureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dotToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  triangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  equilateralTriangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  turnToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  squareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  moveToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel;


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
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->figureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dotToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->triangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->equilateralTriangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->turnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->squareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->figureToolStripMenuItem,
					this->colorToolStripMenuItem, this->deleteToolStripMenuItem, this->turnToolStripMenuItem, this->squareToolStripMenuItem, this->moveToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menu->Size = System::Drawing::Size(714, 24);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menu";
			// 
			// figureToolStripMenuItem
			// 
			this->figureToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->dotToolStripMenuItem,
					this->sectionToolStripMenuItem, this->triangleToolStripMenuItem, this->equilateralTriangleToolStripMenuItem
			});
			this->figureToolStripMenuItem->Name = L"figureToolStripMenuItem";
			this->figureToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->figureToolStripMenuItem->Text = L"Figure";
			// 
			// dotToolStripMenuItem
			// 
			this->dotToolStripMenuItem->Name = L"dotToolStripMenuItem";
			this->dotToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->dotToolStripMenuItem->Text = L"Dot";
			this->dotToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::FigureToolStripMenuItem_Click);
			// 
			// sectionToolStripMenuItem
			// 
			this->sectionToolStripMenuItem->Name = L"sectionToolStripMenuItem";
			this->sectionToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->sectionToolStripMenuItem->Text = L"Section";
			this->sectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::FigureToolStripMenuItem_Click);
			// 
			// triangleToolStripMenuItem
			// 
			this->triangleToolStripMenuItem->Name = L"triangleToolStripMenuItem";
			this->triangleToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->triangleToolStripMenuItem->Text = L"Triangle";
			this->triangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::FigureToolStripMenuItem_Click);
			// 
			// equilateralTriangleToolStripMenuItem
			// 
			this->equilateralTriangleToolStripMenuItem->Name = L"equilateralTriangleToolStripMenuItem";
			this->equilateralTriangleToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->equilateralTriangleToolStripMenuItem->Text = L"Equilateral triangle";
			this->equilateralTriangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::FigureToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->colorToolStripMenuItem->Text = L"Color";
			this->colorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::colorToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
			// 
			// turnToolStripMenuItem
			// 
			this->turnToolStripMenuItem->Name = L"turnToolStripMenuItem";
			this->turnToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->turnToolStripMenuItem->Text = L"Turn";
			this->turnToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::turnToolStripMenuItem_Click);
			// 
			// squareToolStripMenuItem
			// 
			this->squareToolStripMenuItem->Name = L"squareToolStripMenuItem";
			this->squareToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->squareToolStripMenuItem->Text = L"Square";
			this->squareToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::squareToolStripMenuItem_Click);
			// 
			// moveToolStripMenuItem
			// 
			this->moveToolStripMenuItem->Name = L"moveToolStripMenuItem";
			this->moveToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->moveToolStripMenuItem->Text = L"Move";
			this->moveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::moveToolStripMenuItem_Click);
			// 
			// panel
			// 
			this->panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel->AutoScroll = true;
			this->panel->AutoSize = true;
			this->panel->BackColor = System::Drawing::SystemColors::Window;
			this->panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel->Location = System::Drawing::Point(0, 24);
			this->panel->Margin = System::Windows::Forms::Padding(0);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(714, 487);
			this->panel->TabIndex = 1;
			this->panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_Paint);
			this->panel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 511);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->menu);
			this->MainMenuStrip = this->menu;
			this->MaximumSize = System::Drawing::Size(730, 550);
			this->MinimumSize = System::Drawing::Size(730, 550);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Painter";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	// our code starts here
	
	private: 
		Brush ^color;
		Int32 angle;
		vector<PointF> points;	// храним точки
		Dot ^figure;


	private: System::Void colorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ColorDialog Dcolor;
		Dcolor.ShowDialog();
		//MessageBox::Show(Dcolor.Color.ToString());

		Brush ^newcolor = gcnew SolidBrush(Dcolor.Color);
		figure->Paint_Over(newcolor);
		color = newcolor;

		this->Paint_Coord_Lines();
	}

	private: System::Void squareToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//MessageBox::Show("square");
		MessageBox::Show(Convert::ToString(figure->Square()));
	}
	
	private: System::Void turnToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		MyTurnForm Turnform;
		angle = Turnform.EditDialog();
		figure->Turn(angle);

		this->Paint_Coord_Lines();
		// MessageBox::Show(Convert::ToString(my));
	}

	private: System::Void FigureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^str = sender->ToString();

		if (str == "Dot")
		{
			delete figure;		// вызываем деструктор для удаления уже нарисованного
			figure = gcnew Dot(panel);
		}
		else 
			if (str == "Section")
			{
				delete figure;
				figure = gcnew Section(panel);
			}
		else 
			if (str == "Triangle")
			{
				delete figure;
				figure = gcnew Triangle(panel);
			}
		else
			if (str == "Equilateral triangle")
			{
				delete figure;
				figure = gcnew EqTriangle(panel);
			}
		
		color = Brushes::White;
		this->Paint_Coord_Lines();
		//MessageBox::Show(sender->ToString());
	}
	
	private: System::Void panel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		// если точек хватает - рисуем, нет - продолжаем копить
		points.push_back(PointF(e->X, e->Y));
		
		String ^str = figure->GetType()->ToString();
		int counter = points.size();

		if (((str == "Dot") && (counter == 1)) ||
			((str == "Section") && (counter == 2)) ||
				(str == "Triangle") && (counter == 3) ||
					(str == "EqTriangle") && (counter == 2)) 
		{
		
			figure->SetCoord(points);
			figure->Draw(Pens::Black);

			// координатные оси поверх фигуры
			this->Paint_Coord_Lines();

			points.clear();		// будем собирать точки заново
		}

		if (counter == 4)
			points.clear();		// смогли обойти предыдущий if
	}

	private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		figure->Delete();
		this->Paint_Coord_Lines();
	}
	
	// предлагает пользователю ввести коэффициент сдвига координат по X и по Y			 
	private: System::Void moveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		// получаем сдвиг по x и по у
		MyMoveForm1 MoveForm;
		pair<float, float> mover = MoveForm.EditDialog();

		figure->Move(mover.first, (-1) * mover.second);		// есть оси - Y направлен вверх
		this->Paint_Coord_Lines();
	}

	private: System::Void panel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		figure->Draw(Pens::Black);
		figure->Paint_Over(color);

		this->Paint_Coord_Lines();
	}
	
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
	}

	private: System::Void Paint_Coord_Lines()
	{
		this->panel->CreateGraphics()->DrawLine(Pens::Black, Point(0, this->panel->Height / 2), Point(this->panel->Width, this->panel->Height / 2));
		this->panel->CreateGraphics()->DrawLine(Pens::Black, Point(this->panel->Width / 2, 0), Point(this->panel->Width / 2, this->panel->Height));
	}
};
}
