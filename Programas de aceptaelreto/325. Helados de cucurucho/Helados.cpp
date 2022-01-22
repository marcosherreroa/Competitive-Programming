//Marcos Herrero
#include <iostream>
#include <string>
#include <vector>

void cucuruchos (std::vector<std::string> & vectpermut, int c, int v, std::string  permut) {
	if (c == 0 && v== 0) vectpermut.push_back(permut);
	else if (v == 0){
		permut.push_back('C');
		cucuruchos(vectpermut, c - 1, v, permut);
	}

	else if (c > 0 && v > 0) {
		std::string permut1 = permut, permut2 = permut;
		permut1.push_back('C');
		cucuruchos(vectpermut, c - 1, v, permut1);

		permut2.push_back('V');
		cucuruchos(vectpermut, c, v - 1, permut2);
	}

	else {
		permut.push_back('V');
		cucuruchos(vectpermut, c, v - 1, permut);
	}
}

void resuelveCaso() {
	int c, v;
	std::cin >> c >> v;

	std::vector<std::string> z;
	std::string permut = "";
	cucuruchos(z, c, v, permut);
	for (int i = 0; i < z.size()-1; ++i) std::cout << z[i] << ' ';
	std::cout << z[z.size() - 1] << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}
