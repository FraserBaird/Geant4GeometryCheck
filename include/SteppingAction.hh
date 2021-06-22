//
// Created by Fraser Baird on 02/02/2021.
//

#ifndef BBF3_STEPPINGACTION_HH
#define BBF3_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

class DetectorConstruction;
class EventAction;
class G4VPhysicalVolume;

class SteppingAction : public G4UserSteppingAction{
public:

    SteppingAction(EventAction *eAction);
    virtual ~SteppingAction();
    virtual void UserSteppingAction(const G4Step* aStep);


private:
    DetectorConstruction* theDetector;
    EventAction* theEventAction;
    G4bool IsParticleX(const G4Step* aStep, G4String name);
    G4int GetNumberOfSecondaries(const G4Step* aStep);
    G4bool SecondariesContainLi7AndAlpha(const G4Step* aStep, G4int numOfSecs);

};

#endif //BBF3_STEPPINGACTION_HH
