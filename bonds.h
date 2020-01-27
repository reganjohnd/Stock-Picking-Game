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

	//returns the interest earned on the bond in 2019
	double value() const
	{
		return (bfv - bpp) + (bfv * (bir/1000));
	}

	//returns bond name
	string get_name()
	{
		return name;
	}

	//returns purchase price of bond
	double get_bpp()
	{
		return bpp;
	}

	//returns face value of bond
	int get_bfv()
	{
		return bfv;
	}

	//returns interest rate of bond
	int get_bir()
	{
		return bir / 10;
	}
};