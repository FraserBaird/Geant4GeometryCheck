//
// Created by Fraser Baird on 14/01/2021.
//

#include "RunAction.hh"
#include "G4ios.hh"



RunAction::RunAction() : G4UserRunAction(),
theRunHC(0),
thePrimaryEnergy(0){
    // open up the output file
}

RunAction::~RunAction() {

}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
    if(IsMaster()) {
        G4cout << "Init. run: " << G4endl;
        theRunHC = 0;
    }
}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    //output results at the end of a run
    if (IsMaster()){
        const Run* theRun =static_cast<const Run*> (aRun);
        thePrimaryEnergy = theRun->GetPrimaryEnergy();
        theRunHC = theRun->GetTotalHits();
        G4cout << "End of Run!" << G4endl;
        G4cout << "N Detections: " << theRunHC << G4endl;
        G4cout << "Primary Energy: " << thePrimaryEnergy << " (MeV)" << G4endl;
        // print the results to the file
    }

}

void RunAction::SetPrimaryEnergy(G4double theEnergy){
    thePrimaryEnergy = theEnergy;
}