//Marcos Herrero

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lenSubsecPal(std::string const& palabra, int ini, int fin,std::vector<std::vector<int>> & mat) {
	if (ini > fin) mat[ini][fin] = 0;

	else if (ini == fin) mat[ini][fin] = 1;
	
	else if (palabra[ini] == palabra[fin]) {
		if (mat[ini + 1][fin-1] == -1)mat[ini+1][fin-1] = lenSubsecPal(palabra, ini + 1, fin - 1,mat);
		mat[ini][fin] = mat[ini + 1][fin - 1] + 2;
	}

	else {
		if(mat[ini+1][fin] == -1)mat[ini+1][fin]= lenSubsecPal(palabra, ini + 1, fin,mat);
		if (mat[ini][fin-1] == -1)mat[ini][fin-1] = lenSubsecPal(palabra, ini, fin-1, mat);

		mat[ini][fin] = std::max(mat[ini + 1][fin], mat[ini][fin - 1]);
	}

	return mat[ini][fin];
}

bool resuelveCaso() {
	std::string palabra;
	std::cin >> palabra;
	if (!std::cin)return false;

	std::vector<std::vector<int>> mat(palabra.size(), std::vector<int>(palabra.size(), -1));
	int maxleng = lenSubsecPal(palabra, 0, palabra.size() - 1, mat);

	std::string sec;
	int i = 0, j = palabra.size()-1;
	while (i <= j) {
		if (palabra[i] == palabra[j]) {
			sec.push_back(palabra[i]);
			++i;
			--j;
		}
		else if (mat[i + 1][j] >= mat[i][j - 1]) ++i;
		else --j;
	}
	
	int ind = maxleng / 2 - 1;
	while (ind >= 0) {
		sec.push_back(sec[ind]);
		--ind;
	}
	
	std::cout << sec<< '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}