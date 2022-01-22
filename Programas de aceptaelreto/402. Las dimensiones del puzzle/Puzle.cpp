//Marcos Herrero

#include <iostream>
/*

{0<=a<=l<=N && a*l = N}

*/
int longit(int N) {
	int r;

	r = 1;
	while ((r + 1)  * (r + 1) <= N) ++r;

	while (N % r != 0) --r;

	return N / r;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::cout << longit(N)<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}