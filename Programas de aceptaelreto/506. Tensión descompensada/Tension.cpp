//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int t1, t2; char aux;
	std::cin >> t1 >> aux >> t2;
	if (t1 >= t2)std::cout << "BIEN\n";
	else std::cout << "MAL\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}