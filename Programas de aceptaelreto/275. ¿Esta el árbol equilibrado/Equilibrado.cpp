//Marcos Herrero
#include <iostream>
#include <algorithm>

bool equilibrado(char raiz, int & altura) {
	 if (raiz == '.') {
		altura = 0;
		return true;
	}

	else {
		char rl, rr;int  alt1, alt2;
		std::cin >> rl;
		bool OK1 = equilibrado(rl, alt1);
		std::cin >> rr;
		bool OK2 = equilibrado(rr, alt2);
		altura = 1+ std::max(alt1, alt2);
		return OK1 && OK2 && abs(alt2 - alt1) <= 1;
	}
}

void resuelveCaso() {
	char raiz;
	std::cin >> raiz;
	
	int numbolas;
	if (equilibrado(raiz, numbolas))std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i< n; ++i) resuelveCaso();
}