//Marcos Herrero
#include <iostream>
#include <string>

void resuelveCaso() {
	std::string numEdu; std::string letrasEdu;
	std::string numMat; std::string letrasMat;

	std::string Edumat;
	std::cin >> Edumat;
	numEdu = Edumat.substr(0, 4);
	letrasEdu = Edumat.substr(4);

	long long int viejos = 0, nuevos = 0;
	std::string mat;
	std::cin >> mat;
	while (mat != "0") {
		numMat = mat.substr(0, 4);
		letrasMat = mat.substr(4);
		if (letrasMat < letrasEdu) ++viejos;
		else if (letrasMat > letrasEdu) ++nuevos;
		else if (numMat < numEdu)++viejos;
		else if(numMat > numEdu) ++nuevos;
		std::cin >> mat;
	}

	std::cout << viejos << ' ' << nuevos << '\n';
}

int main() {
	int n; 
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
	return 0;
}