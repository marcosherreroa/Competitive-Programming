//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int C, N;
	std::cin >> C >> N;
	if (C == 0 && N == 0)return false;

	std::vector<int> alturas(C, 0);
	int I, R, P;
	for (int i = 0; i < N; ++i) {
		std::cin >> I >> R >> P;

		switch (I) {
		case 1: {
			if (R == 0 || R == 180) {
				int m = alturas[P-1];
				for (int i = P; i < P + 4; ++i) {
					if (alturas[i - 1] > m) m = alturas[i - 1];
				}
				for (int i = P; i < P + 4; ++i) alturas[i - 1] = m + 1;
			}
			else alturas[P-1] += 4;
			break;
		}

		case 2: {
			if (R == 0) {
				int m = alturas[P - 1];
				for (int i = P; i < P + 3; ++i) {
					if (alturas[i - 1] > m)m = alturas[i - 1];
				}

				alturas[P - 1] = m+2;
				alturas[P] = m + 1;
				alturas[P + 1] = m + 1;
			}
			else if (R == 90) {
				int m = std::max(alturas[P - 1], alturas[P]);
				alturas[P - 1] = m + 1;
				alturas[P] = m + 3;
			}
			else if (R == 180) {
				if (alturas[P + 1] < alturas[P - 1] || alturas[P + 1] < alturas[P]) {
					int m = std::max(alturas[P - 1], alturas[P]);
					alturas[P - 1] = m + 1;
					alturas[P] = m + 1;
					alturas[P + 1] = m + 1;
				}
				else {
					int m = alturas[P + 1];
					for (int i = P; i < P + 3; ++i)alturas[i - 1] = m+2;
				}
			}

			else {
				if (alturas[P-1] < alturas[P] - 1) {
					alturas[P - 1] = alturas[P] + 1;
					++alturas[P];
				}
				else {
					alturas[P] = alturas[P - 1] + 3;
					alturas[P - 1] += 3;
				}
			}

			break;
			}
				
		case 3: {
			if (R == 0) {
				int m = alturas[P - 1];
				for (int i = P; i < P + 3; ++i) {
					if (alturas[i - 1] > m)m = alturas[i - 1];
				}

				alturas[P - 1] = m + 1;
				alturas[P] = m + 1;
				alturas[P + 1] = m + 2;
			}
			else if (R == 90) {
				if (alturas[P] < alturas[P-1] - 1) {
					alturas[P] = alturas[P-1] + 1;
					++alturas[P-1];
				}
				else {
					alturas[P - 1] = alturas[P]+3;
					alturas[P] += 3;
				}
			}
			else if (R == 180) {
				if (alturas[P - 1] < alturas[P] || alturas[P -1] < alturas[P+1]) {
					int m = std::max(alturas[P ], alturas[P+1]);
					alturas[P-1] = m + 1;
					alturas[P] = m + 1;
					alturas[P +1] = m + 1;
				}
				else {
					alturas[P] = alturas[P - 1] + 2;
					alturas[P + 1] = alturas[P - 1] + 2;
					alturas[P - 1] += 2;
				}
			}
			else {
				int m = std::max(alturas[P - 1], alturas[P]);
				alturas[P - 1] = m+3;
				alturas[P] = m + 1;
			}

			break;
		}
		case 4: {
			int m = std::max(alturas[P - 1], alturas[P]);
			alturas[P - 1] = m+2;
			alturas[P] = m+2;
			break;
		}

		case 5: {
			if (R == 0 || R == 180) {
				if (alturas[P-1] < alturas[P + 1] && alturas[P ] < alturas[P + 1]) {
					alturas[P] = alturas[P + 1] + 1;
					alturas[P - 1] = alturas[P + 1];
					++alturas[P + 1];
				}
				else {
					int m = std::max(alturas[P-1], alturas[P]);
					alturas[P - 1] = m + 1;
					alturas[P] = m + 2;
					alturas[P + 1] = m + 2;
				}
			}
			else {
				if (alturas[P] < alturas[P - 1]) {
					alturas[P] = alturas[P - 1] + 1;
					alturas[P - 1] += 2;
				}
				else {
					alturas[P - 1] = alturas[P] +3;
					alturas[P] += 2;;
				}
			}

			break;
		}
				
		case 6: {
			if (R == 0) {
				int m = alturas[P - 1];
				for (int i = P; i < P + 3; ++i) {
					if (alturas[i - 1] > m) m = alturas[i - 1];
				}

				alturas[P - 1] = m + 1;
				alturas[P] = m + 2;
				alturas[P + 1] = m + 1;
			}
			else if (R == 90) {
				if (alturas[P] < alturas[P - 1]) {
					alturas[P] = alturas[P - 1] + 2;
					++alturas[P - 1];
				}
				else {
					alturas[P - 1] = alturas[P]+2;
					alturas[P] += 3;
				}
			}

			else if (R == 180) {
				if (alturas[P] < alturas[P - 1] || alturas[P] < alturas[P + 1]) {
					int m = std::max(alturas[P - 1], alturas[P + 1]);
					alturas[P - 1] = m + 1;
					alturas[P] = m + 1;
					alturas[P + 1] = m + 1;
				}
				else {
					alturas[P - 1] = alturas[P] + 2;
					alturas[P + 1] = alturas[P] + 2;
					alturas[P] += 2;
				}
			}
			else {
				if (alturas[P-1] < alturas[P]) {
					alturas[P-1] = alturas[P] + 2;
					++alturas[P];
				}
				else {
					alturas[P] = alturas[P-1] + 2;
					alturas[P-1] += 3;
				}
			}

			break;
		}

		case 7: {
			if (R == 0 || R == 180) {
				if (alturas[P] < alturas[P - 1] && alturas[P + 1] < alturas[P - 1]) {
					alturas[P] = alturas[P - 1] + 1;
					alturas[P + 1] = alturas[P - 1];
					++alturas[P - 1];
				}
				else {
					int m = std::max(alturas[P], alturas[P + 1]);
					alturas[P - 1] = m + 2;
					alturas[P] = m + 2;
					alturas[P + 1] = m + 1;
				}
			}
			else {
				if (alturas[P - 1] < alturas[P]) {
					alturas[P - 1] = alturas[P] + 1;
					alturas[P] += 2;
				}
				else {
					alturas[P] = alturas[P-1] +3;
					alturas[P - 1] += 2;
					
				}
			}

			break;
		}
		}
	}

	std::cout << alturas[0];
	for (int i = 1; i < C; ++i) std::cout <<' '<<alturas[i];
	std::cout << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}