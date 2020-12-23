//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Dec 21 22:22:37 2020 by ROOT version 6.20/02
// from TTree qfactortree/qfactortree
// found on file: qfactortree030274_allcuts.root
//////////////////////////////////////////////////////////

#ifndef test_selector_h
#define test_selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

#include "TH1D.h"

// Headers needed by this particular selector


class test_selector : public TSelector {
public :

   // use fChain (fReader introduces unknown number of entries)
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain  = 0;   //!pointer to the analyzed TTree or TChain
  

   //for fReader
   // Readers to access the data (delete the ones you do not need).
   /*TTreeReaderValue<Int_t> num_combos = {fReader, "num_combos"};
   TTreeReaderValue<Double_t> pi0mass = {fReader, "pi0mass"};
   TTreeReaderValue<Int_t> combo_number = {fReader, "combo_number"};
   TTreeReaderValue<Double_t> kinfit_CL = {fReader, "kinfit_CL"};
   TTreeReaderValue<Double_t> chisq_ndf = {fReader, "chisq_ndf"};
   TTreeReaderValue<Int_t> event_num = {fReader, "event_num"};*/
   
   

  



   test_selector(TTree * /*tree*/ =0)   { } // for fReader use test_selector(TTree * /*tree*/ =0){ } (don't intialize fChain)
   virtual ~test_selector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);                    // condition ? result1 : result2 (if condition is true returns result1 otherwise result2)
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; } 
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   
   

private:
   
   //for TTree fChain 
//delcare histograms   
   TH1D * hist;

//declare variables;
  Double_t pi0mass;

//declare branches 
  TBranch *b_pi0mass;

   ClassDef(test_selector,0);

};

#endif

#ifdef test_selector_cxx
void test_selector::Init(TTree * tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

      //initialize fReader
   //fReader.SetTree(tree);

   //initialize fChain set branch address and branch pointers
   if(!tree) return;
   fChain = tree;

   //fChain->SetMakeClass(1);
   
   fChain->SetBranchAddress("pi0mass", &pi0mass, &b_pi0mass); // important first argument has to be the same name as in tree
  
   
}

Bool_t test_selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef test_selector_cxx
