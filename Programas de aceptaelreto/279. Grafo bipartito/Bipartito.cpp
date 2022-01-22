//Marcos Herrero
#include <iostream>
#include <vector>
#include <cmath>

using tLista = std::vector<std::vector<int>>;

bool visitar(int x, int color, tLista const & adyac, std::vector<int> & colorear) {
	bool OK = true;
	colorear[x] = color;

	for (int i = 0; OK && i < adyac[x].size(); ++i) {
		if (colorear[adyac[x][i]] == 0) OK = visitar(adyac[x][i], -color, adyac, colorear);
		else if (colorear[adyac[x][i]] == color) OK = false;
	}

	return OK;
}

bool resuelveCaso() {
	int N, A;
	std::cin >> N >> A;


	if (!std::cin) return false;

	std::vector<std::vector<int>> adyac(N);
	int x, y;
	for (int i = 0; i < A; ++i) {
		std::cin >> x >> y;
		adyac[x].push_back(y);
		adyac[y].push_back(x);
	}

	std::vector<int> colorear(N, 0);
	bool OK = true;
	for (int i = 0; OK && i < N; ++i) {
		if (colorear[i] == 0) OK = visitar(i, 1, adyac, colorear);
	}

	if (OK) std::cout << "SI\n";
	else std::cout << "NO\n";

	
		/*for (int i = 1; i < A; ++i) {
			std::cin >> x >> y;
			if (v[x] == 0 && v[y] == 0) {
				v[x] = k;
				v[y] = -k;
				cod.push_back(k);
				++k;
			}

			else if (v[y] == 0) v[y] = -v[x];
			else if (v[x] == 0) v[x] = -v[y];
			else if ((cod[abs(v[x])-1] == cod[abs(v[y])-1] && v[x]/abs(v[x]) == v[y]/abs(v[y]))||
				(cod[abs(v[x]) - 1] == -cod[abs(v[y]) - 1] && v[x]/abs(v[x]) == -v[y]/abs(v[y]))) bipart = false;

			else if (abs(cod[abs(v[x]) - 1]) < abs(cod[abs(v[y]) - 1])) {
				int ant = cod[abs(v[y]) - 1], nuevo = -(v[x]/abs(v[x])) * (v[y]/abs(v[y]))*cod[abs(v[x]) - 1];
				for (int i = 0; i < cod.size(); ++i) {
					if (cod[i] == ant)cod[i] = nuevo;
				}
			}

			else if (abs(cod[abs(v[y]) - 1]) < abs(cod[abs(v[x]) - 1])) {
				int ant = cod[abs(v[x]) - 1], nuevo = -(v[x] / abs(v[x])) * (v[y] / abs(v[y]))*cod[abs(v[x]) - 1];
				for (int i = 0; i < cod.size(); ++i) {
					if (cod[i] == ant)cod[i] = nuevo;
				}
			}
		}*/

	return true;
}

int main() {
	while (resuelveCaso());
}