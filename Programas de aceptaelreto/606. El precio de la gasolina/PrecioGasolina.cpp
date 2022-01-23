#include <iostream>
#include <vector>
#include <algorithm>

/*
subsec[i], 0<= i <= n, longitud de la subsecuencia creciente más larga de v[0...i]  que acaba en v[i]

subsec[0] = 1

subsec[i] = 1 si no existe j, 0 <= j <= i-1 tal que v[j] < v[i[
subsec[i] = 1 + max : 0 <= j <= i-1 && v[j] < v[i] : subsec[i] 
*/

bool resuelveCaso() {
	int N;

	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> v(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> v[i];
	}

	std::vector<int> subsec(N);
	subsec[0] = 1;

	int maximum;
	for (int i = 1; i < N ; ++i) {
		maximum = 0;

		for (int j = 0; j < i; ++j) {
			if (v[j] < v[i] && subsec[j] > maximum) {
				maximum = subsec[j];
			}
		}

		subsec[i] = 1 + maximum;
	}

	maximum = 0;

	for (int i = 0; i < N; ++i) {
		if (subsec[i] > maximum) {
			maximum = subsec[i];
		}
	}
	
	std::cout << maximum << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}