//Marcos Herrero

#include <iostream>
#include <string>

void resuelveCaso() {
	std::string p1, p2, aux;
	std::cin >> p1 >> aux >> p2;

	if (p1.size() != p2.size())std::cout << "NO TAUTOLOGIA\n";
	else {
		bool taut = true;

		for (int i = 0; taut && i < p1.size(); ++i) {
			if(tolower(p1[i]) != tolower(p2[i]))taut = false;
		}

		if (taut) std::cout << "TAUTOLOGIA\n";
		else std::cout << "NO TAUTOLOGIA\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}