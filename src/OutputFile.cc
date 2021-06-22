//
// Created by Fraser Baird on 18/01/2021.
//

#include "OutputFile.hh"
#include <string>

OutputFile::OutputFile(G4String fileName, G4bool newFile) {
    if (newFile){
        theFile.open(fileName);
        theFile << "Energy,NDetections\n";
    }
    else {
        theFile.open(fileName, std::ios_base::app);
    }
}

void OutputFile::WriteResults(G4double primaryEnergy, G4double nDetections) {
//    G4String theOutput = ((G4String) primaryEnergy) + ((G4String) ",") + ((G4String) nDetections);
    theFile << primaryEnergy << "," << nDetections << "\n";

}
