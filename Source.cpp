#include "Approximation.h"
#include <iostream>

int main(void) {
	Approximation myAprx(5);

	std::cin >> myAprx;
	std::cout << "\n";
	myAprx.printApproximationPolynome(2);
	std::cout << "\n\n";
	myAprx.printApproximationPolynome(3);
	std::cout << "\n\n";
	myAprx.printApproximationPolynome(4);
}