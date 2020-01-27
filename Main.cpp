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
	shares s[5]{ {"Amazon", 1460.22, 1876.23}, { "Intel", 45.87, 60.98},{ "Pfizer", 43.05, 38.80 },{ "TEVA Pharmaceuticals", 15.30, 10.06 },{ "Mc Donalds", 175.13, 199.09 } };
	bonds b[3]{ { "Frontier Communications Corporation", 1000, 1000, 92.50 }, { "California Resources Group", 12000, 9000, 80.00 }, { "South African Government Bond", 10000, 10000, 82.95 } };

		cout << "INTRO\n\nYou have $100,000.00 available\n\nWhat would you like to purchase?\n1. Shares\n2. Bonds" << endl;
		cin >> sb_choose;

		switch (sb_choose)
		{
		case 1:
			do
			{
				cout << "Please choose from the list of shares: " << endl;

				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << ". " << string(s[i].get_name()) <<"\t\t Share Price: " << "$" << double(s[i].get_ssp())<< endl;
				}

				cin >> s_choose;

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
				cout << "Would you like to purchase additional shares?\n1. Yes\n2. No" << endl;
				cin >> s_quit;
			} while (s_quit == 1);

		case 2:

			do
			{
				cout << "Please choose from the list of bonds: " << endl;

				for (int i = 0; i < 3; i++)
				{
					cout << i + 1 << ". " << string(b[i].get_name()) << endl;
				}

				cin >> b_choose;

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
				cin >> b_quit;
			} while (b_quit == 1);
		}

		purchase_summary();
		
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
				cout << "Value at year end: $" << b[i].value() << endl;
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
}
