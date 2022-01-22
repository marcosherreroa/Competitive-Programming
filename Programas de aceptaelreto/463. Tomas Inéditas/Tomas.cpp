//Marcos Herrero

#include <iostream>
#include <string>
#include <vector>
#include <queue>


bool resuelveCaso() {
	std::string  frase;
	std::cin >> frase;
	if (!std::cin)return false;

	int altura = 0, maxAltura = 0;
	for (int i = 0; i < frase.size(); ++i) {
		if (frase[i] == 'S')++altura;
		else if (frase[i] == 'B')--altura;

		if (altura > maxAltura)maxAltura = altura;
	}

	std::vector<std::vector<char>> alturas(maxAltura+1, std::vector<char>(frase.size(), ' '));
	altura = 0;
	for (int i = 0; i < frase.size(); ++i) {
		if (frase[i] == 'I')alturas[altura][i]= '_';
		else if (frase[i] == 'S') {
			alturas[altura][i]=  '/';
			++altura;
		}
		else {
			--altura;
			alturas[altura][i] = '\\';
		}
	}

	for (int i = 0; i < frase.size() + 2; ++i)std::cout << '#';
	std::cout << '\n';

	for (int i = alturas.size()-1; i >= 0; --i) {
		std::cout << '#';
		for (int j = 0; j < frase.size(); ++j) {
			std::cout<<alturas[i][j];
		}
		std::cout << "#\n";
	}


	for (int i = 0; i < frase.size() + 2; ++i)std::cout << '#';
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}