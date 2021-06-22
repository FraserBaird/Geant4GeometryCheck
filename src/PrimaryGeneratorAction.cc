//
// Created by Fraser Baird on 12/01/2021.
//

#include "PrimaryGeneratorAction.hh"
#include "G4Neutron.hh"
#include "G4ParticleDefinition.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4Box.hh"
#include "Randomize.hh"
#include "G4GeneralParticleSource.hh"
//class constructor actually does stuff this time, sets the basic particle gun properties
using namespace CLHEP;
PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  theParticleGun(nullptr){
    // get a particle table
    theParticleGun = new G4GeneralParticleSource();
    G4ParticleDefinition* particle = G4Neutron::Definition();
    // set the particle gun particle type
    theParticleGun->SetParticleDefinition(particle);
    // need to double check the geometry to be sure this is correct
//    theParticleGun->SetParticleMomentumDirection(G4ThreeVector(1,0,0));
//    theParticleGun->SetParticleEnergy(1*MeV); // seems reasonable for a beta decay product
    // set in the origin of the XY plane, but the edge of the z dimension
}

//class destructor just deletes the particle gun
PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete theParticleGun;
}



void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    // make source random position on the end of the world box
    // get the world box

    G4ThreeVector randPos = GenerateRandomPosition();
    theParticleGun->SetParticlePosition(randPos);
    theParticleGun->GeneratePrimaryVertex(anEvent);
}

G4double PrimaryGeneratorAction::GetEnergy(){
    return theParticleGun->GetParticleEnergy();
}

G4ThreeVector PrimaryGeneratorAction::GenerateRandomPosition(){
    G4LogicalVolume* worldVol = G4LogicalVolumeStore::GetInstance()->GetVolume("world-logical");
    auto* worldBox = dynamic_cast<G4Box*>(worldVol->GetSolid());

    G4double worldSizeX = worldBox->GetXHalfLength();
    G4double worldSizeY = worldBox->GetYHalfLength();
    G4double worldSizeZ = worldBox->GetZHalfLength();
    G4double xPos= -worldSizeX;
    G4double yPos = 0.75 * 2 * worldSizeY * (G4UniformRand() - 0.5);
    G4double zPos = 0.75 * 2 * worldSizeZ * (G4UniformRand() - 0.5);
    return G4ThreeVector(xPos, yPos, zPos);

}
