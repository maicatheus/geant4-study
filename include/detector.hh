#ifndef DETECTOR_HH
#define DETECTOR_HH


#include "G4VSensitiveDetector.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();
};



#endif