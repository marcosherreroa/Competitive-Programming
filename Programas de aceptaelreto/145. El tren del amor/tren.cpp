//Marcos Herrero
#include <iostream>
#include <string>
#include <stack>

int numParejas(std::string const & tren) {
	std::stack<bool> hombres;
	int numparejas = 0;

	for (int i = 0; i < tren.size(); ++i) {
		switch(tren[i]){
		case 'H': hombres.push(true); break;
		case 'h': hombres.push(false); break;
		case 'M': {
			if (!hombres.empty() && hombres.top()) {
				++numparejas;
				hombres.pop();
			}
			else {
				while (!hombres.empty())hombres.pop();
			}
			break;
		}
		case 'm': {
			if (!hombres.empty() && !hombres.top()){
				++numparejas;
				hombres.pop();
			}
			else {
				while (!hombres.empty())hombres.pop();
			}
			break;
		}
		case '@': {
			while (!hombres.empty())hombres.pop();
			break;
		}
		}
	}

	return numparejas;
}

bool resuelveCaso() {
	std::string tren;
	std::cin >> tren;
	if (!std::cin) return false;

	std::cout << numParejas(tren) << '\n';

	return true;
}

int main(){
	while (resuelveCaso());
}