//Marcos Herrero
#include <iostream>

bool valida(int a, int b) {
	if (a < b) return b == a + 1 && a % 2 == 0;
	else return a == b + 1 && b % 2 == 0;
}

void resuelveCaso() {
	int a, b; char aux;
	std::cin >> a >>aux>> b;
	
	if (valida(a, b))std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}