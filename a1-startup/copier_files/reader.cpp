/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "copier_files/reader.h"
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

void reader::read() {
    std::string line;
    while (std::getline(in,line)) {

        thewriter.addToQueue(line);
    }

    thewriter.write();
}
