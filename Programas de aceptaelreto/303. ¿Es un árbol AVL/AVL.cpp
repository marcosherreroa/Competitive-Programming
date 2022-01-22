//Marcos Herrero
#include <iostream>
#include <algorithm>
#include <cmath>

bool AVL(int raiz, int & altura, int & max, int & min) {
	if (raiz == -1) {
		altura = 0;
		return true;
	}
	else {
		int l, r, alt1= 0, alt2= 0, max1= -1, max2= -1, min1= -1, min2= -1;
		bool OK1= true , OK2 = true;
		std::cin >> l;
		if (l != -1) OK1 = AVL(l, alt1, max1, min1);
		std::cin >> r;
		if(r!= -1) OK2 = AVL(r, alt2, max2, min2);
		altura = 1+std::max(alt1, alt2);
		max = std::max(raiz, std::max(max1, max2));
		if(l != -1 && r != -1)min = std::min(raiz, std::min(min1, min2));
		else if (l != -1)min = std::min(raiz, min1);
		else if (r != -1) min = std::min(raiz, min2);
		else min = raiz;
		bool z =OK1 && OK2 && abs(alt1 - alt2) <= 1 && (l == -1 || max1 < raiz) && (r == -1 || min2 > raiz);
		return z;
	}
}

void resuelveCaso() {
	int raiz, altura, max, min;
	std::cin >> raiz;
	if (AVL(raiz, altura, max ,min))std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}