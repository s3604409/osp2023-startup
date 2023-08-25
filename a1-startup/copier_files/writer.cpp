#include "writer.h"

writer::writer(const std::string& name) : out(name) {
    if (!out.is_open()) {
        std::cerr << "Error: Could not open file " << name << std::endl;
        exit(1);
    }
}

void writer::run() {
    // Write each line from the queue to the output file
    while (!queue.empty()) {
        std::string line = queue.front();
        queue.pop_front();
        out << line << std::endl;
    }
}

void writer::append(const std::string& line) {
    // Appends a line to the queue
    queue.push_back(line);
}