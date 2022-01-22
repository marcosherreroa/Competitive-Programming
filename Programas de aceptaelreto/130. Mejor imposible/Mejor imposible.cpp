//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	if ((x1 + y1) % 2 != (x2 + y2) % 2) std::cout << "IMPOSIBLE\n";
	else if (x1 == x2 && y1 == y2) std::cout << 0 << '\n';
	else if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) std::cout << 1 << '\n';
	else std::cout << 2 << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}