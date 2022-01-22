//Marcos Herrero

#include <iostream>
#include <algorithm>

void resuelveCaso() {
	long long int a1, b1, a2, b2;
	std::cin >> a1 >> b1 >> a2 >> b2;

	if (a1 > b1) std::swap(a1, b1);
    if (a2 > b2) std::swap(a2, b2);

	if ((a1<= a2 && a2< b1)|| (a1 < b2 && b2 <= b1) || (a2 <= a1 && a1< b2) || a2 < b1 && b1 <= b2)std::cout << "SOLAPADOS\n";
	else std::cout << "SEPARADOS\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}