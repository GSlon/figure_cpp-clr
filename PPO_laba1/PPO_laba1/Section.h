#pragma once

#include "Dot.h"
#include <cliext/algorithm>
#include <cliext/vector>
#include <cmath>

using namespace System;
using namespace cliext;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


ref class Section : public Dot
{
protected:
	PointF point2, Savepoint2;

public:
	Section(Panel^ );
	Section(Panel^ , float, float, float, float);
	~Section();
	!Section();

	virtual System::Void SetCoord(vector<PointF>) override;
	virtual vector<PointF> GetCoord() override;

	virtual System::Void Draw(Pen^ ) override;
	virtual System::Void Delete() override;
	virtual System::Void Paint_Over(Brush^ ) override;
	virtual System::Void Move(float, float) override;		// координаты сдвига
	virtual System::Void Turn(Int32) override;
	virtual System::Int32 Square() override;
};

