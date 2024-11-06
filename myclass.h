#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include "TObject.h"
#include <cmath>

class myclass : public TObject
{
public:
    myclass();                                                      // default constructor
    myclass(Int_t variable, Double_t px, Double_t py, Double_t pz); // constructor with p components
    virtual ~myclass();                                             // destructor

    // Setter methods for px, py, and pz
    void SetPx(Double_t px) { fPx = px; }
    void SetPy(Double_t py) { fPy = py; }
    void SetPz(Double_t pz) { fPz = pz; }

    // Member function to calculate magnitude
    Double_t GetMagnitude() const;

private:
    Double_t fPx; // x-component of momentum
    Double_t fPy; // y-component of momentum
    Double_t fPz; // z-component of momentum

    ClassDef(myclass, 1); // ROOT class definition macro
};

#endif // __MYCLASS_H__
