//Marcos Herrero
#include <iostream>
#include <vector>

bool resuelveCaso() {
	int dim, reinas;
	std::cin >> dim >> reinas;
	if (dim == 0 && reinas == 0)return false;

	std::vector<bool> filas(dim, false), columnas(dim, false), d1(2 * dim - 1, false), d2(2*dim-1, false);

	int x, y; bool OK = true;
	for (int i = 0; i < reinas; ++i) {
		std::cin >> x >> y;
		if (OK) {
			if (filas[x - 1] || columnas[y-1] || d1[x-y+dim-1] || d2[x+y]) OK = false;
			else {
				filas[x - 1] = true;
				columnas[y - 1] = true;
				d1[x - y + dim - 1] = true;
				d2[x + y] = true;
			}
		}
	}

	if (OK) std::cout << "NO\n";
	else std::cout << "SI\n";

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
}