//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<char>>;

bool resuelveCaso() {
	int anch, alt;
	std::cin >> anch >> alt;
	if (!std::cin)return false;

	tMatriz pueblo(alt, std::vector<char>(anch));
	for (int i = 0; i < alt; ++i) {
		for (int j = 0; j < anch; ++j) {
			std::cin >> pueblo[i][j];
		}
	}

	int semaforos = 0;
	for (int i = 0; i < alt; ++i) {
		for (int j = 0; j < anch; ++j) {
			if (pueblo[i][j] == '#') {
				bool arriba = false, ab = false, izq = false, dcha = false;
				if (i - 1 >= 0 && pueblo[i - 1][j] == '#') arriba = true;
				if (i + 1 < alt && pueblo[i + 1][j] == '#')ab = true;
				if (j - 1 >= 0 && pueblo[i][j - 1] == '#') izq = true;
				if (j + 1 < anch && pueblo[i][j + 1] == '#') dcha = true;
				
				if ((arriba && ab && (izq || dcha)) || (izq && dcha && (arriba || ab))) {
					semaforos += arriba;
					semaforos += ab;
					semaforos += izq;
					semaforos += dcha;
				}
	
			}
		}
	}

	std::cout << semaforos << '\n';

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
}