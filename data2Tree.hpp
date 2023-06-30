// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################

#ifndef __data2Tree__
#define __data2Tree__

#include <vector>

class myFancyClass
{
public:
  //-- Default constructor
  myFancyClass();
  //-- Default destructor
  ~myFancyClass();
  //-- Default copy constructor
  myFancyClass(myFancyClass const & i);
  
  //-- Other functions...
  void clear();
  
  //-- Class members
  //-- initialized by construction, C++11
  double kk1 = 1;
  double kk2 = 2;
  double kk3 = 3;
  std::vector<double> kk4_v = {1,2,3};
};


#endif
