//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int a, b;
	std::cin >> a >> b;
	if (a < 0 || b < 0) return false;

	std::cout << 2 * a + 2 * b << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}