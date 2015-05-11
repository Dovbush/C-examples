/*
 * main_library.cpp
 *
 *  Created on: 28 Apr 2015
 *      Author: rodo
 */
#include "Data.h"


int main () {
    int numbers[3] = {1,2,3};
    int dates[3] = {28,3,2015};
    int time[3] = {8,23,55};

    Data *ptr[3];
    ptr[0] = new Vector(2,5,6);
    ptr[1] = new SomeDate(23,4,2015);
    ptr[2] = new TimeOfDay(17,22,10);

    ptr[0]->add_number(2);
    ptr[0]->add_vector(numbers);
    ptr[0]->print_result();

    ptr[1]->add_number(20);
    ptr[1]->add_vector(dates);
    ptr[1]->print_result();

    ptr[2]->add_number(15);
    ptr[1]->add_vector(time);
    ptr[2]->print_result();

    delete ptr[0];
    delete ptr[1];
    delete ptr[2];

    return 0;
}
