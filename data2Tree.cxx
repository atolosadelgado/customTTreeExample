// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################


#include "data2Tree.hpp"
#include <iostream>


//-- Default constructor
myFancyClass::myFancyClass()
{

}

//-- Default destructor
myFancyClass::~myFancyClass()
{

}

//-- Default copy constructor
myFancyClass::myFancyClass(const myFancyClass& i):
	      kk1  ( i.kk1   ),
	      kk2  ( i.kk2   ),
	      kk3  ( i.kk3   ),
	      kk4_v( i.kk4_v )
{
  
}


void myFancyClass::clear()
{
    kk1 = 0;
    kk2 = 0;
    kk3 = 0;
    kk4_v.clear();
    return;
}
