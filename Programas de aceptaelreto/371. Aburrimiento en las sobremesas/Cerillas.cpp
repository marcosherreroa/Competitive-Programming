//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;
	std::cout << 3 * N*(N + 1) / 2 << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}