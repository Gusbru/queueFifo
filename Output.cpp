//
// Created by gusbr on 23/09/2017.
//

#include <iostream>
#include "Output.h"

void Output::printQueuesLength(Queues *availableQueues, int nQueues) {

    int length;
    Process *currentProcess;

    for (int i = 0; i < nQueues; ++i) {

        length = 0;
        currentProcess = availableQueues[i].getFirstProcess();

        while (currentProcess != nullptr){
            length += 1;
            std::cout << length << std::endl;
            currentProcess = currentProcess->getNext();
        }

        std::cout << "Q" << i << ": ";
        for (int j = 0; j < length; ++j) {
            std::cout << "#";
        }
        std::cout << std::endl;

    }

}
