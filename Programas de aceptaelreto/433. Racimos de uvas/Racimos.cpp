//Marcos Herrero
#include <iostream>

int intsqrt(int n) {
	int r = 1;
	while (r*r < n)++r;
	return r;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::cout << intsqrt(1 + 8 * N) / 2 << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}