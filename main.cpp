//
// Created by Gustavo Brunetto on 9/20/17.
//

#include <iostream>
#include "Process.h"
#include "Insert.h"

int main(int argc, char *argv[]) {

    time_t timeCreation;
    Process *firstElement = nullptr;
    Process *lastElement = nullptr;

    std::cout << insert(&firstElement, &lastElement, 494) << std::endl;
    std::cout << insert(&firstElement, &lastElement, 304) << std::endl;

    std::cout << firstElement->getNext()->getId() << std::endl;

    return 0;
}

