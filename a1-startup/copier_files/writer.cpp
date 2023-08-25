/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/

#include "writer.h"

/**
 * provide your implementation for the writer functions here
 **/
writer::writer(const std::string& name) {
    //TODO
    out.open(name);
}

writer::~writer(){
    if (out.is_open()) {
        out.close();
    }
}

void writer::addToQueue(const std::string& line) {
    
    queue.push_back(line);
}

void writer::write() {
    
    while (!queue.empty()){
        out << queue.front()<< std::endl;
        queue.pop_front();
    }
}


