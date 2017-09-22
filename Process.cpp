//
// Created by Gustavo Brunetto on 9/20/17.
//

#include "Process.h"

Process::Process(int id, time_t creationTime, Process *next) {
    this->id = id;
    this->creationTime = creationTime;
    this->next = next;

}

Process::~Process() = default;

void Process::setNext(Process *next) {
    this->next = next;
}

Process::Process() = default;
