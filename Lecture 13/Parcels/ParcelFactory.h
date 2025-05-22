#pragma once
#include "Parcel.h"
#include "CircleParcel.h"
#include "RectangleParcel.h"
#include "TriangleParcel.h"

Parcel* factory(const char* str);