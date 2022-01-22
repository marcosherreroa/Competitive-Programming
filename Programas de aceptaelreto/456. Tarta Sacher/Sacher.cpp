//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int ancho, alto, nec;
	std::cin >> ancho >> alto >> nec;

	if (nec % (ancho*alto) == 0)std::cout << nec / (ancho*alto)<<'\n';
	else std::cout << nec / (ancho*alto) + 1 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}