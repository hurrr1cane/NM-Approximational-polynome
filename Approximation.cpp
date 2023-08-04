#include "Approximation.h"
#include "CSystemOfLinearEquations.h"

#include <iostream>

Approximation::Approximation(int count) : Points(count)
{
	coefficients = nullptr;
}

Approximation::~Approximation()
{
	if (coefficients) { delete[] coefficients; }
}

void Approximation::printApproximationPolynome(int order)
{
	createMatrix(order);
	std::cout << "Approximation polynome: y = ";
	for (int i = 0; i < order; i++) {
		if (i == 0) {
			std::cout << coefficients[i] << ' ';
		}
		if (i > 0) {
			std::cout << "+ " << coefficients[i];
		}
		if (i == 1) {
			std::cout << "x ";
		}
		if (i > 1) {
			std::cout << "x^" << i;
		}
	}
}

void Approximation::createMatrix(int order)
{
	if (coefficients) {
		delete[] coefficients;
	}
	coefficients = new double[order];
	CSystemOfLinearEquations system(order);
	system.getElement(0, 0) = countOfPoints;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (i == 0 && j == 0) continue;

			system.getElement(i, j) = this->sumOfXToPowerOf(i + j);
		}
	}

	

	for (int i = 0; i < order; i++) {
		system.getElement(i, order) = this->sumOfYAndXToPowerOf(i);
	}

	std::cout << "System of equations:\n" << system;

	system.solveUsingGaussWithChoosingMainElement();
	for (int i = 0; i < order; i++) {
		coefficients[i] = system[i];
	}

	//std::cout << system;

	return;
}

double Approximation::sumOfXToPowerOf(int power)
{
	double sum = 0;
	for (int i = 0; i < countOfPoints; i++) {
		sum += pow(points[i][0], power);
	}
	return sum;
}

double Approximation::sumOfYAndXToPowerOf(int power)
{
	double sum = 0;
	for (int i = 0; i < countOfPoints; i++) {
		if (power != 0) {
			sum += points[i][1] * pow(points[i][0], power);
		}
		else {
			sum += points[i][1];
		}
	}
	return sum;
}
