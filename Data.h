/*
 *  Created on: 28 Apr 2015
 *      Author: rodo
*/

#ifndef DATA_H_
#define DATA_H_

class Data {
protected:
	static const int size = 3;
	int *array;

public:
	Data(int a, int b, int c);
	virtual ~Data();
	virtual int add_vector( const int (&ptr)[size] );
	virtual int add_number(int ) = 0;
	virtual void print_result() = 0;

};

class Vector: public Data {
public:
	//Vector();
	Vector(int a, int b, int c) : Data(a,b,c) {}
	virtual ~Vector();
	int add_vector(const int (&ptr)[size]);
	int add_number(int );
	void print_result();
};


class SomeDate: public Data {
public:
	SomeDate(int a, int b, int c) : Data(a,b,c) {}
	virtual ~SomeDate();
    int add_vector(const int (&ptr)[size]);
	int add_number(int );
	int standard_date();
	void print_result();
};


class TimeOfDay: public Data {
public:
	TimeOfDay(int a, int b, int c) : Data(a,b,c) {}
	virtual ~TimeOfDay();
	int add_vector(const int (&ptr)[size]);
	int add_number(int );
	int standard_time();
	void print_result();
};

#endif /* DATA_H_ */
