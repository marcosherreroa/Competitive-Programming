//Marcos Herrero

#include <iostream>
#include <vector>

bool submovil(int & peso) {
	int pi, di, pd, dd; 
	std::cin >> pi >> di >> pd >> dd;

	bool OK1 = true, OK2 = true;
	if (pi == 0) OK1= submovil(pi);
	if (pd == 0) OK2 = submovil(pd);

	peso = pi + pd;
	return(OK1 && OK2 && pi*di == pd*dd);
}

bool resuelveCaso(){
	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;

	if (pi == 0 && di == 0 && pd == 0 && dd == 0) return false;

	bool OK1 = true, OK2 = true;
	if (pi == 0) OK1= submovil(pi);
	if (pd == 0) OK2 = submovil(pd);

	if (OK1 && OK2 && pi*di == pd*dd) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
