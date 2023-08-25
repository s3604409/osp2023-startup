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
   
    /**
     * appends a line from the file read in to be output ... needed by the
     * reader class
     **/
    void write();

   private:
    std::ofstream out;
    std::deque<std::string> queue;
    
};
#endif
