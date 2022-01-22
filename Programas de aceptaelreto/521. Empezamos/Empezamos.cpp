//Marcos Herrero
#include <iostream>
#include <vector>
#include <unordered_set>

bool resuelveCaso() {
	int numPisos, numLetras, numAsist;
	std::cin >> numPisos >> numLetras >> numAsist;
	if (numPisos == 0 && numLetras == 0 && numAsist == 0) return false;

	std::vector<std::unordered_set<char>> asistencia (numPisos);

	int piso; char letra;
	for (int i = 0; i < numAsist; ++i) {
		std::cin >> piso >> letra;
		asistencia[piso-1].insert(letra);
	}

	int rep = 0;
	for (int i = 0; i < numPisos; ++i) {
		rep += asistencia[i].size();
	}

	if (numPisos*numLetras % 2 == 0 && rep >= (numPisos*numLetras) / 2 ) std::cout << "EMPEZAMOS\n";
	else if (rep >= (numPisos*numLetras + 1) / 2) std::cout << "EMPEZAMOS\n";
	else std::cout << "ESPERAMOS\n";

	return true;
}

int main() {
	while (resuelveCaso());
}