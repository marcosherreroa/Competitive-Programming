//Marcos Herrero

#include <iostream>
#include <vector>
#include <algorithm>

/*

dist(i,j) = 0 si i <= j <= i+T-1
dist(i,j) = i-j si i < j
dit(i,j) = j - i - T + 1 si i > i+T-1

sol = min : 0 <= i <= E-T: (sum  : 0<= j <= E : personas[j] * dist(i,j))

*/


bool resuelveCaso() {
	int longTren, longAnden;
	std::cin >> longTren >> longAnden;

	if (longTren == 0 && longAnden == 0)return false;

	std::vector<int> personas(longAnden);
	for (int i = 0; i < longAnden; ++i) std::cin >> personas[i];

	long long int funcion = 0; // funcion a minimizar: 
	int sumaPersonasIzq = 0, sumaPersonasDer = 0;

	for (int i = longTren; i < longAnden; ++i) { //valor inicial : tren a la izquierda
		funcion += personas[i] * (i - longTren + 1);
		sumaPersonasDer += personas[i];
	}

	long long int sol = funcion; // el minimo
	for (int i = 0; i < longAnden - longTren; ++i) {
		funcion -= sumaPersonasDer;
		sumaPersonasDer -= personas[i + longTren];

		sumaPersonasIzq += personas[i];
		funcion += sumaPersonasIzq;

		if (funcion < sol) sol = funcion;
	}

	std::cout << sol << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}