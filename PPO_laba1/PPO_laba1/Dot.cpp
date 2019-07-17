#include "Dot.h"


Dot::Dot(Panel ^form)
{
	oldBrush = Brushes::White;		// по умолчанию

	graph = form->CreateGraphics();
	point.X = 0.0;
	point.Y = 0.0;

	Savepoint.X = 0.0;
	Savepoint.Y = 0.0;
}

Dot::Dot(Panel ^form, float x, float y)
{
	oldBrush = Brushes::White;		// по умолчанию

	graph = form->CreateGraphics();
	point.X = x;
	point.Y = y;

	Savepoint.X = 0.0;
	Savepoint.Y = 0.0;
}

Dot::~Dot()
{
	this->Delete();
}

Dot::!Dot()
{
	this->Delete();
}

System::Void Dot::SetCoord(vector<PointF> vCoord)
{
	if (vCoord.size() == 0)
		throw gcnew FormatException;

	point.X = vCoord[0].X;
	point.Y = vCoord[0].Y;
}

vector<PointF> Dot::GetCoord()
{
	vector<PointF> ret;
	ret.push_back(PointF(point.X, point.Y));
	return ret;
}

System::Void Dot::Draw(Pen ^pen)
{
	this->Delete();		// очистили предыдущий вариант
	graph->DrawLine(pen, point.X, point.Y, point.X+1, point.Y+1);

	Savepoint.X = point.X;
	Savepoint.Y = point.Y;
}

// Savepoint изменяется только если мы что то нарисуем
System::Void Dot::Delete()
{
	// то же, что и Draw с Paint, но белой ручкой
	graph->DrawLine(Pens::White, Savepoint.X, Savepoint.Y, Savepoint.X+1, Savepoint.Y+1);
	//graph->FillLine(Brushes::White, Savepoint.X, Savepoint.Y, Savepoint.X, Savepoint.Y);
}

System::Void Dot::Paint_Over(Brush ^brush)
{
	oldBrush = brush;		// новый цвет

	//this->Delete();
	//graph->FillEllipse(brush, point.X, point.Y, point.X, point.Y);

	Savepoint.X = point.X;
	Savepoint.Y = point.Y;
}

// сдвиг для каждой вершины на один и тот же dx, dy (неважно сколько вершин)
System::Void Dot::Move(float dx, float dy)
{
	this->Delete();
	
	vector<PointF> newcoord;
	newcoord.push_back(PointF(point.X + dx, point.Y + dy));
	this->SetCoord(newcoord);

	this->Draw(Pens::Black);
	//this->Paint_Over(oldBrush);
}

System::Void Dot::Turn(Int32 angle)
{
	// для точки нет поворота

	//this->Delete();
	//this->SetCoord(vector<PointF>(point.X * ...angle, point.Y * ...angle));
	//this->Draw(Pens::Black);		// коордианты сохранятся здесь
	//this->Paint_Over(brush);
}

System::Int32 Dot::Square()
{
	// не важно, что нарисовано, площадь считается для той фигуры, которую мы ввели последней 
	return 0;
}
