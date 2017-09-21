//
// Created by Gustavo Brunetto on 9/20/17.
//

#include <iostream>
#include "Process.h"
#include "Insert.h"
#include "Remove.h"

int main(int argc, char *argv[]) {

    time_t timeStart;
    Process *firstProcess = nullptr;
    Process *lastProcess = nullptr;

    time(&timeStart);
    std::cout << insert(&firstProcess, &lastProcess, 494) << std::endl;
    std::cout << insert(&firstProcess, &lastProcess, 304) << std::endl;


    std::cout << firstProcess->getId() << std::endl;
    std::cout << firstProcess->getNext()->getId() << std::endl;

    remove(&firstProcess);
    remove(&firstProcess);
    remove(&firstProcess);

    std::cout << firstProcess->getId() << std::endl;

    return 0;
}

