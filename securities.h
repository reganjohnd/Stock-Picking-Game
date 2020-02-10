#pragma once
#include <string>
using namespace std;

class securities
{
public:
	//calculates the value of the security in the derived classes
	virtual double value() const = 0;

};