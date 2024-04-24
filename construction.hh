#ifndef CONTRUCTION_HH
#define CONTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

#include "detector.hh"


class MyDetectorConstuction : public G4VUserDetectorConstruction{ 
public:
    MyDetectorConstuction();
    ~MyDetectorConstuction();

    virtual G4VPhysicalVolume *Construct();

private:
    G4LogicalVolume *logicDetector;
    virtual void ConstructSDandField();
};
 
#endif