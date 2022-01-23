//Marcos Herrero
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, char> nameToInd = {
	{"Mafalda", 0},
	{"Felipe" , 1},
	{"Manolito" ,2},
	{"Susanita" , 3},
	{"Miguelito", 4},
	{"Libertad" , 5},
	{"Guille",6}
};

/*
int nameToInd(std::string const & name) {
	if (name == "Mafalda")return 0;
	else if (name == "Felipe") return 1;
	else if (name == "Manolito") return 2;
	else if (name == "Susanita") return 3;
	else if (name == "Miguelito") return 4;
	else if (name == "Libertad") return 5;
	else return 6;
}*/

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;

	std::vector <int> esperando (7, 0);
	int numFotos = 0, numPersonas = 0;

	std::string name;
	char ind;
	for (int i = 0; i < n; ++i) {
		std::cin >> name;

		ind = nameToInd[name];
		++esperando[ind];
		if (esperando[ind] == 1)++numPersonas;

		if (esperando[0] > 0 && numPersonas > 2) {
			for (int i = 0; i < 7; ++i) {
				if (esperando[i] > 1) --esperando[i];
				else if (esperando[i] == 1) {
					esperando[i] = 0;
					--numPersonas;
				}
			}

			++numFotos;
		}

	}

	int remain = 0;
	for (int i = 0; i < 7; ++i) {
		remain += esperando[i];
	}

	std::cout << numFotos <<' '<<remain<<'\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}