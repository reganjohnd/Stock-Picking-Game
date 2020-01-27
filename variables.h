#pragma once
#include "shares.h"
#include "bonds.h"
#include "securities.h"


double starting_funds{ 100000 }; // cash available with which to purchase securities
double funds_remaining{ starting_funds }; //keeps track of how much money the user has left

//choose which share to purchase
int s_choose;

//choose which bonds t purchase
int b_choose{};
//number of shares to buy
double bs[5]{};

//number of bonds to buy
int bb[3]{};

//share starting price
double ssp[5]{};

//share name
string sn[5]{};

//bond name
string bn[3]{};

//bond purchsae price
double bpp[3]{};

//ending share price
double esp[5]{};

//total share value
double tsv[5]{};

//total bond value
double tbv[3]{};

//choose to purchase shares or bonds
int sb_choose{};

//quit choosing shares
int s_quit{};

//quit choosing bonds
int b_quit{};

string security_plural{ "" };

double all_shares_value{}; //value of all the shares purchased by user
double all_bonds_value{}; // value of all bonds puechased by user