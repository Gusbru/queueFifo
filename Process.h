//
// Created by Gustavo Brunetto on 9/20/17.
//

#ifndef QUEUEFIFO_PROCESS_H
#define QUEUEFIFO_PROCESS_H


#include <ctime>

class Process {
public:
    Process();
    Process(int id, time_t creationTime, Process *next);
    ~Process();

    // setters
    void setNext(Process *next);

    // getters
    int getId() { return this->id; };
    time_t getCreationTime() { return this->creationTime; };
    Process *getNext() { return this->next; };


private:
    int id;
    time_t creationTime;
    Process *next;

};


#endif //QUEUEFIFO_PROCESS_H
