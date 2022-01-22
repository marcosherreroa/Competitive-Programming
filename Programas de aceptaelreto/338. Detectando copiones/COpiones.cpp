//Marcos Herrero
#include <iostream>
#include <unordered_map>

bool resuelveCaso() {
	int N, K;
	std::cin >> N >> K;

	if (!std::cin)return false;

	std::unordered_map<int, int> examenes; int examen; int copias = 0, copiasDetec = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> examen;
		if (examenes.count(examen) == 1) {
			++copias;
			if (examenes[examen] >= i - K) ++copiasDetec;
		}
		
		examenes[examen] = i;
	}

	std::cout << copias << ' ' << copiasDetec << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}