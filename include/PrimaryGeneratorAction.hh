//
// Created by Fraser Baird on 12/01/2021.
//

#ifndef FIRSTSIM_PRIMARYGENERATORACTION_HH
#define FIRSTSIM_PRIMARYGENERATORACTION_HH

#endif //FIRSTSIM_PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4GeneralParticleSource.hh"
// not sure why these are called in here


class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    G4ThreeVector GenerateRandomPosition();
    virtual void GeneratePrimaries(G4Event*);
    G4double GetEnergy();
    //get method for the particle gun

    G4GeneralParticleSource* GetThePG(){
        return theParticleGun;
    };

private:
    G4GeneralParticleSource* theParticleGun;
    static G4double energy;
};