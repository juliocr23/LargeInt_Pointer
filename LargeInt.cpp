
/***
  LargeInt.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: julio
        Purpose: The purpose of this file is to implement the header file LargeInt.h 
*/
#include "LargeInt.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

LargeInt:: LargeInt(int max)
{
	this->maxSize = max;
	ptr = new int[maxSize];
}
LargeInt:: LargeInt(const LargeInt& copyObj)
{
	maxSize = copyObj.maxSize;
	ptr = new int[copyObj.maxSize];

	for(int i = 0; i<copyObj.maxSize; i++)
		    ptr[i] = copyObj.ptr[i];
}

LargeInt:: ~LargeInt()
{
	delete [] ptr;
	ptr = 0;
}
/**
   Base case: When the length of both arrays are the 
	         same and the sum of each digit is less than 9. (CHECKED)

   case 2: When  the length of one array is greater than other
	      and the sum of each digit is less than 9.           (CHECKED)

   case 3: When the length of both arrays are the same and the sum of
           each digit is greater than 9.                       (CHECKED)

   case 4: When the length of one array is greater than other
           and the sum of each digit is greater than 9.       (CHECKED)
*/
LargeInt  LargeInt:: operator+(LargeInt& integer)
{
	string strSum; //Store the sum in a string 
	string temp;   //Store the sum of the two digit into temp.
	int carry = 0; //The carry of the sum of the two digit. 

	int i = 0;
	int j = 0;

    for (i, j; (i<maxSize||j<integer.maxSize )|| carry>0; i+=1,j+=1)
    {
	     int digitSum = 0;
		digitSum += carry;

		if (j<integer.maxSize)
			digitSum += integer.ptr[j];
		if (i< maxSize)
			digitSum += ptr[i];

		if (digitSum > 9)
		{
			temp = to_string(digitSum);
			carry = temp[0]-'0'; 
			strSum += temp[1];
		}
		else
		{
			strSum += to_string(digitSum);
			carry = 0;
		}
	}

    LargeInt sum(strSum.length());
    //Copy elements from string  to int.
    for(int i = 0; i < sum.maxSize; i++)
		sum.ptr[i] = strSum[i] - '0';

	return sum;
}

bool LargeInt:: operator==(LargeInt& integer)
{
	bool flag  = true;

	 if(maxSize != integer.maxSize)
    	  return false;
      else
      {
    	  for(int i = 0; i<maxSize; i++)
    		  if(ptr[i] != integer.ptr[i])
    		  {
    			  flag = false;
    			  break;
    		  }
      }
	 return flag;
}

void LargeInt::operator=(const LargeInt& integer)
{
	maxSize = integer.maxSize;
	ptr = new int[integer.maxSize];

	for (int i = integer.maxSize-1; i>=0; i--)
		ptr[i] = integer.ptr[i];
}

ostream& operator<<(ostream& out,LargeInt& integer)
{
	for(int i = (integer.maxSize-1); i>=0; i--)
		  out << integer.ptr[i];
	return out;
}

//CHECKED
istream& operator>>(istream& in, LargeInt& integer)
{
	delete[] integer.ptr;
	integer.ptr = 0;

	//Get input from the user and calculate # of digits.
	string temp;
	getline(in,temp);

	integer.maxSize = temp.length();
	integer.ptr = new int[integer.maxSize];

	// convert char to int and Copy digit by digit backwards
	for (int i = (integer.maxSize-1), j = 0; i>= 0; i--, j++)
		integer.ptr[i] = temp[j] - '0';
	return in;
}
