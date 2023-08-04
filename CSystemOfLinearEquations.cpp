#include "CSystemOfLinearEquations.h"
#include <iomanip>


CSystemOfLinearEquations::CSystemOfLinearEquations(int countOfUnknown) {
	this->countOfUnknown = countOfUnknown;
	matrixOfCoefficients = new double* [countOfUnknown];
	for (int i = 0; i < countOfUnknown; i++) {
		matrixOfCoefficients[i] = new double[countOfUnknown + 1];
	}
	vectorOfSolutions = new double[countOfUnknown];
	for (int i = 0; i < countOfUnknown; i++) {
		vectorOfSolutions[i] = 0;
	}
}

double* CSystemOfLinearEquations::solveUsingGaussWithChoosingMainElement() {
	for (int i = 0; i < countOfUnknown; i++) {
		for (int j = i + 1; j < countOfUnknown; j++) {
			//find m
			double m = -(matrixOfCoefficients[j][i] / matrixOfCoefficients[i][i]);
			for (int k = 0; k < countOfUnknown + 1; k++) {
				matrixOfCoefficients[j][k] = matrixOfCoefficients[j][k] + m * matrixOfCoefficients[i][k];
			}
		}
	}
	for (int i = countOfUnknown - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = 0; j < countOfUnknown; j++) {
			sum += -matrixOfCoefficients[i][j] * vectorOfSolutions[j];
		}
		vectorOfSolutions[i] = (matrixOfCoefficients[i][countOfUnknown] + sum) / matrixOfCoefficients[i][i];
	}
	return vectorOfSolutions;
}

std::istream& operator>>(std::istream& in, CSystemOfLinearEquations object) {
	for (int i = 0; i < object.countOfUnknown; i++) {
		std::cout << "Enter coefficients of " << i + 1 << " line: ";
		for (int j = 0; j < object.countOfUnknown + 1; j++) {
			in >> object.matrixOfCoefficients[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, CSystemOfLinearEquations object) {
	out << std::setprecision(4);
	for (int i = 0; i < object.countOfUnknown; i++) {
		for (int j = 0; j < object.countOfUnknown + 1; j++) {
			if (j == 0) {
				out << std::setw(8) << object.matrixOfCoefficients[i][j] << std::resetiosflags(std::ios_base::adjustfield) << std::resetiosflags(std::ios_base::showpos) << "a" << j;
			}
			else if (j > 0 && j != object.countOfUnknown) {
				out << std::showpos << std::setw(8) << object.matrixOfCoefficients[i][j] << std::resetiosflags(std::ios_base::adjustfield) << std::resetiosflags(std::ios_base::showpos) << "a" << j;
			}
			else if (j = object.countOfUnknown) {
				out << "=" << object.matrixOfCoefficients[i][j];
			}
		}
		out << std::endl;
	}
	return out;
}

void printMatrix(double** Matrix, int a, const char* string) {
	std::cout << "\n" << string << "-matrix:\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			std::cout << std::setw(6) << std::setprecision(3) << Matrix[i][j] << " ";
		}
		std::cout << std::resetiosflags(std::ios_base::adjustfield) << std::resetiosflags(std::ios_base::showpos) << std::endl;
	}
}

void printVector(double* Vector, int a, const char* string) {
	std::cout << "\n" << string << ":\n";
	for (int i = 0; i < a; i++) {
		std::cout << Vector[i] << " ";
	}
	std::cout << std::resetiosflags(std::ios_base::adjustfield) << std::resetiosflags(std::ios_base::showpos) << std::endl;
}