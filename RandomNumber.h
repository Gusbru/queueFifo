//
// Created by gusbru on 11/6/17.
//

#ifndef QUEUEFIFO_RANDOMNUMBER_H
#define QUEUEFIFO_RANDOMNUMBER_H


#include <random>

class RandomNumber {
public:
    RandomNumber(int seed, int n, double min, double max);
    double *getRand();

private:
    int seed;
    int n;
    double min;
    double max;
    double *nRand;
};


#endif //QUEUEFIFO_RANDOMNUMBER_H
