//Marcos Herrero

#include <iostream>

void resuelveCaso() {
	int N, M;
	std::cin >> N >> M;
	std::cout << 2 * N*M + N + M<<'\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}