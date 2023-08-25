/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"

#include "writer.h"

/**
 * implement the functions needed for this class
 **/
std::ifstream reader::in;

void reader::init(const std::string& name) {}

void reader::run() {}

void* reader::runner(void* arg) { return nullptr; }

/////

/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include <functional>

reader::reader(const std::string& name, writer& mywriter) {
    in.open(name);
    thewriter = mywriter;

}

reader::~reader(){
    if (in.is_open()) {
        in.close();
    }
}

void reader::read(pthread_mutex_t* mu) {
    std::string line;
    
    while (true) {
        pthread_mutex_lock(mu);
        if(!std::getline(in,line)){
            pthread_mutex_unlock(mu);
            break;
        }
        pthread_mutex_unlock(mu);
        thewriter.addToQueue(line);

    }

    thewriter.write();
}
