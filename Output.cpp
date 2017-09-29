//
// Created by gusbr on 23/09/2017.
//

#include <iostream>
#include "Output.h"

void Output::printQueuesLength(int *controlQueues, int nQueues) {

    for (int i = 0; i < nQueues; ++i) {
        std::cout << "Q" << i << ": ";
        for (int j = 0; j < controlQueues[i]; ++j) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }


}
