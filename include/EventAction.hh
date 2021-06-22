//
// Created by Fraser Baird on 13/01/2021.
//

#ifndef FIRSTSIM_EVENTACTION_HH
#define FIRSTSIM_EVENTACTION_HH

#endif //FIRSTSIM_EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "globals.hh"

class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAct);
    virtual ~EventAction();
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    void AddHit(){
        theHitCount += 1;
    }
private:
    G4int theHitCount;
    RunAction* theRunAction{};
};