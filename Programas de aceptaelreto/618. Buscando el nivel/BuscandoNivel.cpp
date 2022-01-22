//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>

bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (n == 0)return false;

	std::vector<int> empieza(n+1);

	int acum = 0, esp;
	for (int i = 0; i < n; ++i) {
		empieza[i] = acum;
		std::cin >> esp;
		acum += esp;
	}

	empieza[n] = acum;

	int q;
	std::cin >> q;

	int a, b;
	for (int i = 0; i < q; ++i) {
		std::cin >> a >> b;

		std::cout << empieza[b - 1] - empieza[a]<<'\n';
	}

	std::cout << "---\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}