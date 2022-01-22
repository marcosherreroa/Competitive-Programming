//Marcos Herrero
#include <iostream>
#include <algorithm>;


int mcd(int a, int b) {
	if (b > a) std::swap(b, a);
	if (b == 0) return a;
	else return mcd(b, a % b);
}

void resuelveCaso() {
	int p;
	std::cin >> p;

	std::cout << 10000 / mcd(10000, p)<<'\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();

}