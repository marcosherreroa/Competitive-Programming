//Marcos Herrero
#include <iostream>

bool bienDecorado(char raiz, int & numbolas) {
	if (raiz == '*') {
		numbolas = 1;
		return true;
	}
	else if (raiz == '.') {
		numbolas = 0;
		return true;
	}

	else {
		char rl, rr;int  b1, b2;
		std::cin >> rl;
		bool OK1 = bienDecorado(rl, b1);
		std::cin >> rr;
		bool OK2 = bienDecorado(rr, b2);
		numbolas = b1 + b2;
		return OK1 && OK2 && abs(b2 - b1) <= 1;
	}
}

bool resuelveCaso() {
	char raiz;
	std::cin >> raiz;
	if (!std::cin) return false;

	int numbolas;
	if (bienDecorado(raiz, numbolas))std::cout << "OK\n";
	else std::cout << "KO\n";
	return true;
}

int main() {
	while (resuelveCaso());
}