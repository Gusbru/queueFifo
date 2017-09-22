//
// Created by Gustavo Brunetto on 9/22/17.
//

#ifndef QUEUEFIFO_QUEUES_H
#define QUEUEFIFO_QUEUES_H


#include "Process.h"

class Queues {


public:
    Queues(int id, int creationRate, Process *firstProcess, Process *lastProcess);
    ~Queues() = default;

    void setFirstProcess(Process *firstProcess);
    void setLastProcess(Process *lastProcess);
    int getId();
    int getCreationRate();
    Process *getFirstProcess();
    Process *getLastProcess();

private:
    int id;
    int creationRate;
    Process *firstProcess;
    Process *lastProcess;
};


#endif //QUEUEFIFO_QUEUES_H
