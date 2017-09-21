//
// Created by Gustavo Brunetto on 9/21/17.
//

#include "Remove.h"

int remove(Process **firstProcess) {

    // empty queue
    if ((*firstProcess) == nullptr) return -1;

    Process *currentProcess = (*firstProcess);
    int currentId = (*currentProcess).getId();
    (*firstProcess) = (*firstProcess)->getNext();
    delete (currentProcess);

    return currentId;

}