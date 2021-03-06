//
// Nome: Gutavo Brunetto RA: 17733320
// Opcionais Funcionando:
//      0. Projeto Basico                                - 5.0 pontos
//      1. Usuário pode especificar numero de servidores - 1.0 ponto
//      7. Chegada de clientes na fila obedece Poisson   - 2.0 pontos
//      8. Execução do sistema acelerada                 - 2.0 pontos
//      -------------------------------------------------------------
//                                                        10.0 pontos
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
#include "RandomNumber.h"
#include "PoissonDistribution.h"

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
    int queueInitialLength = input.getQueueInitialLength();
    int outputLevel = input.getOutputLevel();
    bool fastTrack = input.getFastTrack();

    Output output;

    PoissonDistribution *poissonDistributionCreate = new PoissonDistribution(processCreationRate);
    PoissonDistribution *poissonDistributionDestruction = new PoissonDistribution(processDestructionRate);

    // Creating an array for queues and servers (nQueues == nServers)
    Queues **availableQueues = new Queues *[nQueues];
    Servers **availableServers = new Servers *[nServers];
    for (int i = 0; i < nQueues; ++i) {
        availableQueues[i] = new Queues(i, processCreationRate, nullptr, nullptr);
        availableServers[i] = new Servers(i, processDestructionRate, nullptr);
        if (availableQueues[i] == nullptr || availableServers[i] == nullptr) exit(EXIT_FAILURE);
    }

    // initialize the queues
    int *controlQueues = new int [nQueues];
    int countProcess = 0;
    for (int j = 0; j < nQueues; ++j) {
        for (int i = 0; i < queueInitialLength; ++i) {
            firstProcess = availableQueues[j]->getFirstProcess();
            lastProcess = availableQueues[j]->getLastProcess();
            int addProcess = insert(&firstProcess, &lastProcess, i+j, 0);
            countProcess++;

            if (addProcess == -1) {
                std::cout << "Error adding new process... Exiting..." << std::endl;
                exit(0);
            }

            if (outputLevel == 0) std::cout << "Process " << countProcess << " added successfully" << std::endl;

            controlQueues[j] += 1;
            availableQueues[j]->setFirstProcess(firstProcess);
            availableQueues[j]->setLastProcess(lastProcess);
        }
    }


    // record the initial time
    time_t initialTime;
    std::time(&initialTime);

    // store the number of process executed
    int numberOfProcess = 0;

    // total time in the queue
    double timeInQueue = 0;

    // random number vector for process and servers
    int seed;

    seed = 2;
    double *randomNumberProcess = RandomNumber(seed, nQueues*nSteps, 0.0, 1.0).getRand();

    seed = 7;
    double *randomNumberServer = RandomNumber(seed, nServers*nSteps, 0.0, 1.0).getRand();

    int stepQueue = 0;
    int stepServer = 0;

    // cada passo da simulacao (a cada "segundo")
    for (int time = 0; time < nSteps; ++time) {

        if(!fastTrack)
            std::cout << "******************* STEP = " << time << " *****************************" << std::endl;

        // Para cada uma das filas, create new processes (pode ser diferente para cada fila)
        for (int j = 0; j < nQueues; ++j) {

            firstProcess = availableQueues[j]->getFirstProcess();
            lastProcess = availableQueues[j]->getLastProcess();


            // determining the creationRate based in the Poisson Distribution
            stepQueue++;
            int kPoissonProcess = 0;
            double sumProbabilityProcess = poissonDistributionCreate->getPk(kPoissonProcess);
            while (sumProbabilityProcess < randomNumberProcess[stepQueue]){
                kPoissonProcess++;
                sumProbabilityProcess += poissonDistributionCreate->getPk(kPoissonProcess);
            }


            // create process
            for (int k = 0; k < kPoissonProcess; ++k) {
                if (outputLevel == 0) std::cout << "creating " << k << std::endl;

                int addProcess = insert(&firstProcess, &lastProcess, k+j, time);

                if (addProcess == -1) {
                   std::cout << "Error adding new process... Exiting..." << std::endl;
                   exit(0);
                }

                if (outputLevel == 0) std::cout << "Process added successfully" << std::endl;

                controlQueues[j] += 1;
                availableQueues[j]->setFirstProcess(firstProcess);
                availableQueues[j]->setLastProcess(lastProcess);
                availableServers[j]->setProcessToServe(firstProcess);

                if (outputLevel == 0) std::cout << "add element id = " << k+j << " at queue id = " << j << " at time = " << lastProcess->getCreationTime() << std::endl;
            }


            if (outputLevel == 0) {
                if (processCreationRate > 0)
                    std::cout << "Q" << j << " now have new processes" << std::endl;
            }


            //std::this_thread::sleep_for(std::chrono::milliseconds(1000));


            // determining the destructionRate based in the Poisson Distribution
            stepServer++;
            int kPoissonServer = 0;
            double sumProbabilityServer = poissonDistributionDestruction->getPk(kPoissonServer);
            while (sumProbabilityServer < randomNumberServer[stepServer]){
                kPoissonServer++;
                sumProbabilityServer += poissonDistributionDestruction->getPk(kPoissonServer);
            }


            // Para cada um dos servidores, executa os processos correspondentes
            // server request
            for (int k = 0; k < kPoissonServer; ++k) {

                if (outputLevel == 0) std::cout << "destructing process " << k << " for queue id = " << j << std::endl;

                if (firstProcess != nullptr) {
                    int processId = firstProcess->getId();

                    double lifetime;
                    if(!fastTrack){
                        // pegar o tempo na remocao (fastTrack desligado)
                        time_t removalTime;
                        std::time(&removalTime);
                        lifetime = difftime(removalTime, firstProcess->getCreationTime());
                    } else {
                        // fastTrack ligado
                        int removalStep = time;
                        lifetime = removalStep - firstProcess->getCreationStep();
                    }


                    int removeProcess = remove(&firstProcess);

                    if (removeProcess != processId) {
                        std::cout << "Error removing process... Exiting..." << std::endl;
                        exit(0);
                    }

                    // update the number of process processed and the total time
                    numberOfProcess++;
                    timeInQueue += lifetime;

                    if (outputLevel == 0) std::cout << "Process removed successfully" << std::endl;
                    availableQueues[j]->setFirstProcess(firstProcess);
                    availableQueues[j]->setLastProcess(lastProcess);
                    availableServers[j]->setProcessToServe(firstProcess);

                    controlQueues[j] -= 1;
                    if (outputLevel == 0) std::cout << "server id = " << j << " removed the process id = " << removeProcess << " from queue id = " << availableQueues[j]->getId() << " process lifetime = " << lifetime << std::endl;
                } else {
                    if(k == 0 && !fastTrack)
                        std::cout << "Queue " << j << " already empty..." << std::endl;
                }




            }



        }

        if(!fastTrack) {
            output.printQueuesLength(controlQueues, nQueues);

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "********************************************************************" << std::endl << std::endl;
        }


    }

    std::cout << "********************************************************************" << std::endl;
    std::cout << "**                            STATISTICS                          **" << std::endl;
    std::cout << "********************************************************************" << std::endl;
    std::cout << "We consumed " << numberOfProcess << " process" << std::endl;
    std::cout << "Total time = " << timeInQueue << " seconds" << std::endl;
    std::cout << "Average time in queue = " << timeInQueue/numberOfProcess << " seconds/process" << std::endl;
    std::cout << "********************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "********************************************************************" << std::endl;
    std::cout << "**                    Program finished!                           **" << std::endl;
    std::cout << "********************************************************************" << std::endl;

    return 0;
}

