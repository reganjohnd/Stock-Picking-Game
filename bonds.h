#pragma once
#include "securities.h"
#include <string>
#include <iostream>
using namespace std;

class bonds : public securities
{
private:
	double bfv;
	double bpp;
	double bir;
	string name;

public:
	bonds() : bfv{1}, bpp{1}, bir{111}
	{}

	bonds(string name, double bondFaceValue, double bondPurchasePrice, double bondInterestrate)
		: name{name}, bfv{bondFaceValue}, bpp{bondPurchasePrice}, bir{bondInterestrate}
	{}

	double value() const
	{
		return (bfv - bpp) + (bfv * (bir/1000));
	}

	string get_name()
	{
		return name;
	}

	double get_bpp()
	{
		return bpp;
	}
};