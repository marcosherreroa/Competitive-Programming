//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

struct coord {
	int x;
	int y;
};

struct punto {
	int coord;
	bool principio;
};

bool operator<(punto const & p1, punto const & p2) {
	return p1.coord < p2.coord || (p1.coord == p2.coord && p1.principio == true && p2.principio == false);
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;

	std::vector<punto> extrIntervalos;
	int x, y;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		extrIntervalos.push_back({ x - y, true });
		extrIntervalos.push_back({ x + y, false });
	}
	std::sort(extrIntervalos.begin(), extrIntervalos.end());

	int max =1 , cont = 0;
	for (int i = 0; i < extrIntervalos.size(); ++i) {
		if (extrIntervalos[i].principio)++cont;
		else --cont;

		if (cont > max)max = cont;
	}

	std::cout << max << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}