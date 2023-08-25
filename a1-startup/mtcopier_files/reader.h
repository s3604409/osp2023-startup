/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include <pthread.h>

#include <fstream>
#include <iostream>
#include <string>
#include "mtcopier_files/writer.h"
#ifndef READER
#define READER
class reader {
   public:
    /* this class has a bunch of static (which means shared in a class)
     * because we need to share the state between threads. For example, we
     * are reading from the same file, should have the same locks for all
     * readers, etc.
     **/

    /** initialize the shared data for the class - for example, open the
     * file. There will be other things which you will need to figure out
     * as you complete the assignment.
     **/
      FileReader() = default;
      static void init(const std::string& name);

    /**
     * the method that implements the thread. It has to be static as the first
     * implicit argument to all instance methods is 'this' and c functions don't
     * know about classes
     **/
      static void* runner(void*);

    /**
     * does the setup for and launches the threads
     **/
      void run();
    /**
     * there may be other functions you need so declare them.
     **/

   private:
      static std::ifstream in;
      static std::ifstream fileIn;
      static pthread_mutex_t file_mutex;
      writer& thewriter;
    /**
     * There may be other private instance data you need so declare those here.
     **/
};
#endif



/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "mtcopier_files/writer.h"
#include <fstream>
#include <iostream>
#include <string>
#include <pthread.h>
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

    void read(pthread_mutex_t* mu);

        

   private:
    std::ifstream in;
    writer& thewriter;
};
#endif

