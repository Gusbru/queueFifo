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
#include "Queues.h"

int main(int argc, char *argv[]) {

    time_t timeStart;
    Process *firstProcess = nullptr;
    Process *lastProcess = nullptr;

    int nServers = 10;
    int nQueues = 10;
    int nSteps = 10;


    // Creating an array of queues
    Queues **availableQueues = new Queues *[nQueues];
    for (int i = 0; i < nQueues; ++i) {
        availableQueues[i] = new Queues(i, 1, nullptr, nullptr);
        if (availableQueues[i] == nullptr) exit(EXIT_FAILURE);
    }




    // serverRate
    // processRate

    time(&timeStart);

    // cada passo da simulacao (a cada "segundo")
    for (int i = 0; i < nSteps; ++i) {

        // Para cada uma das filas, create new processes (pode ser diferente para cada fila)
        for (int j = 0; j < nQueues; ++j) {
            // TODO: insert the creation process rate
            int addProcess = insert(&firstProcess, &lastProcess, i+j);
            if (addProcess == 1) {
                availableQueues[j]->setFirstProcess(firstProcess);
                availableQueues[j]->setLastProcess(lastProcess);
            }
        }

        // Para cada um dos servidores, executa os processos correspondentes
        // server request
        //for (int k = 0; k < nServers; ++k) {
        //    remove(&firstProcess);
        //}
    }

    for (int i = 0; i < nQueues; ++i) {
        Process *currentProcess;
        currentProcess = availableQueues[i]->getFirstProcess();
        while (currentProcess != nullptr) {
            std::cout << "we are at queue id = " << i << " and the currentProcess has id = " << currentProcess->getId() << std::endl;
            currentProcess = currentProcess->getNext();
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

