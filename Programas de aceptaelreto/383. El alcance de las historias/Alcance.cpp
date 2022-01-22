//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	int N;
	std::cin >> N;

	int pag;
	std::cin >> pag;
	int ult = pag;
	std::cin >> pag;
	int dif = ult - pag;
	if (pag > ult) ult = pag;
	for (int i = 2; i < N; ++i) {
		std::cin >> pag;
		if(ult -pag > dif) dif = ult - pag;
		if (pag > ult) ult = pag;
	}

	std::cout << dif << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}