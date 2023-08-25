/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include <pthread.h>

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#ifndef WRITER
#define WRITER
class writer {
   public:
    /**
     * Please note that methods and data need to be static as there's a
     * variety of information that needs to be coordinated between writers
     * such as locks and other shared data. Also, as the pthread library
     * is a c library, it does not know about classes so ruuner in particular
     * needs to be static. You can pass in instances into the function as
     * pointers though.
     **/
    static void init(const std::string& name);
    static void* runner(void*);
    void run();
    static void append(const std::string& line);

   private:
    static std::ofstream out;
    static std::deque<std::string> queue;
};
#endif
//////////

/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#ifndef WRITER
#define WRITER
class writer {
   public:
    /**
     * creates the writer instance that writes out to the file
     **/
    writer(const std::string& name);
    /**
     * does the actual writing
     **/
     ~writer();
    void addToQueue(const std::string& line);
    void run();
    /**
     * appends a line from the file read in to be output ... needed by the
     * reader class
     **/
    void write(const std::string& line, std::mutex& mu);

   private:
    std::ofstream out;
    std::deque<std::string> queue;
};
#endif
