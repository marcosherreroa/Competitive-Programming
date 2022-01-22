#include <iostream>
#include <vector>

bool resuelveCaso() {
	int n, m, c , ini, read, readant;

	std::cin >> readant;
	if (readant == -1) return false;
	std::cin >> read;

	n = 1;
	m = 0;
	c = 0;
	ini = 0;

	while (read != -1) {
		if (read != readant) ini = n;
		if (n - ini > m) {
			m = n - ini;
			c = ini;
		}

			n = n + 1;
			readant = read;
			std::cin >> read;
		}

	if (m == 0) std::cout << "HOY NO COMEN\n";
	else std::cout << c <<' '<< m<< '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}
