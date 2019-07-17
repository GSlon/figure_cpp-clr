#include "EqTriangle.h"


EqTriangle::EqTriangle(Panel ^form) : Section(form)
{
	point3.X = 0.0;
	point3.Y = 0.0;

	Savepoint3.X = 0.0;
	Savepoint3.Y = 0.0;
}

EqTriangle::~EqTriangle()
{
	this->Delete();
}

EqTriangle::!EqTriangle()
{
	this->Delete();
}

System::Void EqTriangle::SetCoord(vector<PointF> vPoints)
{
	if (vPoints.size() < 2)
		throw gcnew FormatException;

	point.X = vPoints[0].X;
	point.Y = vPoints[0].Y;
	point2.X = vPoints[1].X;
	point2.Y = vPoints[1].Y;
	
	// ввели две точки - третью дописываем 
	float d = Math::Sqrt(Math::Pow(point2.X - point.X, 2) + Math::Pow(point2.Y - point.Y, 2));
	float dx = point2.X - point.X;
	float dy = point2.Y - point.Y;
	
	point3.X = point.X + dx * Math::Cos(Math::PI / 3) + dy * Math::Sin(Math::PI / 3);
	point3.Y = point.Y - dx * Math::Sin(Math::PI / 3) + dy * Math::Cos(Math::PI / 3);
}

vector<PointF> EqTriangle::GetCoord()
{
	vector<PointF> ret;
	ret.push_back(PointF(point.X, point.Y));
	ret.push_back(PointF(point2.X, point2.Y));
	ret.push_back(PointF(point3.X, point3.Y));

	return ret;
}

System::Void EqTriangle::Draw(Pen ^pen)
{
	this->Delete();

	cli::array<PointF> ^arrPoints = {point, point2, point3};
	graph->FillPolygon(oldBrush, arrPoints);
	graph->DrawPolygon(pen, arrPoints);

	Savepoint.X = point.X;
	Savepoint.Y = point.Y;
	Savepoint2.X = point2.X;
	Savepoint2.Y = point2.Y;
	Savepoint3.X = point3.X;
	Savepoint3.Y = point3.Y;
}

System::Void EqTriangle::Delete()
{
	cli::array<PointF> ^arrPoints = { Savepoint, Savepoint2, Savepoint3 };
	graph->DrawPolygon(Pens::White, arrPoints);
	graph->FillPolygon(Brushes::White, arrPoints);		// удаляем закраску
}

System::Void EqTriangle::Paint_Over(Brush ^brush)
{
	oldBrush = brush;

	cli::array<PointF> ^arrPoints = { point, point2, point3 };
	graph->FillPolygon(brush, arrPoints);
	graph->DrawPolygon(Pens::Black, arrPoints);		//потому что Fill портит контур

	Savepoint.X = point.X;
	Savepoint.Y = point.Y;
	Savepoint2.X = point2.X;
	Savepoint2.Y = point2.Y;
	Savepoint3.X = point3.X;
	Savepoint3.Y = point3.Y;	
}

System::Void EqTriangle::Move(float dx, float dy)
{
	this->Delete();

	vector<PointF> newcoord;
	newcoord.push_back(PointF(point.X + dx, point.Y + dy));
	newcoord.push_back(PointF(point2.X + dx, point2.Y + dy));

	this->SetCoord(newcoord);
	this->Draw(Pens::Black);
	this->Paint_Over(oldBrush);
}

System::Void EqTriangle::Turn(Int32 angle) 
{
	this->Delete();
	
	vector<PointF> ret;
	ret.push_back(PointF(point.X, point.Y));
	ret.push_back(PointF(point.X + (point2.X - point.X) * Math::Cos(angle * Math::PI / 180) + (point2.Y - point.Y) * Math::Sin(angle * Math::PI / 180),
		point.Y - (point2.X - point.X) * Math::Sin(angle * Math::PI / 180) + (point2.Y - point.Y) * Math::Cos(angle * Math::PI / 180)));
	ret.push_back(PointF(point.X + (point3.X - point.X) * Math::Cos(angle * Math::PI / 180) + (point3.Y - point.Y) * Math::Sin(angle * Math::PI / 180),
		point.Y - (point3.X - point.X) * Math::Sin(angle * Math::PI / 180) + (point3.Y - point.Y) * Math::Cos(angle * Math::PI / 180)));

	this->SetCoord(ret);
	this->Draw(Pens::Black);		// коордианты сохранятся здесь
	this->Paint_Over(oldBrush);
}

System::Int32 EqTriangle::Square()
{
	float d = Math::Sqrt(Math::Pow(point2.X - point.X, 2) + Math::Pow(point2.Y - point.Y, 2));
	return Convert::ToInt32(pow(d , 2) * Math::Sqrt(3) / 4);
}
