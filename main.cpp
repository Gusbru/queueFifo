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
#include "Input.h"
#include "Output.h"

int main(int argc, char *argv[]) {

    Process *firstProcess = nullptr;
    Process *lastProcess = nullptr;


    // Read user preferences
    Input input;
    input.getInp(argv[1]);
    int nServers = input.getNServers();
    int nQueues = input.getNQueues();
    int nSteps = input.getNSteps();
    int processCreationRate = input.getProcessCreationRate();           // how many process to be create in a specific queue per second (minimum 1)
    int processDestructionRate = input.getProcessDestructionRate();     // how many process to be processed in a specific queue per second (minimum 1)

    Output output;

    int *controlQueues = new int [nQueues];
    for (int l = 0; l < nQueues; ++l) {
        controlQueues[l] = 0;
    }

    // Creating an array for queues and servers (nQueues == nServers)
    Queues **availableQueues = new Queues *[nQueues];
    Servers **availableServers = new Servers *[nServers];
    for (int i = 0; i < nQueues; ++i) {
        availableQueues[i] = new Queues(i, processCreationRate, nullptr, nullptr);
        availableServers[i] = new Servers(i, processDestructionRate, nullptr);
        if (availableQueues[i] == nullptr || availableServers[i] == nullptr) exit(EXIT_FAILURE);
    }

    // cada passo da simulacao (a cada "segundo")
    for (int time = 0; time < nSteps; ++time) {
        std::cout << "******************* STEP = " << time << " *****************************" << std::endl;

        // Para cada uma das filas, create new processes (pode ser diferente para cada fila)
        for (int j = 0; j < nQueues; ++j) {

            for (int k = 0; k < processCreationRate; ++k) {
                std::cout << "creating " << k << std::endl;
                firstProcess = availableQueues[j]->getFirstProcess();
                lastProcess = availableQueues[j]->getLastProcess();
                int addProcess = insert(&firstProcess, &lastProcess, k+j);

                if (addProcess == -1) {
                   std::cout << "Error adding new process... Exiting..." << std::endl;
                   exit(0);
                }

                std::cout << "Process added successfully" << std::endl;
                controlQueues[j] += 1;
                availableQueues[j]->setFirstProcess(firstProcess);
                availableQueues[j]->setLastProcess(lastProcess);
                availableServers[j]->setProcessToServe(firstProcess);
                std::cout << "add element id = " << k+j << " at queue id = " << j << " at time = " << lastProcess->getCreationTime() << std::endl;
            }

            std::cout << "Q" << j << " now have new processes" << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));




            // Para cada um dos servidores, executa os processos correspondentes
            // server request
            for (int k = 0; k < processDestructionRate; ++k) {

                std::cout << "destructing " << k << std::endl;
                firstProcess = availableServers[j]->getProcessToServe();

                if (firstProcess != nullptr) {
                    int processId = firstProcess->getId();
                    // pegar o tempo na remocao
                    time_t removalTime;
                    std::time(&removalTime);
                    double lifetime = difftime(removalTime, firstProcess->getCreationTime());

                    int removeProcess = remove(&firstProcess);

                    if (removeProcess != processId) {
                        std::cout << "Error removing process... Exiting..." << std::endl;
                        exit(0);
                    }

                    std::cout << "Process removed successfully" << std::endl;
                    availableQueues[j]->setFirstProcess(firstProcess);
                    availableQueues[j]->setLastProcess(lastProcess);
                    availableServers[j]->setProcessToServe(firstProcess);

                    controlQueues[j] -= 1;
                    std::cout << "server id = " << j << " removed the process id = " << removeProcess << " from queue id = " << availableQueues[j]->getId() << " process lifetime = " << lifetime << std::endl;
                } else {
                    std::cout << "Queue already empty..." << std::endl;
                }




            }



        }

        // control queue length
//        for (int i = 0; i < nQueues; ++i) {
//            std::cout << "Q" << i << ": ";
//            for (int j = 0; j < controlQueues[i]; ++j) {
//                std::cout << "#";
//            }
//            std::cout << std::endl;
//        }
        output.printQueuesLength(controlQueues, nQueues);


        //output.printQueuesLength(*availableQueues, nQueues);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "********************************************************************" << std::endl << std::endl;
    }

    std::cout << "Program finished!" << std::endl;

    return 0;
}

