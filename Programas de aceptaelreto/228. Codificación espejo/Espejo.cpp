//Marcos Herrero


#include <iostream>
#include <stack>

void decodificar(char raiz, std::stack<char> & sol) {
	if (raiz != ' ') {
		char l, r;
		std::cin.get(l);
		decodificar(l, sol);
		if (l != ' ') sol.push(l);
		std::cin.get(r);
		decodificar(r, sol);
		if (r != ' ') sol.push(r);
	}
}

bool resuelveCaso() {
	char raiz;
	std::cin >> raiz;
	if (!std::cin) return false;
	std::stack<char> sol;
	decodificar(raiz, sol);

	std::cout << raiz;
	while (!sol.empty()) {
		std::cout << sol.top();
		sol.pop();
	}
	

	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}