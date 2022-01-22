#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso(){
	int nbolas;
	std::cin >> nbolas;

	if (nbolas == 0) return false;

	std::vector<int> bolas(nbolas);
	for (int i = 0; i < nbolas; ++i) std::cin >> bolas[i];

	std::sort(bolas.begin(), bolas.end());

	std::vector<bool> posiciones(bolas[nbolas-1]- bolas[0], false);
	for (int i = 1; i < nbolas; ++i){
		for (int j = 0; j < i; ++j){
			posiciones[bolas[i] - bolas[j]-1] = true;
		}
	}

	for (int i = 0; i < posiciones.size()-1; ++i){
		if (posiciones[i]) std::cout<< i+1<<' ';
	}
	if(posiciones[posiciones.size()-1]) std::cout<<posiciones.size()<<'\n';

	return true;
}


int main(){
	while (resuelveCaso());

	//system("PAUSE");
}