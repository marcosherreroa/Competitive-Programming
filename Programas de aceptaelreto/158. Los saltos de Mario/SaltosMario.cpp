//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int N;
	std::cin >> N;

	int heigant, heig, up = 0, down = 0;
	std::cin >> heigant;

	for (int i = 1; i < N; ++i) {
		std::cin >> heig;
		if (heig > heigant) ++up;
		else if (heig < heigant)++down;
		heigant = heig;
	}

	std::cout << up << ' ' << down << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}