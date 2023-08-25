/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "writer.h"

#include "reader.h"

/**
 * implement these functions requred for the writer class
 **/
void writer::init(const std::string& name) {}

void writer::run() {}

void* writer::runner(void* arg) { return nullptr; }

void writer::append(const std::string& line) {}

void writer::setfinished() {}

/////

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

void writer::run() {
    //TODO
}

void writer::addToQueue(const std::string& line) {
    
    queue.push_back(line);
}

void writer::write(const std::string& line, std::mutex& mu) {
    
    while (!queue.empty()){
        std::lock_guard<std::mutex> lock(mu);
        out << queue.front()<< std::endl;
        queue.pop_front();
    }
}
