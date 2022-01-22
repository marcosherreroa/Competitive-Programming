//Marcos Herrero

#include <iostream>
#include <unordered_map>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	std::unordered_map<int, int> mapa; int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		++mapa[aux];
	}

	int max = mapa.begin()->first, maxvalor = mapa.begin()->second;
	for (auto it = mapa.begin(); it != mapa.end(); ++it) {
		if (it->second > maxvalor) {
			maxvalor = it->second;
			max = it->first;
		}
	}

	std::cout << max << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}