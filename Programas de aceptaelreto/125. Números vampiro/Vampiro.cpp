//Marcos Herrero

#include <iostream>
#include <cmath>

int numDigitos(int num) {
	int cont = 0;
	if (num == 0) return 1;
	else {
		while (num > 0) {
			++cont;
			num /= 10;
		}
		return cont;
	}
}

bool buscarColmillos(int num, int vcifras, int e10ncifras, int colmillo1, int e10cifrasColmillo1, int colmillo2, int e10cifrasColmillo2) {
	if (vcifras==0) return colmillo1*colmillo2 == num && colmillo1/(e10cifrasColmillo1/10)!=0 
		&& colmillo2/(e10cifrasColmillo2/10) && (colmillo1 % 10 != 0 || colmillo2 % 10 != 0);

	else {
		bool encontrado = false;
		if (e10cifrasColmillo1 < sqrt(e10ncifras)) {
			for (int i = 1; !encontrado && i < e10cifrasColmillo1 * 10; i *= 10) {
				int colmillo1z = (colmillo1 / i * 10 + vcifras % 10)*i + colmillo1 % i;
				encontrado = buscarColmillos(num, vcifras / 10, e10ncifras, colmillo1z, e10cifrasColmillo1 * 10, colmillo2, e10cifrasColmillo2);
			}
		}

		if (e10cifrasColmillo2 < sqrt(e10ncifras)) {
			for (int i = 1; !encontrado && i < e10cifrasColmillo2 * 10; i *= 10) {
				int colmillo2z = (colmillo2 / i * 10 + vcifras % 10)*i + colmillo2 % i;
				encontrado = buscarColmillos(num, vcifras / 10, e10ncifras, colmillo1, e10cifrasColmillo1, colmillo2z, e10cifrasColmillo2 * 10);
			}
		}
		return encontrado;
	}
}
bool vampiro(int num) {
	int ncifras = numDigitos(num);
	if (ncifras % 2 == 1) return false;
	else return buscarColmillos(num, num, pow(10, ncifras), 0, 1, 0, 1);
}

void resuelveCaso() {
	int num;
	std::cin >> num;

	if (vampiro(num)) std::cout << "SI\n";
	else std::cout << "NO\n";

}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	//system("PAUSE");
	return 0;
}