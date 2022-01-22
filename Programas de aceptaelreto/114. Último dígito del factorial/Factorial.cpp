//Marcos Herrero
#include <iostream>

void resuelveCaso(){
	int num;
	std::cin >> num;


	if (num == 0 || num == 1) std::cout << 1;
	else if (num == 2)std::cout << 2;
	else if (num == 3) std::cout << 6;
	else if(num == 4) std::cout << 4;
	else std::cout << 0;
	
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}