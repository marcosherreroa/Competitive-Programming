//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int caram, N = 0, suma = 0;
	std::cin >> caram;
	if (caram == 0)return false;
	while (caram != 0) {
		++N;
		suma += caram;

		std::cin >> caram;
	}

	if (suma % N == 0)std::cout << "REPARTO JUSTO\n";
	else std::cout << "IMPOSIBLE\n";

	return true;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	while(resuelveCaso());
}