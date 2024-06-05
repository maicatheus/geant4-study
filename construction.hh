#ifndef CONTRUCTION_HH
#define CONTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"
#include "G4LogicalSkinSurface.hh"
#include "detector.hh"


class MyDetectorConstuction : public G4VUserDetectorConstruction{ 
public:
    MyDetectorConstuction();
    ~MyDetectorConstuction();

    G4LogicalVolume *GetScoringVolume() const {
        return fScoringVolume;
    }

    virtual G4VPhysicalVolume *Construct();

private:
    virtual void ConstructSDandField();
    
    G4int nCols, nRows;

    G4double xWorld, yWorld, zWorld;
    G4bool isCherenkov, isScintillator;

    G4OpticalSurface *mirrorSurface;

    G4Box *solidWorld, *solidRadiator, *solidDetector, *solidScintillator;
    G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector, *logicScintillator;
    G4VPhysicalVolume *physWorld, *physRadiator, *physDetector, *physScintillator;

    G4GenericMessenger *fMessenger;

    G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI;
    G4Element *C, *Na, *I;

    G4LogicalVolume *fScoringVolume;

    void DefineMaterials();

    void ConstructCherenkov();
    void ConstructScintillator();
};
 
#endif