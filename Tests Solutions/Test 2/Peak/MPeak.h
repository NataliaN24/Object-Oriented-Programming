#pragma once
#include "Peak.h"

class MPeak :public Peak
{
	double number;

public:
	MPeak(const char* name, double h, double number);
	MPeak();
	void setNumber(double newNum);
	double getNumber()const;

	virtual void printPeakName()const override;
	virtual Peak* clone()const override;

	virtual bool twoPeaksNear(const Peak* other)const override;
	virtual bool nearMpeak(const MPeak* mpeak)const override;
	virtual bool nearTPeak(const TPeak* tpeak)const override;

};

