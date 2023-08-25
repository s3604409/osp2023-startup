#include "reader.h"

reader::reader(const std::string& name, writer& mywriter) 
    : in(name), thewriter(mywriter) {
    if (!in.is_open()) {
        std::cerr << "Error: Could not open file " << name << std::endl;
        exit(1);
    }
}

void reader::run() {
    std::string line;
    while (std::getline(in, line)) {
        // Appending line to writer's internal queue
        thewriter.append(line);
    }
}