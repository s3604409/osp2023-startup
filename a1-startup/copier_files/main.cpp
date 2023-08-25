/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include "writer.h"
#include <cstdlib>
/* global variables if needed go here */
int main(int argc, char** argv) {
    /* check command line arguments */
    if (argc != 3) {
        std::cerr <<:"Usage: ./copier infile outfile"<< std::endl;

        return 1;
    }
    /* load the file and copy it to the destination */
    reader fileRead(argv[1], writer fileWrite(argv[2]));
    ;

    if(!fileRead.is_open() || !fileWrite.is_open()) {
        std::cerr << "Error opening files." <<std::endl;
        return 1;
    }

    fileRead.read(fileWrite);
    return EXIT_SUCCESS;
}
