//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int numPag;
	std::cin >> numPag;
	if (numPag == 0)return false;
	int numPagAnt = numPag;
	int x0 = numPag;
	std::cin >> numPag;

	while (numPag != 0) {
		if (numPagAnt + 1 != numPag) {
			if (x0 == numPagAnt) std::cout << numPagAnt << ',';
			else std::cout << x0 << '-' << numPagAnt << ',';
			x0 = numPag;
		}
		numPagAnt = numPag;
		std::cin >> numPag;
	}

	if (x0 == numPagAnt) std::cout << numPagAnt << '\n';
	else std::cout << x0 << '-' << numPagAnt << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}