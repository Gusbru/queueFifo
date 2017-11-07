//
// Created by Gustavo Brunetto on 9/20/17.
//

#include "Process.h"

Process::Process(int id, time_t creationTime, int creationStep, Process *next) {
    this->id = id;
    this->creationTime = creationTime;
    this->creationStep = creationStep;
    this->next = next;

}

Process::~Process() = default;

void Process::setNext(Process *next) {
    this->next = next;
}

Process::Process() = default;
