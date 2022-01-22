//Marcos Herrero
#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <unordered_map>

struct mayusNum {
	std::string correct;
	int numMayus;
};

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::unordered_map<std::string, mayusNum> correctos;
	std::vector<std::string> vars(N);
	std::string var, varminus;
	int mayus;

	for (int i = 0; i < N; ++i) {
		mayus = 0;
		std::cin >> var;
		varminus = var;

		for (int j = 0; j < var.length(); ++j) {
			if (isupper(var[j])) {
				++mayus;
				varminus[j] = tolower(var[j]);
			}
		}

		vars[i] = varminus;

		if (!correctos.count(varminus) || correctos[varminus].numMayus < mayus) {
			correctos[varminus] = { var, mayus };
		}
		
	}

	for (int i = 0; i < N; ++i) {
		std::cout << correctos[vars[i]].correct << '\n';
	}

	std::cout << "---\n";

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}