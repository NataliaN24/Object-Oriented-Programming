#pragma once
#include"Peak.h"
#include"TPeak.h"
#include"MPeak.h"
 
enum class PeakType {
	Tpeak,
	MPeak
};

Peak* peak(PeakType type);