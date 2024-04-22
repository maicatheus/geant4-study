#include "generator.hh"


MyPrimaryGenerator::MyPrimaryGenerator(){
    fParticleGun = new G4ParticleGun(1);

};
MyPrimaryGenerator::~MyPrimaryGenerator(){
    delete fParticleGun;
};

void MyPrimaryGenerator::GeneratePrimaries(G4Event * anEvent){
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "proton";
    G4ParticleDefinition *particle = particleTable->FindAntiParticle(particleName);

    G4ThreeVector pos(0.,0.,0.);
    G4ThreeVector mom(1,1,1);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(100.*GeV);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(anEvent);

}