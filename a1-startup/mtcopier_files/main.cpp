/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include "writer.h"
#include <cstdlib>
/**
 * these need to be global variables as you'll need handle cleaning them up in
 *cleanup which will automatically be called on program exit
 **/
reader* readers;
writer* writers;

void cleanup() {
    /**
     * perform any cleanup you need to do here for global pointers
     **/
}

int main(int argc, char** argv) {
    atexit(cleanup);
    /**
     * check command line arguments
     **/
    /**
     * process command line arguments
     **/
    /**
     * initiliaze the reader and writer classes
     **/
    /**
     * initialize the running of each thread. Note you just call run() on each
     * object here, you'll call pthread_create itself in the run function.
     **/

    /**
     *
     * have loop here waiting for the threads to bomplete. Please see
     * section on avoiding busy waiting on the assignment specification to see
     * what need to be done here
      **/
    return EXIT_SUCCESS;
}


///////

/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "mtcopier_files/reader.h"
#include "mtcopier_files/writer.h"
#include <pthread.h>
#include <cstdlib>
/* global variables if needed go here */
int main(int argc, char** argv) {
    /* check command line arguments */
    if (argc != 3) {
        std::cerr <<:"Usage: ./mtcopier infile outfile"<< std::endl;

        return 1;
    }
    /* load the file and copy it to the destination */
    reader fileRead(argv[1], writer fileWrite(argv[2]));
    ;

    if(!fileRead.is_open() || !fileWrite.is_open()) {
        std::cerr << "Error opening files." <<std::endl;
        return 1;
    }

    std::mutex mu;
    std::thread reader1(&reader::read, &fileRead, std::ref(fileWrite), std::ref(mu));
    std::thread reader2(&reader::read, &fileRead, std::ref(fileWrite), std::ref(mu));
    
    std::thread writer1(&FileWriter::write, &fileWrite, std::ref(mu));
    std::thread writer2(&FileWriter::write, &fileWrite, std::ref(mu));
    reader1.join();
    reader2.join();
    
    writer1.join();
    writer2.join();
    return EXIT_SUCCESS;
}