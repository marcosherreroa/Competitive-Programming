//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int x, y;
	std::cin >> x >> y;

	std::cout << (x + y)*(x + y + 1) / 2 + 1 + x<<'\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}