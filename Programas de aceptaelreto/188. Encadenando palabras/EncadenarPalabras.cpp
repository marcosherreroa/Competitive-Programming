//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>

void split(std::vector<std::string> & palabras, std::string const & linea) {
	int lastpos= 0, len = 0;
	for (int i = 0; i < linea.size(); ++i) {
		if (linea[i] == ' ') {
			palabras.push_back(linea.substr(lastpos, len));
			lastpos = i + 1;
			len = 0;
		}
		else ++len;
	}

	palabras.push_back(linea.substr(lastpos));
}

bool resuelveCaso() {
	std::string linea;
	getline(std::cin, linea);

	if (!std::cin) return false;

	std::vector<std::string> palabras;
	split(palabras, linea);
	bool OK = true;

	std::string silabaFin = palabras[0].substr(palabras[0].length() - 2), silabaIni;
	for (int i = 1; OK && i < palabras.size(); ++i) {
		silabaIni = palabras[i].substr(0, 2);
		if (silabaFin != silabaIni) OK = false;
		silabaFin = palabras[i].substr(palabras[i].length() - 2);
	}
	
	if (OK)std::cout << "SI\n";
	else std::cout << "NO\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
}