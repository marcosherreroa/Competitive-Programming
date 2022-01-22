//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	long long int mayores = 0, menores = 0, unos = 0, ceros = 0;
	double aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		if (aux == 0) ++ceros;
		else if (aux > 1) ++mayores;
		else if (aux < 1) ++menores;
		else ++unos;
	}

	std::cout << ((mayores+unos)*(mayores+unos - 1) / 2) + ((menores+unos)*(menores+unos- 1) / 2)+ (N-ceros)*ceros - (unos*(unos-1)/2)<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}