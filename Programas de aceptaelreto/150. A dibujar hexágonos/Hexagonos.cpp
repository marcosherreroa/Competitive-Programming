//Marcos Herrero
#include <iostream>
#include <iomanip>

bool resuelveCaso() {
	int l; char c;
	std::cin >> l >> c;
	if (l == 0 && c == '0')return false;

	for (int i = 1; i < l; ++i) {
		std::cout << std::setfill(' ')<< std::setw(l - i) << ' '
			<< std::setfill(c) << std::setw(l + 2 * (i-1)) << c << '\n';
	}

	if( l >= 1) std::cout << std::setfill(c) << std::setw(3 * l - 2) << c<<'\n' ;

	for (int i = 1; i < l ; ++i) {
		std::cout <<std::setfill(' ')<< std::setw(i) << ' '
			<< std::setfill(c) << std::setw(3*l-2*i-2) <<c<<'\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
}