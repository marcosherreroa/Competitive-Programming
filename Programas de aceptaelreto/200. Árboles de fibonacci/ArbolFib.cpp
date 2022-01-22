//Marcos Herrero
#include <iostream>
#include <iomanip>
#include <cmath>

inline int fib(int n) {
	return round(pow((1 + sqrt(5)) / 2, n) / sqrt(5));
}

inline void imprimirArbol(int n, int numEspacios) {
	if (n == 0 || n == 1) {
		std::cout<< std::setw(numEspacios) <<"" << std::setw(0)<< n << '\n';
	}
	else {
		std::cout<<std::setw(numEspacios)<<""<<fib(n) << '\n';
		numEspacios += 3;
		imprimirArbol(n - 2,numEspacios);
		imprimirArbol(n - 1, numEspacios);
	}
}

inline bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n < 0) return false;

	int numEspacios = 0;
	imprimirArbol(n, numEspacios);
	std::cout <<"====\n";
	return true;
}

int main() {
	while (resuelveCaso());
}