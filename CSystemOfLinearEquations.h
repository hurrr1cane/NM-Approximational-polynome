#pragma once
#include <iostream>

class CSystemOfLinearEquations {
	int countOfUnknown;
	double** matrixOfCoefficients;
	double* vectorOfSolutions;
public:
	CSystemOfLinearEquations(int countOfUnknown);
	friend std::istream& operator>> (std::istream& in, CSystemOfLinearEquations object);
	friend std::ostream& operator<< (std::ostream& out, CSystemOfLinearEquations object);
	double* solveUsingGaussWithChoosingMainElement();
	friend double Vyznachnyk(CSystemOfLinearEquations& object);
	double& getElement(int i, int j) { return matrixOfCoefficients[i][j]; }
	double operator[] (int i) { return vectorOfSolutions[i]; }
};

void printVector(double* Vector, int a, const char* string);
void printMatrix(double** Matrix, int a, const char* string);
