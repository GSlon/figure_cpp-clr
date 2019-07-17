#include "Triangle.h"


Triangle::Triangle(Panel ^form) : EqTriangle(form)
{
}

System::Void Triangle::SetCoord(vector<PointF> vPoints)
{
	if (vPoints.size() < 3)
		throw gcnew FormatException;

	point.X = vPoints[0].X;
	point.Y = vPoints[0].Y;
	point2.X = vPoints[1].X;
	point2.Y = vPoints[1].Y;
	point3.X = vPoints[2].X;
	point3.Y = vPoints[2].Y;
}

System::Void Triangle::Move(float dx, float dy)
{
	this->Delete();

	vector<PointF> newcoord;
	newcoord.push_back(PointF(point.X + dx, point.Y + dy));
	newcoord.push_back(PointF(point2.X + dx, point2.Y + dy));
	newcoord.push_back(PointF(point3.X + dx, point3.Y + dy));

	this->SetCoord(newcoord);
	this->Draw(Pens::Black);
	this->Paint_Over(oldBrush);
}

System::Int32 Triangle::Square()
{
	// вычисляем длину трех сторон
	float a = Math::Sqrt(Math::Pow(point2.X - point.X, 2) + Math::Pow(point2.Y - point.Y, 2));
	float b = Math::Sqrt(Math::Pow(point3.X - point.X, 2) + Math::Pow(point3.Y - point.Y, 2));
	float c = Math::Sqrt(Math::Pow(point3.X - point2.X, 2) + Math::Pow(point3.Y - point2.Y, 2));

	// используем формулу Герона
	float p = (a + b + c) / 2;		//полупериметр
	return Convert::ToInt32(Math::Sqrt(p * (p - a) * (p - b) * (p - c)));
}


