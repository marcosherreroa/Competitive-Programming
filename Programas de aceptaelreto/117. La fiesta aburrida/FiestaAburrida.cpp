//Marcos Herrero
#include <iostream>
#include <string>

void resuelveCaso() {
	std::string aux, nombre;
	std::cin >>aux >> nombre;
	std::cout << "Hola, " << nombre<<".\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}