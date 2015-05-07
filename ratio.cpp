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
	cout << chys << "/" << znam;
	return;
}

//**********************************************************
//function is looking for common devisor using Euclidean algorithm
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
//using common devisor we can reduse ratio if it not = 1 -> 2/4 = 1/2, but 3/5 = 3/5
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
	if (chys == 0)				//check if ratio has 0 in numerator
	{
		znam = 1;
	}
	else if (znam == 0)			//check if ratio has 0 in denominator
	{
		chys = 1;
		znam = 1;
	}
	else if (znam < 0)			//check if ratio has negativ value in denominator 
	{					//if yes - move negative sign in numerator
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
//using common devisor we can find common denominator for both ratios -> 2/3 and 1/5 = 10/15 and 3/15
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
//adding ratios with common devisor after redusing 
int add_ratio(const Ratio& x, const Ratio& y)
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

	result = chys1 + chys2;
	print_ratio(result, com_dev);
	return 0;
}


//**********************************************************
//subtracting ratios with common devisor
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
//multiplying ratios
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
//deviding ratios
int divide_ratio(const Ratio& x, const Ratio& y)
{
	int chys1 = x.num;
	int znam1 = x.denum;
	int chys2 = y.denum;			
	int znam2 = y.num;			
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
//comparing ratios with common devisor and printing result
int compare(int& chys1, int& chys2, int& com_dev)
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
//comparing ratios with common devisor
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
	compare(chys1, chys2, com_dev);
	return 0;
}

