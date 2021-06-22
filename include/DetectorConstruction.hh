//
// Created by Fraser Baird on 03/02/2021.
//

#ifndef BBF3_DETECTORCONSTRUCTION_HH
#define BBF3_DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"

class DetectorConstruction : public G4VUserDetectorConstruction{
public:
    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

    const G4LogicalVolume* GetDetectorLV() const {
        return theDetectorLV;
    }

private:
    static G4LogicalVolume* GetBox(G4double x_size, G4double y_size, G4double z_size, const G4String& name,
                            G4Material* material);
//    static G4LogicalVolume* GetCylinder(G4double innerRad,
//                                 G4double outerRad,
//                                 G4double length,
//                                 G4double startAngle,
//                                 G4double segmentAngle,
//                                 const G4String& name,
//                                 G4Material* material);

    G4LogicalVolume* theDetectorLV;
    G4bool isModerated;

//    static G4Material* BoronTriflouride(G4NistManager* aMan);

   static G4LogicalVolume *GetX2Capsule (G4NistManager *nistMan) ;

//    G4LogicalVolume *GetBF3Cylinder(G4NistManager *nistMan);

//    G4LogicalVolume *GetPolyModerator(G4NistManager *nistMan);

    G4LogicalVolume *GetWorldBox(G4NistManager *nistMan);

//    G4LogicalVolume* GetStainlessWalls(G4NistManager *nistMan);

    static G4LogicalVolume *GetLogicalFromCAD(G4String stlFile, G4Material *theMat, const G4String& name);

    static G4Material *GetAmBe(G4NistManager *nistMan);

    static G4LogicalVolume *GetX2Source(G4NistManager *nistMan);
};
#endif //BBF3_DETECTORCONSTRUCTION_HH
