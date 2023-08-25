#include "reader.h"
#include "writer.h"
#include <cstdlib>
#include <iostream>

// Global variables, if needed, go here

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc != 3) {
        std::cerr << "Usage: ./copier infile outfile" << std::endl;
        return EXIT_FAILURE;
    }

    std::string infile = argv[1];
    std::string outfile = argv[2];

    // Create a writer object
    writer theWriter(outfile);

    // Create a reader object
    reader theReader(infile, theWriter);

    // Perform the reading from the file
    theReader.run();

    // Perform the writing to the output file
    theWriter.run();

    return EXIT_SUCCESS;
}