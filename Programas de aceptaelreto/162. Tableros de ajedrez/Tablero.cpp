//Marcos Herrero
#include <iostream>

void mostrarTablero(int tam, char n) {
	std::cout << '|';
	for (int i = 0; i < 8 * tam; ++i) std::cout << '-';
	std::cout << "|\n";

	for (int i = 0; i < 4; ++i) {
		for (int i = 0; i < tam; ++i) {
			std::cout << '|';
			for (int i = 0; i < 4; ++i) {
				for (int i = 0; i < tam; ++i) std::cout << ' ';
				for (int i = 0; i < tam; ++i) std::cout << n;
			}
			std::cout << "|\n";

		}

		for (int i = 0; i < tam; ++i) {
			std::cout << '|';
			for (int i = 0; i < 4; ++i) {
				for (int i = 0; i < tam; ++i) std::cout << n;
				for (int i = 0; i < tam; ++i) std::cout << ' ';
			}
			std::cout << "|\n";
		}
	}

	std::cout << '|';
	for (int i = 0; i < 8 * tam; ++i) std::cout << '-';
	std::cout << "|\n";
}

bool resuelveCaso() {
	int tam;
	std::cin >> tam;
	if (tam == 0)return false;

	char negro;
	std::cin >> negro;
	mostrarTablero(tam, negro);

	return true;
}

int main() {
	while (resuelveCaso());
}