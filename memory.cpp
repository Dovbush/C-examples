#include <iostream>
#include "memory.h"
using namespace std;

//constructor
Array::Array()
{
	arr_size = 0;             //non empty index
	capacity = 5;             //full array size with zeros
    parr = new double [capacity];
}


//user's defind constructor 
Array::Array(size_t mem_size)
{
	arr_size = 0;
	capacity = mem_size;
    parr = new double [capacity];
}


//make make a copy of array
Array::Array(const Array &ptr)
    :capacity(ptr.capacity)
{
	arr_size = 0;
    parr = new double [capacity];

    for (size_t k = 0; k < capacity; k++)
    {
    	if (ptr.parr[k] > 0)
    	{
    		parr[k] = ptr.parr[k];
    		++arr_size;
    	}
        parr[k] = ptr.parr[k];
    }

}


//destructor
Array::~Array()
{
    delete [] parr;
}



int Array::get_size()
{
    return arr_size;
}


void Array::print_size()
{
	cout << "Current array capacity is: " << capacity << endl;
	cout << "Current array size is: " << arr_size << endl;
}


//function cut zeros in the tail
Array Array::resize_down()
{
    double *parr1;
    capacity = arr_size;
    parr1 = new double [capacity];	//temporary array
    for (size_t i=0; i<capacity; ++i)
        parr1[i] = parr[i];
  	delete [] parr;
   	parr = parr1;
    return 0;
}


//function extends array if there is no more enough place to store data
Array Array::resize_up(size_t size)
{
    double *parr1;
    parr1 = new double [size];

    for (size_t i=0; i<capacity; ++i)
        parr1[i] = parr[i];

   	delete [] parr;
   	parr = parr1;
   	capacity = size;

    return 0;
}


//store data into the last empty index
void Array::push_to_the_end(const double &temp)
{
    if (arr_size == capacity)
    {
    	Array::resize_up(capacity * 2);
    	parr[arr_size] = temp;
    	++arr_size;
    }

    else
    {
    	parr[arr_size] = temp;
    	++arr_size;
    }
}


//function allows Object to store data using []
double &Array::operator[] (size_t ind)
{
	if (ind > capacity)
		Array::resize_up(ind);
	if ( parr[ind] == 0 )
	{
		++arr_size;
	}
	return parr[ind];
}


//function allows Object to be assigned with some data
const Array &Array::operator= (const Array &rightSide)
{
   	capacity = rightSide.capacity;
   	parr = new double [capacity];
   	for (size_t i = 0; i < capacity; i++)
  	{
   		parr[i] = rightSide.parr[i];
   	}
   	delete [] parr;
	return *this;
}


//function allows comparing two Objects
bool Array::operator== (const Array &rightSide) const
{
    if (capacity != rightSide.capacity)
        return false;
    for (size_t ix = 0; ix < capacity; ix++)
        if (parr[ix] != rightSide.parr[ix])
            return false;

    return true;
}


//function allows to add two Objects
Array Array::operator+ (const Array &rightSide)
{
    if (capacity != rightSide.capacity)
    {
        cout << "Different size\n";
        return 1;
    }
    Array SumArray(capacity);
    for (size_t k = 0; k < capacity; ++k)
    {
    	SumArray.parr[k] = parr[k] + rightSide.parr[k];
    }
    return SumArray;
}

//function prints all elements in array, even zeros
void Array::get_all_elements()
{
    for (size_t k=0; k<capacity; ++k)
    cout << parr[k] << ", ";
    cout << endl;
 }

//function allows to get specified element from array (not by index)
void Array::get_element(size_t ind)
{
    cout << "Element " << ind << " (not index) is " << parr[ind-1] << endl;
}

//function allows to delete specified element from array (not by index)
//and make array smaller
int Array::del_element(size_t ind)
{
    if (ind > capacity)
        cout << "No such index..." << endl;
        //return false;

    for (size_t i = (ind-1); i<(capacity-1); ++i)
        parr[i] = parr[i+1];
    parr[capacity-1] = 0;
    --capacity;
    --arr_size;
    return 0;
}
