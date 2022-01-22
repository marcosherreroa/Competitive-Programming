//Marcos Herrero

#include <iostream>

int elevar(long long int x, long long int n) {
	x = x % 31543;
	if (n == 0) return 1;
	else if (n == 1) return x % 31543;
	else if (n % 2 == 0) {
		long long int p = elevar(x, n / 2) % 31543;
		return (p * p )% 31543;
	}
	else {
		long long int p = elevar(x, n / 2) % 31543;
		return (p * p * x) % 31543;
	}
}

bool resuelveCaso() {
	long long int x, n;
	std::cin >> x >> n;
	if (x == 0 && n == 0) return false;

	std::cout << elevar(x, n) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}