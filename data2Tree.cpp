// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################

// This file contains the definition of the class method
// The class method was declared in the corresponding .hpp file

#include "data2Tree.hpp"
#include <iostream>

static std::random_device rd;    // you only need to initialize it once
static std::mt19937 rng(rd());
std::uniform_int_distribution<std::mt19937::result_type> numerOfElements_rnd(1,MAX_SIZE_OF_VECTOR-1);


void myVectorData::clear()
{
   correlatedDetectors_v.clear();
   return;
}

void myVectorData::CreateEvent()
{
    int nelements = MAX_SIZE_OF_VECTOR; //numerOfElements_rnd(rng);
    correlatedDetectors_v.resize( nelements );
    std::generate( std::begin(correlatedDetectors_v), std::end(correlatedDetectors_v), [&] () { return 123.123; });
}

void myArrayData::CreateEvent()
{
    int nelements = numerOfElements_rnd(rng);
    for( int i =0; i<MAX_SIZE_OF_VECTOR; ++i)
       correlatedDetectors_v[i] = 123.123;

}


void myArrayData::clear()
{
   for( auto & vit : correlatedDetectors_v ) vit=0.0;
}

