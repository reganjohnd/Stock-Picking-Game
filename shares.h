#pragma once
#include "securities.h"
#include <string>
#include <iostream>
#include "variables.h"
#include "bonds.h"
using namespace std;

class shares : public securities
{
private:
	double ssp;
	double esp;
	string name;

public:

	shares() : ssp{1}, esp{1}
	{}

	shares(string name, double starting_sp, double ending_sp)
		: name{name}, ssp{starting_sp}, esp{ending_sp}
	{}

	double value() const
	{
		return esp - ssp;
	}

	string get_name()
	{
		return name;
	}

	double get_ssp()
	{
		return ssp;
	}

	double get_esp()
	{
		return esp;
	}
};