#pragma once
#include "securities.h"
#include <string>
#include <iostream>
#include "variables.h"
#include "bonds.h"
using namespace std;

class shares : public securities
{
public:
	double ssp;
	double esp;
	string name;


	shares() : ssp{1}, esp{1}
	{}

	shares(string name, double starting_sp, double ending_sp)
		: name{name}, ssp{starting_sp}, esp{ending_sp}
	{}

	//returns the change in share price in terms of dollars from 1 Jan 2019 to 31 Dec 2019
	double value() const
	{
		return esp - ssp;
	}

	//returns name of share
	string get_name()
	{
		return name;
	}

	//returns the share price at 1 Jan 2019
	double get_ssp()
	{
		return ssp;
	}


	//returns share price on 31 Dec 2019
	double get_esp()
	{
		return esp;
	}
};