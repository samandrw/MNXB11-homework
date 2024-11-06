#include "myclass.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include <iostream>

void write() {
    // Create a ROOT file to store the data
    TFile file("output.root", "RECREATE");

    // Create a TTree and define branches for px, py, pz, and magnitude
    TTree tree("tree", "Tree storing vector components and their magnitude");

    Double_t px, py, pz, magnitude;
    tree.Branch("px", &px, "px/D");
    tree.Branch("py", &py, "py/D");
    tree.Branch("pz", &pz, "pz/D");
    tree.Branch("magnitude", &magnitude, "magnitude/D");

    // Loop to generate random data
    Int_t nEvents = 1000;  // For example, set to 1000 events
    for (Int_t i = 0; i < nEvents; ++i) {
        // Generate random px, py, and pz values
        px = gRandom->Gaus(0, 0.02);
        py = gRandom->Gaus(0, 0.02);
        pz = gRandom->Gaus(0, 0.02);

        // Create a myclass object and set px, py, pz
        myclass obj;
        obj.SetPx(px);
        obj.SetPy(py);
        obj.SetPz(pz);

        // Calculate magnitude using the myclass member function
        magnitude = obj.GetMagnitude();

        // Fill the tree with the current data
        tree.Fill();
    }

    // Write the tree to the file and close it
    tree.Write();
    file.Close();
}
