//Marcos Herrero

#include <iostream>
#include <vector>
#include <cmath>

long long int mezcla(std::vector<long long int> & v, long long int ini, long long int fin, long long int m) {
	long long int r = 0;
	std::vector<long long int> w (fin - ini);
	long long int i = ini, j = m + 1, k = 0;
	while (i <= m && j < fin) {
		if (v[i] <= v[j]) {
			w[k] = v[i];
			++i;
		}
		else { 
			w[k] = v[j]; 
			r += abs(ini + k - j);
			++j;
		}
		++k;
	}

	while (i <= m) { 
		w[k] = v[i];
	           ++k;
	           ++i; 
	}

	while (j < fin) {
		w[k] = v[j]; 
		++k; 
		++j;
	}

	for (int i = 0; i < fin - ini; ++i)  v[i + ini] = w[i];
	return r;
}

long long int permut(std::vector<long long int> & v, long long int ini, long long int fin) {
	long long int r = 0;
	if (ini >= fin-1) return 0;

	else {
		long long int m = (ini + fin - 1) / 2;
		r += permut(v, ini, m + 1);
		r += permut(v, m + 1, fin);
		r += mezcla(v, ini, fin, m);

		return r;
	}
}

bool resuelveCaso() {
	long long int N;
	std::cin >> N;
	if (N == 0) return false;

	std::vector<long long int> v(N);
	for (long long int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << permut(v, 0 , N) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}