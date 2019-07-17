#pragma once

#include "Section.h"
#include <cliext/algorithm>
#include <cliext/list>
#include <algorithm>

using namespace System::Drawing::Drawing2D;
using namespace cli;

ref class EqTriangle : public Section
{
protected:
	PointF point3, Savepoint3;

public:
	EqTriangle(Panel^ );
	~EqTriangle();
	!EqTriangle();

	virtual System::Void SetCoord(vector<PointF>) override;
	virtual vector<PointF> GetCoord() override;

	virtual System::Void Draw(Pen^ ) override;
	virtual System::Void Delete() override;
	virtual System::Void Paint_Over(Brush^ ) override;
	virtual System::Void Move(float, float) override;		// координаты сдвига
	virtual System::Void Turn(Int32) override;
	virtual System::Int32 Square() override;
};

