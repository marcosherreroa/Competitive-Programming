//Marcos herrero
#include <iostream>

void resuelveCaso() {
	int palom, cajas;
	std::cin >> palom >> cajas;
	if (palom > cajas)std::cout << "PRINCIPIO\n";
	else std::cout << "ROMANCE\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}