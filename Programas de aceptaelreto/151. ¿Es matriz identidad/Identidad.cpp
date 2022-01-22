//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	int aux; bool identidad = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> aux;
			if (i == j && aux != 1 || i != j && aux != 0) identidad = false;
		}
	}

	if (identidad)std::cout << "SI\n";
	else std::cout << "NO\n";
	return true;
}

int main() {
	while (resuelveCaso());
}