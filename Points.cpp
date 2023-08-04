#include "Points.h"

Points::Points(int count)
{
	this->countOfPoints = count;
	points = new double* [count];
	for (int i = 0; i < count; i++) {
		points[i] = new double[2];
	}
}

std::istream& operator>>(std::istream& is, Points obj)
{
	for (int i = 0; i < 2; i++) {
		std::cout << "Enter " << i + 1 << " row: ";
		for (int j = 0; j < obj.countOfPoints; j++) {
			is >> obj.points[j][i];
		}
	}
	obj.isFilled = true;
	return is;
}

std::ostream& operator<<(std::ostream& os, Points obj)
{
	for (int i = 0; i < obj.countOfPoints; i++) {
		os << obj.points[i][0] << ' ';
	}
	os << '\n';
	for (int i = 0; i < obj.countOfPoints; i++) {
		os << obj.points[i][1] << ' ';
	}
	return os;
}
