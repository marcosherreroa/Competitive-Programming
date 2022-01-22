//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0)return false;

	int gasto, suma = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> gasto;
		suma += gasto;
	}

	std::cout << suma<<'\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}