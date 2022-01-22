//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>

bool resuelveCaso() {
	int nbilletes, npart;
	std::cin >> nbilletes >> npart;
	if (nbilletes == 0 && npart == 0)return false;

	std::vector<std::queue<int>> reparto(npart); std::vector<int> sumas(npart); int billete;
	while (nbilletes > 0) {
		for (int i = 0; nbilletes > 0 && i < npart; ++i) {
			std::cin >> billete;
			reparto[i].push(billete);
			sumas[i] += billete;
			--nbilletes;
		}
	}

	for (int i = 0; i < npart; ++i) {
		std::cout << sumas[i] << ':';
		while (!reparto[i].empty()) {
			std::cout << ' ' <<reparto[i].front();
			reparto[i].pop();
		}
		std::cout << '\n';
	}

	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}