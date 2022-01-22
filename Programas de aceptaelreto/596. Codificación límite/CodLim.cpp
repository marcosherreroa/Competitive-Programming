#include <iostream>
#include <string>

bool resuelveCaso() {
	std::string arb;
	std::cin >> arb;

	if (!std::cin) return false;

	for (int i = 0; i < arb.length()-2; ++i) {
		if (arb[i] != '.' && arb[i+1] == '.' && arb[i+2] == '.') std::cout << arb[i];
	}

	std::cout << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}