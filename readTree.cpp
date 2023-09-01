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

   TFile *ifile = TFile::Open("testFile.root", "read");
   if (!ifile) {
      std::cerr << " File not found " << std::endl;
      return;
   }
   if (!TClass::GetClass(typeid(myVectorData))->IsLoaded()) {
      std::cerr << " TClass::GetClass(typeid(std::string))->IsLoaded() == false " << std::endl;
   }

   // Create a TTreeReader to read the tree named "myTree"
   TTreeReader aReader("myTree", ifile);

   // Create TTreeReaderValues for the branches "branch1" and "branch2"
   TTreeReaderValue<myVectorData> branch1(aReader, "branch1.");
   TTreeReaderValue<myVectorData> branch2(aReader, "branch2.");

   // Loop over the entries of the tree
   while (aReader.Next()) {
      if (branch1->correlatedDetectors_v.size() != 0)
         std::cerr << " -Branch1 : size: " << branch1->correlatedDetectors_v.size() << std::endl;
      else if (branch2->correlatedDetectors_v.size() != 0)
         std::cerr << " -Branch2 : size: " << branch2->correlatedDetectors_v.size() << std::endl;
      else
         std::cerr << "WARNING: entry " << aReader.GetCurrentEntry() << " is empty! " << std::endl;
   }

   ifile->Close();

   return;
}

#endif
