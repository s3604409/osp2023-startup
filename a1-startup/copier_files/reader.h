#ifndef READER
#define READER

/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "writer.h"
#include <fstream>
#include <iostream>
#include <string>
#ifndef READER
#define READER
class reader {
   public:
    /* create a reader that reads each line of the file and appends it to the
     * writer's queue
     */
    reader(const std::string& name, writer& mywriter);

    ~reader();

    /* perform the reading and initiating the writing from the file */

    void read();

        

   private:
    std::ifstream in;
    writer& thewriter;
};
#endif
