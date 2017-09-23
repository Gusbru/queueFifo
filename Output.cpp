//
// Created by gusbr on 23/09/2017.
//

#include <iostream>
#include "Output.h"

void Output::printQueuesLength(Queues *availableQueues, int nQueues) {



    std::cout << "printing output " << nQueues << std::endl;

    for (int i = 0; i < nQueues; ++i) {
        int length = 0;
        std::cout << i << std::endl;
        Process *currentProcess = availableQueues[i].getFirstProcess();
        while (currentProcess != nullptr){
            length += 1;
            currentProcess = currentProcess->getNext();
        }

        std::cout << "Q" << i << ": ";
        for (int j = 0; j < length; ++j) {
            std::cout << "#";
        }
        std::cout << std::endl;

    }

}
