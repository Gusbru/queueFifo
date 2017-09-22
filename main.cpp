//
// Nome: Gutavo Brunetto RA: 17733320
// Opcionais Funcionando:
//      0. Projeto Basico - 5.0 pontos
//      1.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Process.h"
#include "Insert.h"
#include "Remove.h"

int main(int argc, char *argv[]) {

    time_t timeStart;
    Process *firstProcess = nullptr;
    Process *lastProcess = nullptr;

    int nServers = 10;
    int nQueues = 10;
    int nSteps = 1000;

    // serverRate
    // processRate

    time(&timeStart);

    for (int i = 0; i < nSteps; ++i) {
        // create new process
        for (int j = 0; j < nQueues; ++j) {
            insert(&firstProcess, &lastProcess, j);
        }
        // server request
        for (int k = 0; k < nServers; ++k) {
            remove(&firstProcess);
        }
    }

    std::cout << insert(&firstProcess, &lastProcess, 494) << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << insert(&firstProcess, &lastProcess, 304) << std::endl;

    time_t timeFinal = lastProcess->getCreationTime();

    double elapsedTime;

    elapsedTime = difftime(timeFinal, timeStart);

    std::cout << "It took " << elapsedTime << " seconds" << std::endl;

    std::cout << firstProcess->getId() << std::endl;
    std::cout << firstProcess->getNext()->getId() << std::endl;

    remove(&firstProcess);
    remove(&firstProcess);
    remove(&firstProcess);

    std::cout << firstProcess->getId() << std::endl;

    return 0;
}

