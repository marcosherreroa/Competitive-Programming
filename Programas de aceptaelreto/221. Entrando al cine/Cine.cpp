//Marcos Herrero

#include <iostream>


void resuelveCaso() {
	int N;
	std::cin >> N;

	int aux, sol = 0, cont = 0; bool impar = false, OK = true;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		++cont;
		if (aux % 2 == 1) impar = true;
		else {
			sol = cont;
			if (impar) OK = false;
		}
		
	}

	if (OK)std::cout << "SI " << sol<<'\n';
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}