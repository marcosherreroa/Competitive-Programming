//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;

	for (int i = 0; i < n; ++i)std::cout << 1;
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}