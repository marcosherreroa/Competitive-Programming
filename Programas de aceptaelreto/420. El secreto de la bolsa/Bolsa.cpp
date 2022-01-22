//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>

unsigned long long int sumas(unsigned long long int c, std::string & sec) {
	unsigned long long int suma, nsumas, pot, digit;
     int i, longsec, z;

	suma = 0;
	nsumas = 0;
	pot = 1;
	i = 0;
	longsec = 0;
	
	while (i < sec.size()) {
		digit = int(sec[i])- int ('0');
		suma += digit;
		++longsec;
		
		while(suma > c) {
			suma -= int(sec[i+1-longsec])- int('0');
			--longsec;
		}

		if (suma == c) {
			nsumas++;
			suma -= int(sec[i+1 - longsec]) - int('0');
			--longsec;
		}

		++i;
	}

	return nsumas;
}

void resuelveCaso() {
	unsigned long long int c;
	std::string sec;

	std::cin >> c >> sec;

	std::cout << sumas(c, sec) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}