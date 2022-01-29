//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0)return false;

	std::vector<int> dice1(n), dice2(n);

	for (int i = 0; i < n; ++i)std::cin >> dice1[i];
	for (int i = 0; i < n; ++i)std::cin >> dice2[i];
	
	std::sort(dice1.begin(), dice1.end());
	std::sort(dice2.begin(), dice2.end());

	int nless = 0, nequal = 0, caseswin1 = 0, casesstale = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && dice1[i - 1] < dice1[i]) {
			nless += nequal;
			nequal = 0;
		}

		while (nless < n && dice2[nless] < dice1[i]) ++nless;
		while (nless + nequal < n && dice2[nless + nequal] == dice1[i])++nequal;

		caseswin1 += nless;
		casesstale += nequal;
	}

	int caseslose1 = n * n - caseswin1 - casesstale;
	if (caseswin1 > caseslose1)std::cout << "PRIMERO\n";
	else if (caseswin1 < caseslose1)std::cout << "SEGUNDO\n";
	else std::cout << "NO HAY DIFERENCIA\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}