//Marcos Herrero
#include <iostream>

bool resuelveCaso() {
	int P;
	std::cin >> P;
	if (P == 0) return false;

	int D, N, act = 0;
	for (int i = 0; i < P; ++i) {
		std::cin >> D >> N;
		if (D < act) {
			if ((act - D) % N == 0)++act;
			else act = ((act - D) / N +1)*N+D+1;
		}
		else act = D+1;

	}

	std::cout << act-1<<'\n';
	return true;
}


int main() {
	while (resuelveCaso());
}