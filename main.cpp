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
#include "Servers.h"

int main(int argc, char *argv[]) {

    time_t timeStart;
    Process *firstProcess = nullptr;
    Process *lastProcess = nullptr;

    int nServers;
    int nQueues;

    nServers = nQueues = 10;

    int nSteps = 10;

    int processCreationRate = 1;
    int processDestructionRate = 1;

    // Creating an array of queues
    Queues **availableQueues = new Queues *[nQueues];
    for (int i = 0; i < nQueues; ++i) {
        availableQueues[i] = new Queues(i, processCreationRate, nullptr, nullptr);
        if (availableQueues[i] == nullptr) exit(EXIT_FAILURE);
    }

    // Creating an array of servers
    Servers **availableServers = new Servers *[nServers];
    for (int i = 0; i < nServers; ++i) {
        availableServers[i] = new Servers(i, processDestructionRate, nullptr);
    }

    // cada passo da simulacao (a cada "segundo")
    for (int time = 0; time < nSteps; ++time) {
        std::cout << "******************* STEP = " << time << " *****************************" << std::endl;

        // Para cada uma das filas, create new processes (pode ser diferente para cada fila)
        for (int j = 0; j < nQueues; ++j) {
            // TODO: insert the creation process rate
            firstProcess = availableQueues[j]->getFirstProcess();
            lastProcess = availableQueues[j]->getLastProcess();
            int addProcess = insert(&firstProcess, &lastProcess, time+j);

            std::cout << "add element id = " << time+j << " at queue id = " << j << " at time = " << lastProcess->getCreationTime() << std::endl;
            if (addProcess == 1) {
                availableQueues[j]->setFirstProcess(firstProcess);
                availableQueues[j]->setLastProcess(lastProcess);
                availableServers[j]->setProcessToServe(firstProcess);
            }
        }
        // Para cada um dos servidores, executa os processos correspondentes
        // server request

        for (int j = 0; j < nServers; ++j) {
            // TODO: insert the server process rate
            firstProcess = availableServers[j]->getProcessToServe();
            //int removeProcess = remove(&firstProcess);
            //if (removeProcess == 1) {
                //availableQueues[j]->setFirstProcess(firstProcess);
                //availableQueues[j]->setLastProcess(lastProcess);
                //availableServers[j]->setProcessToServe(firstProcess);
            //}
            //std::cout << "server id = " << j << " removed the process id = " << removeProcess << " from queue id = " << availableQueues[j]->getId() << std::endl;
            // pegar o tempo na remocao
        }



        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

