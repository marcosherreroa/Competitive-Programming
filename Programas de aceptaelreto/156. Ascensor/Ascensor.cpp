//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int piso;
	std::cin >> piso;
	if (piso < 0)return false;

	int pisoant = piso, totaldif = 0;
	std::cin >> piso;
	while (piso != -1) {
		totaldif += abs(piso - pisoant);
		pisoant = piso;
		std::cin >> piso;
	}

	std::cout << totaldif << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}