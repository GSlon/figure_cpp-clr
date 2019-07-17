#pragma once

#include <cliext/algorithm>
#include <cliext/vector>

using namespace System;
using namespace cliext;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


// ���� ������ - ���� ������
ref class Dot
{
protected:
	PointF point, Savepoint;	// SavePoint �������� ��� ������ Draw (Delete �������, ������
								//											���� ����� ����������)
	Graphics ^graph;	// '���������' �������, �� ������� ����� ��������
	Brush ^oldBrush;		// ��� move ���������

public:
	Dot(Panel^);
	Dot(Panel^, float, float);
	~Dot();
	!Dot();

	virtual System::Void SetCoord(vector<PointF>);
	virtual vector<PointF> GetCoord();

	virtual System::Void Draw(Pen^);
	virtual System::Void Delete();
	virtual System::Void Paint_Over(Brush^);
	virtual System::Void Move(float, float);
	virtual System::Void Turn(Int32);
	virtual System::Int32 Square();

};

