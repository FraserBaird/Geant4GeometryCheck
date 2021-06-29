//
// Created by Fraser Baird on 11/02/2021.
//

#include "Run.hh"

Run::Run() : theHitCount(0), thePrimaryEnergy(0){
}

Run::~Run() {}

void Run::Merge(const G4Run* run){
//    const Run* localRun = static_cast<const Run*>(run);
//    theHitCount += localRun->theHitCount;
//    if (thePrimaryEnergy == 0) {
//        thePrimaryEnergy = localRun->thePrimaryEnergy;
//    }
    G4Run::Merge(run);
}

