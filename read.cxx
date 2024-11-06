#include "myclass.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"
#include <iostream>

void read() {
    // Initialize your object
    myclass obj;

    // Open your file
    TFile file("output.root", "READ");

    // Get the tree from the file
    TTree* tree = (TTree*)file.Get("tree");
  
    Double_t px, py;
    tree->SetBranchAddress("px", &px);
    tree->SetBranchAddress("py", &py);

    TH2D* hist = new TH2D("px_py_hist", "px vs py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    Int_t nEntries = tree->GetEntries();
    for (Int_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);

        hist->Fill(px, py);
    }

    hist->Draw("COLZ");

    // Close the file
    file.Close();
}
