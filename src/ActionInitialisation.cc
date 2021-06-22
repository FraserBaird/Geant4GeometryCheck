//
// Created by Fraser Baird on 12/01/2021.
//

#include "ActionInitialisation.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialisation::ActionInitialisation()
: G4VUserActionInitialization(){
//    theFilename = filename;
}

ActionInitialisation::~ActionInitialisation(){}

void ActionInitialisation::BuildForMaster() const{
    SetUserAction(new RunAction());
}

void ActionInitialisation::Build() const {

    // get the primary generator object
    PrimaryGeneratorAction* primGen = new PrimaryGeneratorAction;
    // set it as a user action
    SetUserAction(primGen);
    auto* runAct = new RunAction();
    SetUserAction(runAct);
    EventAction* eventAct = new EventAction(runAct);
    SetUserAction(eventAct);
    SteppingAction* stepAct = new SteppingAction(eventAct);
    SetUserAction(stepAct);
}

