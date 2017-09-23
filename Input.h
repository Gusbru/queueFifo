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

private:
    int nServers;
    int nQueues;
    int nSteps;
    int processCreationRate;
    int processDestructionRate;
};



#endif //QUEUEFIFO_INPUT_H
