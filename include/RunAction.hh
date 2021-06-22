//
// Created by Fraser Baird on 13/01/2021.
//

#ifndef FIRSTSIM_RUNACTION_HH
#define FIRSTSIM_RUNACTION_HH

#endif //FIRSTSIM_RUNACTION_HH

#include "G4UserRunAction.hh"
#include "Run.hh"


class RunAction : public G4UserRunAction{
public:
    RunAction();
    virtual ~RunAction();
    G4Run* GenerateRun(){
        return new Run;
    };
    virtual void BeginOfRunAction(const G4Run* aRun);
    virtual void EndOfRunAction(const G4Run* aRun);

    void AddHitCount(G4int eventHitCount){
        theRunHC += eventHitCount;
    };

    void SetPrimaryEnergy(G4double theEnergy);

private:
    G4int theRunHC;
    G4double thePrimaryEnergy;
    OutputFile* theOutput;

};