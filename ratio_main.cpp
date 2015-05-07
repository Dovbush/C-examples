/*
 * gcd.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: rodo
 */

#include <iostream>
using namespace std;
#include "ratio.h"


int test_addition(const Ratio& x, const Ratio& y)
{
	add_ratio(x, y);
	return 0;
}


int test_subtraction(const Ratio& x, const Ratio& y)
{
	subtract_ratio(x, y);
	return 0;
}

int test_multiplied(const Ratio& x, const Ratio& y)
{
	multiplied_ratio(x, y);
	return 0;
}

int test_division(const Ratio& x, const Ratio& y)
{
	divide_ratio(x, y);
	return 0;
}

int test_comparison(const Ratio& x, const Ratio& y)
{
	compare_ratio(x, y);
	return 0;
}

int test_zero(const Ratio& x, const Ratio& y)
{
	subtract_ratio(x, y);
	return 0;
}

int test_add_negative_znam(const Ratio& x, const Ratio& y)
{
	add_ratio(x, y);
	return 0;
}

int test_compare_negative_znam(const Ratio& x, const Ratio& y)
{
	compare_ratio(x, y);
	return 0;
}


//****************************************************************

int main()
{
	Ratio var1 = {10, 15};
	Ratio var2 = {8, 104};
	Ratio var3 = {13, 27};
	Ratio var4 = {55, 167};
	Ratio var5 = {0, 25};
	Ratio var6 = {3, -8};

	test_addition(var1, var2);
	cout << endl;
	test_subtraction(var2, var3);
	cout << endl;
	test_multiplied(var1, var2);
	cout << endl;
	test_division(var2, var4);
	cout << endl;
	test_comparison(var4, var1);
	cout << endl;
	test_zero(var1, var5);
	cout << endl;
	test_add_negative_znam(var4, var6);
	cout << endl;
	test_compare_negative_znam(var6, var5);
	cout << endl;

/*  USER choice
 *
	char operation;
	cout << "Choose operation (+,-,*,/,>): ";
	cin >> operation;
	if (operation == '+')
	{
		add_ratio(var1, var2);
	}
	else if (operation == '-')
	{
		subtract_ratio(var1, var2);
	}
	else if (operation == '*')
	{
		multiplied_ratio(var1, var2);
	}
	else if (operation == '/')
	{
		divide_ratio(var1, var2);
	}
	else if (operation == '>')
	{
		compare_ratio(var1, var2);
	}
	else
	{
		cout << "Exit";
	}
*
*/

	return 0;
}



