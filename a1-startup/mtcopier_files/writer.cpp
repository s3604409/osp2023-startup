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

void writer::addToQueue(const std::string& line) {
    
    queue.push_back(line);
}

void writer::write(std::mutex& mu) {

    while(true) {
        std::string line;
        pthread_mutex_lock(mu);
        if (!queue.empty()){
            pthread_mutex_unlock(mu);
            break;
        }
        line = queue.front();
        queue.pop_front();
        pthread_mutex_unlock(mu);
        out << line<< std::endl;
    }
   
}
