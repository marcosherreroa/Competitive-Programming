//Marcos Herrero
#include <iostream>

void resuelveCaso() {
	long long int min, max, temp;
	int nmin = 1, nmax = 1;

	std::cin >> min;
	max = min;

	std::cin >> temp;
	while (temp != 0) {
		if (temp > max) {
			max = temp;
			nmax = 1;
		}
        
		else if (temp == max)++nmax;

		if (temp < min) {
			min = temp;
			nmin = 1;
		}

		else if (temp == min)++nmin;

		std::cin >> temp;
	}

	std::cout << min << ' ' << nmin << ' ' << max << ' ' << nmax << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}