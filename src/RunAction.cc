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

}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    //output results at the end of a run


}
//
//void RunAction::SetPrimaryEnergy(G4double theEnergy){
//    thePrimaryEnergy = theEnergy;
//}