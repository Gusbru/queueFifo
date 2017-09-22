//
// Created by Gustavo Brunetto on 9/22/17.
//

#ifndef QUEUEFIFO_SERVERS_H
#define QUEUEFIFO_SERVERS_H

#include "Process.h"

class Servers {
public:
    Servers(int id, int processRate, Process *processToServe);
    ~Servers();

    void setProcessRate(int processRate);
    void setProcessToServe(Process *processToServe);

    int getId();
    int getProcessRate();
    Process *getProcessToServe();

private:
    int id;
    int processRate;
    Process *processToServe;
};


#endif //QUEUEFIFO_SERVERS_H
