#pragma once
#include "EqTriangle.h"


ref class Triangle : public EqTriangle
{
public:
	Triangle(Panel^ );
	virtual System::Void SetCoord(vector<PointF>) override;
	virtual System::Void Move(float, float) override;
	virtual System::Int32 Square() override;
};

