//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N, pesoMax;
	std::cin >> N >> pesoMax;
	if (N == 0 && pesoMax == 0)return false;

	std::vector<int> pesos(N);
	for (int i = 0; i < N; ++i) std::cin >> pesos[i];
	std::sort(pesos.begin(), pesos.end());

	long long int emparej = 0;
	int i = 0, j = pesos.size() - 1;
	while (i < j) {
		if (pesos[i] + pesos[j] <= pesoMax) {
			emparej += (j-i);
			++i;
		}
		else --j;
	}
	
	std::cout << emparej << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}