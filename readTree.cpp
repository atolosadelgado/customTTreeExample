// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################


#ifndef __readTree_cpp__
#define __readTree_cpp__


#include <iostream>

#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include "data2Tree.hpp"

void readTree()
{
  
  TFile * ifile = TFile::Open( "testFile.root" , "read" );
  if( ! ifile )
  {
    std::cerr << " File not found " << std::endl;
    return;
  }
  if( ! TClass::GetClass(typeid(myFancyClass))->IsLoaded() )  
  {
	std::cerr << " TClass::GetClass(typeid(std::string))->IsLoaded() == false " << std::endl;
  }
  TTreeReader aReader( "myTree", ifile );
  TTreeReaderValue <myFancyClass>  branch1 (aReader, "branch1.");
  TTreeReaderValue <myFancyClass>  branch2 (aReader, "branch2.");
  
  while( aReader.Next() )
  {
    if( branch1->kk1 != 0 )
      std::cerr << " -Branch1 : kk1: " << branch1->kk1 << " kk2: " << branch1->kk1 << std::endl;
    else if( branch2->kk1 != 0 )
      std::cerr << " +Branch2 : kk1: " << branch2->kk1 << " kk2: " << branch2->kk1 << std::endl;
    else
      std::cerr << "WARNING: entry " << aReader.GetCurrentEntry() << " is empty! " << std::endl;
    
  }
  
  ifile->Close();
  
  return;
}


#endif
