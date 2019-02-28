/*
 * LargeInt.h
 *
 *  Created on: Mar 5, 2017
 *      Author: julio
        Purpose: To create a header file class called LargeInt that is able to hold  an integer 
	            as big as the memory of the heap, using a dynamic array to do so.

	NOTE: Did not use length in this program due to the fact that the user is inputing 
	      a integer, and you don't know the size, so regardless when you take the input
		 the array will be at max, and my algorithm for the addition didn't require to
		 leave an extra index space for the carray. 
 */

#ifndef LARGEINT_H_
#define LARGEINT_H_
#include <iostream>
using namespace std;

class LargeInt
{
	private:
		int maxSize;					//Maximum size of array
		int* ptr;                      //Array to hold large integer.

	public:
		LargeInt(int max = 5);		                //Constructor
		~LargeInt();                                   //Destructor
		LargeInt(const LargeInt&);                     //Copy Constructor

		LargeInt operator+(LargeInt&);	    //Add LargeInt
		bool operator==(LargeInt&);          //Compare LargeInt
	     void operator=(const LargeInt&);   //copy LargeInt value.

		friend ostream& operator<<(ostream& out,LargeInt&);	//Output LargeInt
		friend istream& operator>>(istream& in,LargeInt&);  //InputLargeInt
};
#endif /* LARGEINT_H_ */
