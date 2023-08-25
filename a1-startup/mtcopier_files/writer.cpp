/**
 * startup code provided by Paul Miller for COSC1114 - Operating Systems
 * Principles
 **/
#include "mtcopier_files/writer.h"

#include "mtcopier_files/reader.h"

std::string FileWriter::out;
std::ofstream FileWriter::fileOut;
std::deque<std::string> FileWriter::queue;
pthread_mutex_t FileWriter::queue_mutex;
bool FileWriter::finished = false;
/**
 * implement these functions requred for the writer class
 **/
void writer::init(const std::string& name ) {
    out = name;
    fileOut.open(out);
    pthread_mutex_init(&queue_mutex, nullptr);
}

void writer::run() {
     while (!finished || !queue.empty()) { 
        write();
    }
    outfile.close();
}

void* writer::runner(void* arg) { 
    writer* theWriter = static_cast<writer*>(arg);
    writer->run();
    return nullptr; }

void writer::addToQueue(const std::string& line) {
    pthread_mutex_lock(&queue_mutex);
    queue.push_back(line);
    pthread_mutex_unlock(&queue_mutex);
}

void writer::setfinished() {
    finished = true;
}

void writer::write(std::mutex& mu) {
    pthread_mutex_lock(&queue_mutex);

    while(!queue.empty()) {
        std::string line= queue.front();
        queue.pop_front();
        outfile << line << std::endl;
    }
    pthread_mutex_unlock(&queue_mutex);
}