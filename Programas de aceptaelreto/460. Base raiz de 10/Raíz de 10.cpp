//Marcos Herrero

#include <iostream>
#include <string>

bool resuelveCaso() {
	std::string N;
	std::cin >> N;
	if (!std::cin)return false;

	std::cout << N[0];
	for (int i = 1; i < N.size(); ++i) {
		std::cout << 0 << N[i];
	}
	std::cout << '\n';

	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
}