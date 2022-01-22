//Marcos Herrero
#include <iostream>
#include <vector>

std::vector<int> diasAcum = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273,  304, 334, 365 };

void resuelveCaso() {
	int d,  m;
	std::cin >> d >> m;

	std::cout << 334 - diasAcum[m-1] + 31 - d << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}