#include "bonds.h"
#include "securities.h"
#include "shares.h"
#include <string>
#include <cstdlib>
#include "functions.h"
#include "variables.h"
using namespace std;
#include <iostream>

int main()
{
	//declaring shares and bonds
	shares s[5]{ {"Amazon", 1460.22, 1876.23}, { "Intel", 45.87, 60.98},{ "Pfizer", 43.05, 38.80 },{ "TEVA Pharmaceuticals", 15.30, 10.06 },{ "Mc Donalds", 175.13, 199.09 } };
	bonds b[3]{ { "Frontier Communications Corporation", 1000, 1000, 92.50 }, { "California Resources Group", 12000, 9000, 80.00 }, { "South African Government Bond", 10000, 10000, 82.95 } };
		

		cout << "You have been chosen to invest in a choice of 5 Stocks and 3 Bonds.\n\nYou have $100,000.00 available\n\n"<< endl;
	
		//prompting user to choose shares or bonds by selecting either "1" or "2". Program will not continue if user does not "1" or "2".
		do
		{
			cout << "Please select a security:\n1. Shares/n2. Bonds" << endl;
				cin >> sb_choose;
		} while (sb_choose != 1||2);

		cout << "\n\n";

		switch (sb_choose)
		{
		case 1:
			do
			{
				cout << "Please choose from the list of shares: " << endl;

				//prints out the list of available shares by iterating over the variable "s" of type "shares".
				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << ". " << string(s[i].get_name()) << "\t\t Share Price: " << "$" << double(s[i].get_ssp()) << endl;
				}

				//input for selecting which share to purchase
				cin >> s_choose;

				//switches to the relevant share based on user input above
				switch (s_choose)
				{
				case 1:
					sn[0] = s[0].get_name();
					ssp[0] = s[0].get_ssp();
					buy_s(0);
					break;
				case 2:
					sn[1] = s[1].get_name();
					ssp[1] = s[1].get_ssp();
					buy_s(1);
					break;
				case 3:
					sn[2] = s[2].get_name();
					ssp[2] = s[2].get_ssp();
					buy_s(2);
					break;
				case 4:
					sn[3] = s[3].get_name();
					ssp[3] = s[3].get_ssp();
					buy_s(3);
					break;

				case 5:
					sn[4] = s[4].get_name();
					ssp[4] = s[4].get_ssp();
					buy_s(4);
					break;
				}
				cout << "Would you like to purchase shares in other stocks?\n1. Yes\n2. No" << endl;
				//input where user decides to purchase another share or move on to bonds
				cin >> s_quit;
				//Selecting "1" allwos user to choose another stock and "2" moves the user on to bonds
			} while (s_quit == 1);

		case 2:

			do
			{
				cout << "Please choose from the list of bonds: " << endl;

				//prints the list of bonds available for purchase by iterating over the variable "b" of type "bonds"
				for (int i = 0; i < 3; i++)
				{
					cout << i + 1 << ". " << string(b[i].get_name()) <<"\tFace Value: $"<<int(b[i].get_bfv()) << "\tPurchase Price: $" << b[i].get_bpp() <<"\tInterest: "<<b[i].get_bir()<<"%"<< endl;
				}

				//user input decides which bonds to go to 
				cin >> b_choose;

				//switches to the relevant bonds based on user input above
				switch (b_choose)
				{
				case 1:
					bn[0] = b[0].get_name();
					bpp[0] = b[0].get_bpp();
					buy_b(0);
					break;
				case 2:
					bn[1] = b[1].get_name();
					bpp[1] = b[1].get_bpp();
					buy_b(1);
					break;
				case 3:
					bn[2] = b[2].get_name();
					bpp[2] = b[2].get_bpp();
					buy_b(2);
					break;
				}
				cout << "Would you like to purchase additional bonds?\n1.Yes\n2.No" << endl;
				//user decides to purchase mre bonds or continue
				cin >> b_quit;
			} while (b_quit == 1);
		}

		//provides a summary of all shares and bonds purchased by the user
		purchase_summary();
		
		//iterates over shares to provide a financial summary of purchases and performance
		for (int i = 0; i < 5; i++)
		{
			if (bs[i] > 0)
			{
				cout << i + 1 << ". " << sn[i] << endl;;
				cout << bs[i];

				if (bs[i] > 1)
				{
					cout << " Shares\n";
				}
				else
				{
					cout << " Share\n";
				}
				cout << "\tPurchase price: $" << ssp[i] << endl;
				cout << "Value at Year End: $" << s[i].get_esp() << endl;
				if ((s[i].value() * bs[i]) > 0)
				{
					cout << "Profit: $";
				}
				else if (s[i].value() * bs[i] < 0)
				{
					cout << "Loss: $";
				}

				cout << s[i].value() * bs[i]<<"\n\n";

				all_shares_value = all_shares_value + s[i].value() * bs[i];
			}
		}

		//iterates over bonds to proivde a financial summary of purchases and performance
		for (int i = 0; i < 3; i++)
		{
			if (bb[i] > 0)
			{
				cout << i + 1 << ". " << bn[i] << endl;
				cout << bb[i];
				if (bb[i] > 1)
				{
					cout << " Bonds";
				}
				else if(bb[i] == 1)
				{
					cout << " Bond" << endl;
				}
				cout << "Purchase price: $" << bpp[i] << endl;
				cout << "Value at year end: $" << bpp[i] + b[i].value() << endl;
				if (b[i].value() > 0)
				{
					cout << "Profit: $";
				}
				else
				{
					cout << "Loss: $";
				}
				cout << b[i].value() << "\n\n";
			}
			all_bonds_value = all_bonds_value + b[i].value();
		}

		//prints one figure depicting the performance of the shares portfolio
		cout << "Total shares ";
		if (all_shares_value > 0)
		{
			cout << "profit: $";
		}
		else 
		{
			cout << " loss: $ ";
		}
		cout << all_shares_value << "\n";

		//prints one figure depicting the performance of the bonds portfolio
		cout << "Total bonds ";
		if (all_bonds_value > 0)
		{
			cout << " profit: $";
		}
		else
		{
			cout << " loss: $";
		}
		cout << all_bonds_value << "\n";

		p1Score[0] = all_shares_value;
		p1Score[1] = all_bonds_value;
}
