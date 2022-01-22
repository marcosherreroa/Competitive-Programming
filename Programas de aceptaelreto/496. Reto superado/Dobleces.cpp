//Marcos Herrero
#include <iostream>
#include <cmath>

bool resuelveCaso() {
	int grosor, altura;
	std::cin >> grosor >> altura;
	if (!std::cin)return false;

	std::cout << ceil(log10(altura) / log10(2) - log10(grosor*0.000001) / log10(2))<<'\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}