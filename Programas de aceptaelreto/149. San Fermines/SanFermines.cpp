//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin)return false;

	int e, max;
	std::cin >> max;
	for (int i = 1; i < n; ++i) {
		std::cin >> e;
		if (e > max)max = e;
	}

	std::cout << max << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}