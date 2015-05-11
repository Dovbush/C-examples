/*
 * Data.cpp
 *
 *  Created on: 28 Apr 2015
 *      Author: rodo
 */

#include "Data.h"
#include <iostream>
using namespace std;


Data::Data(int a, int b, int c) {
	array = new int [size];
	array[0] = a;
	array[1] = b;
    array[2] = c;
	}


Data::~Data()
{
	//delete [] array;
}


int Data::add_vector(const int (&ptr)[size])
{
    for (int k = 0; k < 3; ++k)
    {
         array[k] += ptr[k];
    }
	return 0;
}


Vector::~Vector()
{
	delete [] array;
}


int Vector::add_vector(const int (&ptr)[size])
{
    for (int k = 0; k < 3; ++k)
    {
         array[k] += ptr[k];
    }
	return 0;
}


int Vector::add_number(int number)
{
	for (int ix=0; ix<3; ++ix)
	{
		array[ix] += number;
	}
	return 0;
}

void Vector::print_result()
{
	for (int ix=0; ix<3; ++ix)
	{
		cout << "Vector: " << array[ix] << endl;
	}
}

//=================================================
//=================================================



SomeDate::~SomeDate()
{
	delete [] array;
}


int SomeDate::standard_date()
{
	if (array[0] > 30)
	{
		array[1] += 1;
		array[0] -= 30;
	}
	if (array[1] > 12)
	{
		array[2] += 1;
		array[1] -= 12;
	}
	return 0;
}

int SomeDate::add_vector(const int (&ptr)[size])
{
    for (int k = 0; k < 3; ++k)
    {
         array[k] += ptr[k];
    }
    SomeDate::standard_date();
	return 0;
}


int SomeDate::add_number(int number)
{
	for (int ix=0; ix<3; ++ix)
	{
		array[ix] += number;
	}
	SomeDate::standard_date();
	return 0;
}

void SomeDate::print_result()
{
    cout << "Day: " << array[0] << endl;
    cout << "Month: " << array[1] << endl;
    cout << "Year: " << array[2] << endl;
}


//=================================================
//=================================================


TimeOfDay::~TimeOfDay()
{
	delete [] array;
}


int TimeOfDay::standard_time()
{
    for (int k = 2; k == 0; --k)
    {
    	if (array[k] > 59)
    	{
    		array[k-1] += 1;
    		array[k] -= 60;
    	}
    }
    if (array[0] > 24)
        array[0] -= 24;

    return 0;
}

int TimeOfDay::add_vector(const int (&ptr)[size])
{
    for (int k = 0; k < 3; ++k)
    {
         array[k] += ptr[k];
    }
    TimeOfDay::standard_time();
	return 0;
}


int TimeOfDay::add_number(int number)
{
	for (int ix=0; ix<3; ++ix)
	{
		array[ix] += number;
	}
	TimeOfDay::standard_time();
	return 0;
}

void TimeOfDay::print_result()
{
	cout << "Hour: " << array[0] << endl;
    cout << "Minutes: " << array[1] << endl;
	cout << "Seconds: " << array[2] << endl;
}

