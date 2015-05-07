/*
 * ratio.h
 *
 *  Created on: 8 Apr 2015
 *      Author: rodo
 */

#ifndef RATIO_H_
#define RATIO_H_


struct Ratio
{
	int num, denum;
};

int add_ratio(const Ratio& x, const Ratio& y);
int subtract_ratio(const Ratio& x, const Ratio& y);
int multiplied_ratio(const Ratio& x, const Ratio& y);
int divide_ratio(const Ratio& x, const Ratio& y);
int compare_ratio(const Ratio& x, const Ratio& y);



#endif /* RATIO_H_ */
