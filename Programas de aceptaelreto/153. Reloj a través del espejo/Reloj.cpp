//Marcos Herrero
#include <iostream>
#include <iomanip>

void resuelveCaso() {
	int hora, min; char aux;
	std::cin >> hora >> aux >> min;
	
	if(hora == 12 && min == 0)std::cout<< "12:00\n";
	else if(hora == 12)std::cout << std::setfill('0') << std::setw(2) << 11 << ':' << std::setw(2) << 60-min << '\n';
	else if (min == 0)std::cout << std::setfill('0') << std::setw(2) << 12 - hora << ':' << std::setw(2) << 0 << '\n';
	else if (hora == 11)std::cout << std::setfill('0') << std::setw(2) << 12 << ':' << std::setw(2) << 60 - min << '\n';
	else std::cout <<std::setfill('0')<<std::setw(2)<< 11 - hora << ':' <<std::setw(2)<< 60 - min<<'\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}