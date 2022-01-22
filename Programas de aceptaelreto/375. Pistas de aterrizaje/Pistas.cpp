//Marcos Herrero

#include <iostream>
#include <string>
#include <iomanip>

bool resuelveCaso() {
	std::string linea;
	getline(std::cin, linea);

	if (!std::cin)return false;

	if (linea.size() == 2) {
		int num = 10*(int(linea[0]) - int('0')) + int (linea[1]) -int ('0');
		if(num<= 18)std::cout<< std::setfill('0')<<std::setw(2) << 18 + num;
		else std::cout <<std::setfill('0')<<std::setw(2)<< num - 18;
	}

	else {
		int num = 10 * (int(linea[0]) - int('0')) + int(linea[1]) - int('0');;
		char letra = linea[2];

		if(num <= 18)std::cout <<std::setfill('0')<< std::setw(2) << 18+num;
		else std::cout<<std::setfill('0')<<std::setw(2)<< num - 18;

		if (letra == 'L')std::cout << 'R';
		else if (letra == 'C')std::cout << 'C';
		else std::cout << 'L';
	}

	std::cout << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}