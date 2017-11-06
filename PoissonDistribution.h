//
// Created by gusbru on 11/6/17.
//

#ifndef QUEUEFIFO_POISSONDISTRIBUTION_H
#define QUEUEFIFO_POISSONDISTRIBUTION_H


class PoissonDistribution {
public:
    explicit PoissonDistribution(double lambda);

    double getPk(int k);

private:
    double lambda;

    int factorial(int n);
};


#endif //QUEUEFIFO_POISSONDISTRIBUTION_H
