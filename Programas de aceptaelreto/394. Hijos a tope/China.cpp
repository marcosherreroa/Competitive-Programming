//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>

struct Sol {
	int numgenActual;
	int numgenMax;
};

 Sol numgen(int numhijos) {
	 if (numhijos == 0)return { 0 , 0};
	 else if (numhijos == 1) {
		 int hijos1;
		 std::cin >> hijos1;
		 Sol sol1 = numgen(hijos1);
		 return { 0, sol1.numgenMax};
	 }
	 else {
		 int hijos1, hijos2;
		 std::cin >> hijos1;
		 Sol sol1 = numgen(hijos1);
		 std::cin >> hijos2;
		 Sol sol2 = numgen(hijos2);
		 int numgenActual = 1 + std::min(sol1.numgenActual, sol2.numgenActual);
		 int numgenMax = std::max(std::max(sol1.numgenMax, sol2.numgenMax), numgenActual);
		 return{ numgenActual, numgenMax };
	 }
}

void resuelveCaso() {
	int hijos;
	std::cin >> hijos;
	Sol sol = numgen(hijos);
	std::cout << sol.numgenMax << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}