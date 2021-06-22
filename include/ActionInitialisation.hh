//
// Created by Fraser Baird on 12/01/2021.
//

#ifndef FIRSTSIM_ACTIONINITIALISATION_HH
#define FIRSTSIM_ACTIONINITIALISATION_HH

#endif //FIRSTSIM_ACTIONINITIALISATION_HH
#include "globals.hh"
#include "G4VUserActionInitialization.hh"
class ActionInitialisation : public G4VUserActionInitialization
{
public:
    ActionInitialisation();
    ~ActionInitialisation();
    void Build() const;
    void BuildForMaster() const;

private:
    G4String theFilename;
};