//
// Created by Fraser Baird on 11/02/2021.
//

#ifndef BBF3_RUN_HH
#define BBF3_RUN_HH
#include "G4Run.hh"
#include "OutputFile.hh"

class Run : public G4Run
{
public:
    Run();
    virtual ~Run();
    virtual void AddHitCount(const G4double numHits){
        theHitCount += numHits;
    }

    virtual void Merge(const G4Run*);

    G4double GetTotalHits() const {
        return theHitCount;
    }
    void SetPrimaryEnergy(G4double theEnergy) {
        thePrimaryEnergy = theEnergy;
    };

    G4double GetPrimaryEnergy() const {
        return thePrimaryEnergy;
    };
private:
    G4double theHitCount;
    G4double thePrimaryEnergy;
};
#endif //BBF3_RUN_HH
