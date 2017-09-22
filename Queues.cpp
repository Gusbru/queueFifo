//
// Created by Gustavo Brunetto on 9/22/17.
//

#include "Queues.h"

Queues::Queues(int id, int creationRate, Process *firstProcess, Process *lastProcess) {
    this->id = id;
    this->creationRate = creationRate;
    this->firstProcess = firstProcess;
    this->lastProcess = lastProcess;
}

void Queues::setFirstProcess(Process *firstProcess) {
    this->firstProcess = firstProcess;
}

void Queues::setLastProcess(Process *lastProcess) {
    this->lastProcess = lastProcess;
}

int Queues::getId() {
    return this->id;
}

int Queues::getCreationRate() {
    return this->creationRate;
}

Process *Queues::getFirstProcess() {
    return this->firstProcess;
}

Process *Queues::getLastProcess() {
    return this->lastProcess;
}






