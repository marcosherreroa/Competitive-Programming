//Marcos Herrero
#include <iostream>


bool polidivisible(long long int N, long long int l) {
	if (N / 10 == 0) return true;
	else return (N % l == 0 && polidivisible(N / 10, l-1));
}

bool resuelveCaso() {
	long long int N;
	std::cin >> N;
	if (!std::cin)return false;

	long long int n = N, l = 0;
	while (n > 0) {
		++l;
		n /= 10;
	}

	if (polidivisible(N,l)) std::cout << "POLIDIVISIBLE\n";
	else std::cout << "NO POLIDIVISIBLE\n";

	return true;
}

int main() {
	while (resuelveCaso());
}