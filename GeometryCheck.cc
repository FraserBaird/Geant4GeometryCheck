// the main program for the simulation of the response of a bare boron triflouride detector
#include "globals.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include <string>

#include "G4PhysListFactory.hh"
#include "G4ThermalNeutrons.hh"
#include "ActionInitialisation.hh"
#include "DetectorConstruction.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
// construct the main
int main(int argc, char** argv){
    G4cout << "Hello there!" << G4endl;
    // this program can be run in batch mode (i.e. execute a macro with no visualisation) or in interactive mode, which
    // visualises the set up and allows the user to give commands during run-time. Start by initialising a UI executive
    // pointer
    G4UIExecutive* ui = nullptr;
    // the user can start a batch mode section by passing the name of the macro after the name of the script and the moderated bool and filename. If this
    // isn't done argc == 3 and a UI executive is created

    ui = new G4UIExecutive(argc, argv);
    G4cout << "Ui set!" << G4endl;

    // create the run manager, this could be single threaded or mutlithreaded
#ifdef G4MULTITHREADED
    auto* runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(9);

#else
    auto* runManager = new G4RunManager;
#endif
    G4cout << "Run man set!" << G4endl;

    // build the world
    // returns false if false is input, true otherwise
    G4cout << "Trying construction" << G4endl;
    auto* theWorldObj = new DetectorConstruction();
    // send the world to the run manager
    runManager->SetUserInitialization(theWorldObj);
    const G4String physListName = "FTFP_BERT_HP";
    G4PhysListFactory physListFactory;
    G4VModularPhysicsList* physList = physListFactory.GetReferencePhysList(physListName);
    //set the physics list through the run manager
    runManager->SetUserInitialization(physList);
    runManager->SetUserInitialization(new ActionInitialisation());


    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialise();
    // get a UI manager
    G4UImanager*  UIMan = G4UImanager::GetUIpointer();
    // set the macro path
    UIMan->ApplyCommand("/control/macroPath macros");

    UIMan->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    // remove the ui exec from memory
    delete ui;
    delete visManager;
    delete runManager;
}