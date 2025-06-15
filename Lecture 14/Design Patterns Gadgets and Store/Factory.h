#pragma once
#include"Laptop.h"
#include"Computer.h"
#include"Gadget.h"

Gadget* createProduct(const MyString& type, const MyString& model, double price, double weight = 0);