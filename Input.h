//
// Created by gusbr on 23/09/2017.
//

#ifndef QUEUEFIFO_INPUT_H
#define QUEUEFIFO_INPUT_H

class Input {
public:
    void getInp(char *input);
    int getNServers();
    int getNQueues();
    int getNSteps();
    int getProcessCreationRate();
    int getProcessDestructionRate();
    int getOutputLevel();
    int getQueueInitialLength();

private:
    int nServers;
    int nQueues;
    int nSteps;
    int processCreationRate;
    int processDestructionRate;
    int queueInitialLength;
    int outputLevel;
};



#endif //QUEUEFIFO_INPUT_H
