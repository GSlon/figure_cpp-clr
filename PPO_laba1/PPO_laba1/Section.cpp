#include "Section.h"

Section::Section(Panel ^form) : Dot(form)
{
	point2.X = 0.0;
	point2.Y = 0.0;

	Savepoint2.X = 0.0;
	Savepoint2.Y = 0.0;
}

Section::Section(Panel ^form, float X1, float Y1, float X2, float Y2) : Dot(form, X1, Y1)
{
	point2.X = X2;
	point2.Y = Y2;

	Savepoint2.X = 0.0;
	Savepoint2.Y = 0.0;
}

Section::~Section()
{
	this->Delete();
}

Section::!Section()
{
	this->Delete();
}

System::Void Section::SetCoord(vector<PointF> vPoints)
{
	if (vPoints.size() < 2)
		throw gcnew FormatException;

	point.X = vPoints[0].X;
	point.Y = vPoints[0].Y;
	point2.X = vPoints[1].X;
	point2.Y = vPoints[1].Y;
}

vector<PointF> Section::GetCoord()
{
	vector<PointF> ret;
	ret.push_back(PointF(point.X, point.Y));
	ret.push_back(PointF(point2.X, point2.Y));

	return ret;
}

System::Void Section::Draw(Pen ^pen)
{
	this->Delete();
	graph->DrawLine(pen, point.X, point.Y, point2.X, point2.Y);

	Savepoint.X = point.X;
	Savepoint.Y = point.Y;
	Savepoint2.X = point2.X;
	Savepoint2.Y = point2.Y;
}

System::Void Section::Delete()
{
	graph->DrawLine(Pens::White, Savepoint.X, Savepoint.Y, Savepoint2.X, Savepoint2.Y);
}

System::Void Section::Paint_Over(Brush ^)
{
	// для линии не будет
}

System::Void Section::Move(float dx, float dy)
{
	this->Delete();

	vector<PointF> newcoord;
	newcoord.push_back(PointF(point.X + dx, point.Y + dy));
	newcoord.push_back(PointF(point2.X + dx, point2.Y + dy));
	this->SetCoord(newcoord);

	this->Draw(Pens::Black);
}

System::Void Section::Turn(Int32 angle)
{
	this->Delete();

	vector<PointF> ret;
	ret.push_back(PointF(point.X, point.Y));
	ret.push_back(PointF(point.X + (point2.X - point.X) * Math::Cos(angle * Math::PI /180) + (point2.Y - point.Y) * Math::Sin(angle * Math::PI /180),
				point.Y - (point2.X - point.X) * Math::Sin(angle * Math::PI / 180) + (point2.Y - point.Y) * Math::Cos(angle * Math::PI / 180)));

	this->SetCoord(ret);
	this->Draw(Pens::Black);		// коордианты сохранятся здесь
}

System::Int32 Section::Square()
{
	return 0;
}
