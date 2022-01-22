//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	long long int N;
	std::cin >> N;
	long long int sol = 0;
	for (long long int i = 5; i <= N; i *= 5) sol += N / i;
	std::cout << sol << '\n';;
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}