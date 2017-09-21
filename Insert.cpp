//
// Created by Gustavo Brunetto on 9/20/17.
//

#include "Insert.h"

int insert(Process **firsElement, Process **lastElement, int id) {
    time_t creationTime;
    time(&creationTime);
    // start an empty queue
    if ((*firsElement) == nullptr) {
        (*firsElement) = new Process(id, creationTime, nullptr);
        if ((*firsElement) == nullptr) return -1;
        (*lastElement) = (*firsElement);

        return 1;
    }

    // queue is not empty
    Process *tmp = (*lastElement);
    (*lastElement) = new Process(id, creationTime, nullptr);
    if((*lastElement) == nullptr) return -1;
    tmp->setNext((*lastElement));

    return 1;

}
