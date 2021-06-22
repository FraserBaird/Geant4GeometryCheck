//
// Created by Fraser Baird on 02/02/2021.
//
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4RunManager.hh"
#include "DetectorConstruction.hh"

SteppingAction::SteppingAction( EventAction* eAction)
        :   G4UserSteppingAction(),
            theDetector(0),
            theEventAction(eAction){
}

SteppingAction::~SteppingAction(){}

void SteppingAction::UserSteppingAction(const G4Step* theStep){
    /* if the first point of the step was not in the target physical volume then
    exit the method */
    G4VPhysicalVolume* pV = theStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    G4LogicalVolume* stepVol = pV->GetLogicalVolume();
    // get the world construction
    const auto* detCon = dynamic_cast<const DetectorConstruction*>(
            G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    // get the detector volume
    const G4LogicalVolume* detectorVol = detCon->GetDetectorLV();
    if (stepVol != detectorVol){
        return;
    }
    if (! IsParticleX(theStep, "neutron")){
        return;
    }

    G4int numberOfSecondaries = GetNumberOfSecondaries(theStep);

    if (numberOfSecondaries == 0){
        return;
    }
    if (SecondariesContainLi7AndAlpha(theStep, numberOfSecondaries)){
        theEventAction->AddHit();
    }

}

G4int SteppingAction::GetNumberOfSecondaries(const G4Step* aStep){
    G4int numSecs = aStep->GetNumberOfSecondariesInCurrentStep();
    return (numSecs);
}

G4bool SteppingAction::IsParticleX(const G4Step* aStep, G4String testParticleName){

    G4String partType = aStep->GetTrack()->GetParticleDefinition()->GetParticleName();

    int compareOutput = partType.compare(testParticleName); // ==0 if strings match


    return (compareOutput == 0); // TRUE if strings match

}

G4bool SteppingAction::SecondariesContainLi7AndAlpha(const G4Step* aStep, G4int numSecs){

    G4bool Li7Bool = false;
    G4bool alphaBool = false;
    const std::vector <const G4Track*>* secondaryTracksVector = aStep->GetSecondaryInCurrentStep();

    for (int i = 0; i < numSecs; i++){
        if (secondaryTracksVector->at(i)->GetParticleDefinition()->GetParticleName() == "Li7"){
            Li7Bool = true;
        }
        else if (secondaryTracksVector->at(i)->GetParticleDefinition()->GetParticleName() == "alpha"){
            alphaBool = true;
        }

    }

    return (alphaBool && Li7Bool);

}