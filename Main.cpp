/**
  Main.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: Anna Salvati
     Purpose: To test the class LargeInt.ccp/LargeInt.h to make sure that
	         everything i sworking correctly.
*/
#include "LargeInt.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main ()
{
   LargeInt  x, y,z;

  cout << "Enter an integer of your choice : ";
  cin >> x;

  cout << "Enter an integer of your choice : ";
  cin >> y;

  if ( x == y )
         cout<<"\n\nThe two numbers entered are equal";
  else
         cout<<"\n\nThe two numbers entered are different";

    z = x+y;

   cout<<"\n\nx: "<< x << "\ny: " << y << "\nz: " << z;

   cin.get();	//output is too fast 
   return 0;
 }



















