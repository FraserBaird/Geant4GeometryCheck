//
// Created by Fraser Baird on 19/05/2021.
//

#include "DetectorConstruction.hh"
#include "G4GDMLParser.hh"
#include "G4Visible.hh"

DetectorConstruction::DetectorConstruction()
        : G4VUserDetectorConstruction(),
          theDetectorLV(nullptr){

}

DetectorConstruction::~DetectorConstruction()= default;

G4VPhysicalVolume* DetectorConstruction::Construct(){

    G4GDMLParser parser;
    parser.Read("geometry/PhysNeutronSource.gdml");
    G4VPhysicalVolume* worldVol = parser.GetWorldVolume();


    G4bool over = worldVol->CheckOverlaps();
    G4cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << G4endl;
    G4cout << over << G4endl;
    G4cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << G4endl;
    return worldVol;
}