//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;

	bool I = false, D = false; char aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		if (aux == 'I')I = true;
		if (aux == 'D') D = true;
	}
	
	if (I && D) std::cout << "ALGUNO NO COME\n";
	else std::cout << "TODOS COMEN\n";
	return true;
}

int main() {
	while (resuelveCaso());
}