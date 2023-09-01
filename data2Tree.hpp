// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################

// This file declares a class, with some members and method
// The definition of the method is done in the corresponding .cpp file

#ifndef __data2Tree__
#define __data2Tree__

#include <vector>
#include <random>
#include <algorithm>

class myVectorData {
public:
   //-- Example of method...
   void clear();
   void CreateEvent();
   std::vector<double> correlatedDetectors_v = {1, 2, 3};
};

static const std::size_t MAX_SIZE_OF_VECTOR = 666;

class myArrayData {
public:
   //-- Example of method...
   void clear();
   void CreateEvent();
   double correlatedDetectors_v[MAX_SIZE_OF_VECTOR] = {1, 2, 3};
};


#endif
