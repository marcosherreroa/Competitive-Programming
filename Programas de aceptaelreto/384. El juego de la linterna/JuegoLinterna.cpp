//Marcos Herrero

#include <iostream>
#include <vector>
#include<algorithm>

bool encontrado2(std::vector<long int> const & v, int N) {
	std::vector<long int> inis;
	std::vector<long int> fins;

	bool OK = false;
	int minl = v[0];
	int maxr = v[1];

	for (int i = 2; !OK && i < N; ++i) {
		if (v[i-1] < minl) {
			if (minl < maxr) {
				inis.push_back(minl);
				fins.push_back(maxr);
			}
			minl = v[i - 1];
			maxr = v[i];
		}

		else if (v[i] > maxr) maxr = v[i];

	if (v[i] > minl && v[i] < maxr) OK = true;
	for (int j = inis.size()-1; !OK && j >= 0 && inis[j]< v[i]; --j) {
				if (fins[j] > v[i]) OK = true;
		}
	}

	return OK;
}


bool encontrado(std::vector<long int> const & v, int ini, int fin ) {
	if (ini >= fin - 2) return false;
	else {
		int max, posmax;

		max = v[ini];
		posmax = ini;
		for (int i = ini + 1; i < fin; ++i) {
			if (v[i] > max) {
				max = v[i];
				posmax = i;
			}
		}

		bool OK = encontrado(v, ini, posmax) || encontrado(v, posmax + 1, fin);

		int minl = v[ini];
		for (int i = ini + 1; !OK && i < posmax; ++i) {
			if (v[i] < minl) minl = v[i];
		}

		for (int i = posmax + 1; !OK && i < fin; ++i) {
			if (v[i] > minl) OK = true;
		}

		return OK;
	}
}

bool resuelveCaso() {
	long int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<long int> v(N);

	for (long int i = 0; i < N; ++i) std::cin >> v[i];

	if (encontrado2(v, N)) std::cout << "ELEGIR OTRA\n";
	else std::cout<<"SIEMPRE PREMIO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}