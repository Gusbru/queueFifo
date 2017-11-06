//
// Created by gusbru on 11/6/17.
//

#include "RandomNumber.h"
#include <random>

RandomNumber::RandomNumber(int seed, int n, double min, double max) {
    this->seed = seed;
    this->n = n;
    this->min = min;
    this->max = max;
    this->nRand = new double[n];
}

double *RandomNumber::getRand() {
    std::mt19937 gen(this->seed);
    std::uniform_real_distribution<> dist(this->min, this->max);
    for (int i = 0; i < this->n; ++i) {
        nRand[i] = dist(gen);
    }
    return nRand;
}




