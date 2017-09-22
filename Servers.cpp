//
// Created by Gustavo Brunetto on 9/22/17.
//

#include "Servers.h"

Servers::Servers(int id, int processRate, Process *processToServe) {
    this->id = id;
    this->processRate = processRate;
    this->processToServe = processToServe;
}

void Servers::setProcessRate(int processRate) {
    this->processRate = processRate;
}

void Servers::setProcessToServe(Process *processToServe) {
    this->processToServe = processToServe;
}

int Servers::getId() {
    return this->id;
}

int Servers::getProcessRate() {
    return this->processRate;
}

Process *Servers::getProcessToServe() {
    return this->processToServe;
}


Servers::~Servers() = default;

