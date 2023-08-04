#pragma once
#include "Points.h"
class Approximation :
    public Points
{
private:
    double* coefficients;
public:
    Approximation(int count);
    ~Approximation();
    void printApproximationPolynome(int order);
    void createMatrix(int order);
private:
    double sumOfXToPowerOf(int power);
    double sumOfYAndXToPowerOf(int power);
};

