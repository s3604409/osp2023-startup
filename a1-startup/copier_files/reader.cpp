/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "reader.h"
#include <functional>

reader::reader(const std::string& name) {
    in.open(name);
}

void reader::copy(writer& mywriter) {
    //TODO
    std::string line;
    while (std::getline(in,line)) {
        mywriter.write(line)
    }
}

bool is_open() {
    //TODO
}
