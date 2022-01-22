//Marcos Herrero
#include <iostream>
#include <string>

bool hyperpar(std::string const & n) {
	bool sol = true;
	for (int i = 0; sol && i < n.length(); ++i) {
		if ((int(n[i]) - int('0')) % 2 == 1) sol = false;
	}

	return sol;
}

bool resuelveCaso() {
	std::string n;
	std::cin >> n;
	if (n[0] == '-') return false;

	if (hyperpar(n))std::cout << "SI\n";
	else std::cout << "NO\n";
	

	return true;
}

int main() {
	while (resuelveCaso());
}