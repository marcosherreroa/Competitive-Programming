//Marcos Herrero
#include <iostream>
#include <string>

int result(std::string & str, int ini, int fin) {
	int p;
	if (ini == fin - 1) {
		p = int(str[ini]) - int('0');
		return p;
	}
	else {
		int p, expr = 0, i = ini+2;
		bool encontrado = false, firstnum = false;
		while(!encontrado && i < fin) {
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') ++expr;
			else if (firstnum) --expr;
			else firstnum = true;

			if (expr == 0) {
				encontrado = true;
				p = i;
			}
			i += 2;
			}

		int primarg = result(str, ini + 2, p + 1);
		int segarg = result(str, p + 2, fin);

		if (str[ini] == '+') return primarg + segarg ;
		if (str[ini] == '-') return primarg - segarg;
		if (str[ini] == '*') return primarg * segarg;
		if (str[ini] == '/') return primarg / segarg;
	}
}

void resuelveCaso() {
	std::string str;
	std::getline(std::cin, str);
	std::cout << result(str, 0, str.size()) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore(1);
	for (int i = 0; i < n; ++i) resuelveCaso();
}