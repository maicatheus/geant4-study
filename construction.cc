#include "construction.hh"

MyDetectorConstuction::MyDetectorConstuction(){};
MyDetectorConstuction::~MyDetectorConstuction(){};

G4VPhysicalVolume *MyDetectorConstuction::Construct(){

    G4NistManager *nist = G4NistManager::Instance();

    G4double densitySiO2 = 2.201;
    G4Material *SiO2 = new G4Material("SiO2", densitySiO2*g/cm3,2);
    SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
    SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

    G4double densityH2O = 2.201;
    G4Material *H2O = new G4Material("H2O", densityH2O*g/cm3,2);
    H2O->AddElement(nist->FindOrBuildElement("H"), 2);
    H2O->AddElement(nist->FindOrBuildElement("O"), 1);

    G4Element *C = nist->FindOrBuildElement("C");
    G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3,3);
    Aerogel->AddMaterial(SiO2, 62.5*perCent);
    Aerogel->AddMaterial(H2O, 37*perCent);
    Aerogel->AddElement(C, 0.1*perCent);

    G4double energy[2] = { 1.239841939*eV/0.9, 1.239841939*eV/0.2 };
    G4double rindexAerodel[2] = { 1.1,1.1 };
    G4double rindexWorld[2] = { 1.0,1.0 };


    G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy, rindexAerodel, 2);

    Aerogel->SetMaterialPropertiesTable(mptAerogel);


    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);

    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    //insert material into volume
    G4LogicalVolume *logicWorld =  new G4LogicalVolume(solidWorld, worldMat,"logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.),logicWorld,"physWorld", 0,false,true);


    G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);
    G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");

    G4VPhysicalVolume *physRadiator = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.25*m), logicRadiator, "physRadiator",logicWorld,false,0,true);

    return physWorld;
};
