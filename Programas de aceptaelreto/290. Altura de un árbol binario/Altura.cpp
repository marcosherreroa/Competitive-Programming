//Marcos Herrero
#include <iostream>
#include <algorithm>

int altura(char raiz) {
	if (raiz == '.') return 0;
	else {
		char l, r;
		std::cin >> l;
		int sol1 = altura(l);
		std::cin >> r;
		int sol2 = altura(r);
		return 1 + std::max(sol1, sol2);
	}
}

void resuelveCaso(){
	char raiz;
	std::cin >> raiz;
	std::cout << altura(raiz) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}