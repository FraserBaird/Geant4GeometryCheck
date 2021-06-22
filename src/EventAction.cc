//
// Created by Fraser Baird on 14/01/2021.
//
#include "EventAction.hh"
#include "RunAction.hh"
#include "Run.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"

EventAction::EventAction(RunAction *runAct)
: G4UserEventAction(),
  theHitCount(0){}

EventAction::~EventAction(){}

void EventAction::BeginOfEventAction(const G4Event *event) {
    theHitCount = 0;
}

void EventAction::EndOfEventAction(const G4Event *event) {
    Run* currentRun = dynamic_cast< Run* > (G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    currentRun->AddHitCount(theHitCount);
    G4double energy = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
    currentRun->SetPrimaryEnergy(energy);

}