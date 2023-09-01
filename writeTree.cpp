// ##########################################################################
// # Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es #
// # Copyright (c) 2018 Alvaro Tolosa. All rights reserved.		 #
// ##########################################################################

#ifndef __writeTree_cpp__
#define __writeTree_cpp__

#include <iostream>
#include <random>
#include <algorithm>

#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include "data2Tree.hpp"




void writeTree()
{

   TFile *ofile = TFile::Open("testFile.root", "recreate");
   if (!ofile) {
      std::cerr << " File not found or already exists" << std::endl;
      return;
   }
   TTree *myTree = new TTree("myTree", "");
   myArrayData obj_for_branch1;
   myTree->Branch("branch1.", &obj_for_branch1);

   myArrayData obj_for_branch2;
   myTree->Branch("branch2.", &obj_for_branch2);

   for (int i = 0; i < 10000; ++i) {


         obj_for_branch1.clear();
         obj_for_branch2.clear();
      //-- if i is even, fill branch2 and set branch1's entry to zero
      if (i % 2 == 0) {
         obj_for_branch2.CreateEvent();
         // obj_for_branch2
         myTree->Fill();

      }
      //-- if i is odd, we do the opposite
      else {

         obj_for_branch1.CreateEvent();
         myTree->Fill();
      }
   }

   myTree->Print();

   ofile->Write();
   ofile->Close();

   return;
}

#endif
