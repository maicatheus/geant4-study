#include "construction.hh"

MyDetectorConstuction::MyDetectorConstuction(){};
MyDetectorConstuction::~MyDetectorConstuction(){};

G4VPhysicalVolume *MyDetectorConstuction::Construct(){

    G4NistManager *nist = G4NistManager::Instance();

    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    //insert material into volume
    G4LogicalVolume *logicWorld =  new G4LogicalVolume(solidWorld, worldMat,"logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.),logicWorld,"physWorld", 0,false,true);

    return physWorld;


};
