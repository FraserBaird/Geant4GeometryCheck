//
// Created by Fraser Baird on 18/01/2021.
//

#ifndef FS_OUTPUTFILE_HH
#define FS_OUTPUTFILE_HH

#endif //FS_OUTPUTFILE_HH

#include <fstream>
#include "globals.hh"

class OutputFile {
public:
    OutputFile(G4String fileName, G4bool newFile);
    ~OutputFile(){
        theFile.close();
        G4cout << "Closed!";
    };
    void WriteResults(G4double primaryEnergy, G4double nDetections);
private:
    std::ofstream theFile;
};