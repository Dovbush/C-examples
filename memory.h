/*
 * memory.h
 *
 *  Created on: 16 Apr 2015
 *      Author: rodo
 */

#ifndef MEMORY_H_
#define MEMORY_H_

class Array
{
private:

	double *parr;
	double element;
	size_t capacity;
	size_t arr_size;

public:
	Array();
    	Array(size_t );
    	Array(const Array & ); //make a copy of array
	~Array();

	Array resize_down();
	Array resize_up(size_t );
	void push_to_the_end(const double &temp);
    	const Array &operator= (const Array &);
    	Array operator+ (const Array & );
    	bool operator== (const Array & ) const;
    	double &operator[] (size_t );
    	void get_element(size_t );
    	int del_element(size_t );
	void get_all_elements();
	int get_size();
	void print_size();
};

#endif /* MEMORY_H_ */
