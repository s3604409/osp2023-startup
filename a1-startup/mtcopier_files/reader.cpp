/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "mtcopier_files/reader.h"

#include "mtcopier_files/writer.h"

/**
 * implement the functions needed for this class
 **/
std::ifstream reader::in;
pthread_mutex_t reader::file_mutex;

void reader::init(const std::string& name) {
    in = name;
    pthread_mutex_init(&file_mutex,nullptr);
}

void reader::run() {
    infile.open(in)
    if(!infile.is_open()) {
        std::cerr << "Error opening file: "<< in << std::endl;
        return;
    }
    std:string line;
    while (true) {
        pthread_mutex_lock(&file_mutex);
        if(!std::getline(fileIn,line)){
            pthread_mutex_unlock(&file_mutex);
            break;
        }
        pthread_mutex_unlock(&file_mutex);
        writer::append(line)
    }
}

void* reader::runner(void* arg) { 
    reader* theReader = static_cast<FileReader*>(arg);
    reader->run();
    return nullptr; }

/////

/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "mtcopier_files/reader.h"
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
