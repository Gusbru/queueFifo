//
// Created by Gustavo Brunetto on 9/20/17.
//

#include "Insert.h"

int insert(Process **firsProcess, Process **lastProcess, int id, int creationStep) {

    time_t creationTime;
    time(&creationTime);

    // start an empty queue
    if ((*firsProcess) == nullptr) {
        (*firsProcess) = new Process(id, creationTime, creationStep, nullptr);
        if ((*firsProcess) == nullptr) return -1;
        (*lastProcess) = (*firsProcess);

        return 1;
    }

    // queue is not empty
    Process *tmp = (*lastProcess);
    (*lastProcess) = new Process(id, creationTime, creationStep, nullptr);
    if((*lastProcess) == nullptr) return -1;
    tmp->setNext((*lastProcess));

    return 1;

}