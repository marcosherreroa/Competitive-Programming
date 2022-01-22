//Marcos Herrero

#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	int talla;
	std::vector<bool> distrib(N); std::vector<int> zap1, zap2;
	for (int i = 0; i < N; ++i) {
		std::cin >> talla;
		if (talla > 0) {
			distrib[i] = true;
			zap1.push_back(talla);
		}
		else {
			distrib[i] = false;
			zap2.push_back(-talla);
		}
	}

	std::sort(zap1.begin(), zap1.end());
	std::sort(zap2.begin(), zap2.end());

	int j1 = 0, j2 = 0;

	if (distrib[0]) {
		std::cout << zap1[j1];
		++j1;
	}

	else {
		std::cout << -zap2[j2];
		++j2;
	}

	for (int i = 1; i < N; ++i) {
		if (distrib[i]) {
			std::cout << ' ' << zap1[j1];
			++j1;
		}
		else {
			std::cout <<' '<< -zap2[j2];
			++j2;
		}
	}

	std::cout << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}