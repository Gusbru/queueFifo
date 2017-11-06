//
// Created by gusbru on 11/6/17.
//

#include "PoissonDistribution.h"
#include <cmath>

PoissonDistribution::PoissonDistribution(double lambda) {
    this->lambda = lambda;
}

double PoissonDistribution::getPk(int k) {
    return exp(-this->lambda) * pow(this->lambda, k) / factorial(k) ;
}

int PoissonDistribution::factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

