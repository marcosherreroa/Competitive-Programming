//Marcos Herrero
#include <iostream>

int base6(int n) {
	if (n == 0) return 0;
	else return 10 * base6(n / 6) + n % 6;
}

void resuelveCaso() {
	int n;
	std::cin >> n;
	std::cout << base6(n) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}