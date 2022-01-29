//Marcos Herrero
#include <iostream>
#include <iomanip>
#include <cmath>

void resuelveCaso() {
	double ang1, ang2;
	std::cin >> ang1 >> ang2;

	double hora = (ang1*12.0) / 360.0;

	if (std::abs(hora - floor(hora) - ang2 / 360.0) < 0.001) { //Case 1: first hand indicates hours
		int min = (ang2*60.0) / 360.0;

		std::cout <<std::setfill('0')<<std::setw(2)<<floor(hora) << ':' <<std::setw(2)<< min << '\n';
	}
	
	else {
		hora = (ang2*12.0) / 360.0;

		if (std::abs(hora - floor(hora) - ang1 / 360.0) < 0.001) { //Case 2: second hand indicates hours
			int min = (ang1*60.0) / 360.0;

			std::cout << std::setfill('0') << std::setw(2) << floor(hora) << ':' << std::setw(2) << min << '\n';
		}

		else { //Case 3: Incorrect
			std::cout << "ERROR\n";
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}