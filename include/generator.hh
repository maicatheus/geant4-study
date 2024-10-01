#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun *fParticleGun;
    
public:
    MyPrimaryGenerator(/* args */);
    ~MyPrimaryGenerator();

    virtual void GeneratePrimaries(G4Event*);
};


#endif