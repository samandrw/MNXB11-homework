#include "myclass.h"
#include <cmath>

// Default constructor - initializes all momentum components to 0
myclass::myclass()
    : fPx(0), fPy(0), fPz(0) {}

// Constructor with variable and momentum components
myclass::myclass(Int_t variable, Double_t px, Double_t py, Double_t pz)
    : fPx(px), fPy(py), fPz(pz) {}

// Destructor - currently empty
myclass::~myclass() {}

// Function to calculate the magnitude of the vector p = (px, py, pz)
Double_t myclass::GetMagnitude() const {
    return std::sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
}
