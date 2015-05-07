/*
 * ratio.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: rodo
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "ratio.h"
using namespace std;


void print_ratio(int& chys, int& znam)
{
	//cout << operation;
	cout << chys << "/" << znam;
	return;
}

//**********************************************************

int devisor(int& chys, int& znam)
{
	int a = chys;
	int b = znam;
	int c = 0;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

//**********************************************************

int reduce(int& chys, int& znam)
{
	int dev = devisor(chys, znam);
	chys = chys/dev;
	znam = znam/dev;
	return 0;
}

//**********************************************************

int check_ratio(int& chys, int& znam)
{
	//assert(znam == 0);
	if (chys == 0)
	{
		znam = 1;
	}
	else if (znam == 0)
	{
		chys = 1;
		znam = 1;
	}
	else if (znam < 0)
	{
		chys = -(chys);
		znam = -(znam);
		reduce(chys, znam);
	}
	else
	{
	reduce(chys, znam);
	}
return 0;
}

//**********************************************************

int common_devisor(int& chys1, int& znam1, int& chys2, int& znam2)
{
	int common_dev;
	int dev;
	if (znam1 == znam2)
	{
		common_dev = znam1;
	}
	else
	{
		dev = devisor(znam1, znam2);
		common_dev = (znam1 * znam2) / dev;
	}
	if (znam1%znam2 == 0)
	{
		chys2 = chys2 * (znam1/znam2);
	}
	else if (znam2%znam1 == 0)
	{
		chys1 = chys1 * (znam2/znam1);
	}
	else
	{
	chys1 = chys1 * znam2;
	chys2 = chys2 * znam1;
	}
	return common_dev;
}


//**********************************************************
int add_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.num;
	int znam2 = y.denum;
	int result;
	int com_dev;
    //string operation = "addition: ";

	check_ratio(chys1, znam1);
	check_ratio(chys2, znam2);
	com_dev = common_devisor(chys1, znam1, chys2, znam2);

	result = chys1 + chys2;
	print_ratio(result, com_dev);
	return 0;
}


//**********************************************************

int subtract_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.num;
	int znam2 = y.denum;
	int result;
	int com_dev;

	check_ratio(chys1, znam1);
	check_ratio(chys2, znam2);
	com_dev = common_devisor(chys1, znam1, chys2, znam2);

	result = chys1 - chys2;
	print_ratio(result, com_dev);
	return 0;
}

//**********************************************************

int multiplied_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.num;
	int znam2 = y.denum;
	int result;
	int com_dev;

	check_ratio(chys1, znam1);
	check_ratio(chys2, znam2);
	result = chys1 * chys2;
	com_dev = znam1 * znam2;
	print_ratio(result, com_dev);
	return 0;
}

//**********************************************************

int divide_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.denum;			//change to denominator;
	int znam2 = y.num;				//change to numerator;
	int result;
	int com_dev;

	check_ratio(chys1, znam1);
	check_ratio(chys2, znam2);
	result = chys1 * chys2;
	com_dev = znam1 * znam2;
	print_ratio(result, com_dev);
	return 0;
}

//**********************************************************

int comapre(int& chys1, int& chys2, int& com_dev)
{
	if (chys1 > chys2)
		cout << chys1 << "/" << com_dev << " is greater than " << chys2 << "/" << com_dev;
	else if (chys1 == chys2)
		cout << "These ratios are equal!";
	else
		cout << chys2 << "/" << com_dev << " is greater than " << chys1 << "/" << com_dev;
	return 0;
}

//**********************************************************

int compare_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.num;
	int znam2 = y.denum;
	int com_dev;

	check_ratio(chys1, znam1);
	check_ratio(chys2, znam2);
	com_dev = common_devisor(chys1, znam1, chys2, znam2);
	comapre(chys1, chys2, com_dev);
	return 0;
}

