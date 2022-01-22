//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int kaprekar(std::string & n) {
	if (n == "0") return 8;

	if (n.size() == 4) {
		bool dist = false;

		for (int i = 1; !dist && i < n.size(); ++i) {
			if (n[i] != n[i - 1]) dist = true;
		}

		if (!dist) return 8;
	}

	int iter = 0;
	int crec, decrec, sol;
	while (n != "6174") {
		std::vector<int> num(4);
		int i = 0;
		while (i < n.length() && i < 4) {
			num[i] = int(n[i]) - int('0');
			++i;
		}

		while (i < 4) {
			num[i] = 0;
			++i;
		}

		std::sort(num.begin(), num.end());
		crec = num[0] + 10 * num[1] + 100 * num[2] + 1000 * num[3];
		decrec = num[3] + 10 * num[2] + 100 * num[1] + 1000 * num[0];
		
		if (crec >= decrec) sol = crec - decrec;
		else sol = decrec - crec;

		n = std::to_string(sol);
		++iter;
	}

	return iter;
}

void resuelveCaso() {
	std::string n;
	std::cin >> n;
	
	std::cout << kaprekar(n) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}

