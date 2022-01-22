//Marcos Herrero
#include<iostream>
#include <iomanip>

bool isVowel(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool resuelveCaso() {
	int num; char c1, c2, c3;
	std::cin >> num >> c1 >> c2 >> c3;
	if (num == 9999 && c1 == 'Z' && c2 == 'Z' && c3 == 'Z')return false;

	++num;
	if (num == 10000) {
		num = 0;
		++c3;
		if (isVowel(c3))++c3;
		if (c3 == '[') {
			c3 = 'B';
			++c2;
			if (isVowel(c2))++c2;
			if (c2 == '[') {
				c2 = 'B';
				++c1;
				if (isVowel(c1))++c1;
			}
		}	
	}

	std::cout <<std::setfill('0')<<std::setw(4) <<num<<' '<< c1 << c2 << c3 << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}