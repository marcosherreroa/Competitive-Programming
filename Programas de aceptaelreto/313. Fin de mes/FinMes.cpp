//Marcos Herrero

#include <iostream>

void resuelveCaso() {
	int saldo, var;
	std::cin >> saldo >> var;
	if (saldo + var >= 0)std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}