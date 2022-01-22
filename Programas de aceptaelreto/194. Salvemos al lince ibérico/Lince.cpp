//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>

void resuelveCaso() {
	std::string linea;
    getline(std::cin, linea);

	std::vector<bool> cubierto(linea.length(), false);
	int tunel = 0;
	for (int i = 1; i < linea.length(); ++i) {
		if (!cubierto[i - 1] && linea[i - 1] == '.') {
			cubierto[i - 1] = true;
			cubierto[i] = true;
			cubierto[i + 1] = true;
			++tunel;
		}
	}

	if (!cubierto[linea.length() - 1] && linea[linea.length() - 1] == '.')++tunel;

	std::cout << tunel<< '\n';
}

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore(1);
	for (int i = 0; i < n; ++i)resuelveCaso();
}