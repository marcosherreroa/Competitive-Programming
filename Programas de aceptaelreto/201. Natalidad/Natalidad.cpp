//Marcos Herrero
#include <iostream>

std::pair<bool, bool> norma(char raiz) {
	char left, right; std::pair<bool, bool> sol1 = { false,false }, sol2 = { false, false };
	//first: hay gente con un hijo , scond: hay gente con dos hijos
	std::cin >> left;
	if (left != '.') sol1 = norma(left);
	std::cin >> right;
	if (right != '.') sol2 = norma(right);

	if (left == '.' && right == '.')return { true, true };
	else if (right== '.' ) return { sol1.first, false};
	else if (left == '.') return { sol2.first, false };
	else return  { false , sol1.second && sol2.second};
}
	
bool resuelveCaso() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.')return false;
	std::pair<bool, bool> sol = norma(raiz);
	if (sol.first && sol.second) std::cout << "12\n";
	else if (sol.first)std::cout << "1\n";
	else if (sol.second)std::cout << "2\n";
	else std::cout << "N\n";

	return true;
}

int main() {
	while (resuelveCaso());
}