#pragma once
#include"shares.h"
#include "securities.h"
#include "bonds.h"
using namespace std;
#include <iostream>
#include"variables.h"
#include <string>


//prints message that you have insufficient funds available
void i_funds()
{
	cout << "You have insifficent funds." << endl;
}

//quicker way to print this statement with a word of my choice
void ns(string security)
{
	cout << "Number of "<<security<<" to purchase: " << endl;
}	

//purchasing shares
void buy_s(int x)
{
	cout << "You chose "<<sn[x]<<"\nCurrent share price: $" << ssp[x] << endl;
	ns("shares");
	cin >> bs[x];
	tsv[x] = bs[x] * ssp[x];
	if (tsv[x] > funds_remaining)
	{
		i_funds();
	}
	else
	{
		cout << "\n\nTotal value of purchase: $" << tsv[x] << endl;
		funds_remaining = funds_remaining - tsv[x];
		cout << "\nFunds remaining: $" << funds_remaining << endl;
	}
}

//purchasing bonds
void buy_b(int x)
{
	cout << "You chose " << bn[x] << "Current purchase price: $" << bpp[x];
	ns("bonds");
	cin >> bb[x];
	tbv[x] = bb[x] * bpp[x];
	if (tbv[x] > funds_remaining)
	{
		i_funds();
	}
	else
	{
		cout << "\n\nTotal value of purchase: $" << tbv[x] << endl;
		funds_remaining = funds_remaining - tbv[x];
		cout << "\nFunds remaining: $" << funds_remaining << endl;
	}
}

	//provides a summary of all shares and bonds purchased by the user
	void purchase_summary()
	{
		
		cout << "Purchase Summary" << endl;
		cout << "SHARES" << endl;
		cout << "------------------------"<<"\n\n";
		for (int i = 0; i < 5; i++)
		{
			if (bs[i] > 0)
			{
				cout << i + 1 << ". " << sn[i] << "\t" << bs[i];
				if (bs[i] > 1)
				{
					cout << " Shares @ $";
				}
				else
				{
					cout << " Share @ $";
				}
				cout << ssp[i] << " = $" << tsv[i] << "\n\n";
			}
		}

		cout << "BONDS" << endl;
		cout << "---------------------------" <<"\n\n";
		for (int i = 0; i < 3; i++)
		{
			if (bb[i] > 0)
			{
				cout << i + 1 << ". " << bn[i] << "\t" << bb[i];
				if (bb[i] > 1)
				{
					cout << " Bonds @ $";
				}
				else
				{
					cout << " Bond @ $";
				}
				cout << bpp[i] << " = $" << tbv[i] << "\n\n";
			}
		}
	}