//Marcos Herrero
#include <iostream>
#include <string>
#include <unordered_map>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	std::unordered_map<std::string, int> numReyes;
	std::string nombre;
	for (int i = 0; i < N; ++i) {
		std::cin >> nombre;
		++numReyes[nombre];
	}

	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> nombre;
		std::cout << ++numReyes[nombre]<<'\n';
	}
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}