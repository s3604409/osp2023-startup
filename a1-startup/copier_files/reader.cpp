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

void reader::read() {
    std::string line;
    while (std::getline(in,line)) {

        thewriter.addToQueue(line);
    }
}

bool isOpen() {
    return in.isOpen();
}
