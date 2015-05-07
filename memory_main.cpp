/*
 * memory_main.cpp
 *
 *  Created on: 16 Apr 2015
 *      Author: rodo
 */

#include <iostream>
#include "memory.h"
using namespace std;


//============================================


int main ()
{
	Array A(4);

	A[0] = 2;
	A[1] = 4;
	A[2] = 8;
	A.get_all_elements();
	A.print_size();

	A.push_to_the_end(5);
	A.push_to_the_end(11);
	A.get_all_elements();
	A.print_size();

	A.resize_down();
	A.get_all_elements();
	A.print_size();

	Array B(A);
    if (A==B)
        {cout << "Arrays are equal" << endl;}
    else
        {cout << "Arrays are not equal" << endl;}

    Array C = A + B;
    C.push_to_the_end(100);
    C.push_to_the_end(502);
    C.get_size();
    C.get_all_elements();
	C.print_size();

    C.get_element(2);
    C.del_element(4);
    C[5] = 41;
	C.get_all_elements();
	C.print_size();


	return 0;
}
