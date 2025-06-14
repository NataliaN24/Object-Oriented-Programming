#pragma once
#include"Peak.h"

class TPeak:public Peak
{
	char* nameTPeak;

	void copyFrom(const TPeak& other);
	void free();
public:
	TPeak();
	TPeak(const char* mountainName, double h, const char* peakName);
	TPeak(const TPeak& other);
	TPeak& operator=(const TPeak& other);
	~TPeak();

	void setPeakName(const char* newName);
	const char* getPeakName()const;

	virtual void printPeakName()const override;
	virtual Peak* clone()const override;
	virtual bool twoPeaksNear(const Peak* other)const override;
	virtual bool nearMpeak(const MPeak* mpeak)const override;
	virtual bool nearTPeak(const TPeak* tpeak)const override;
};

