//Marcos Herrero

#include <iostream>

bool resuelveCaso() {
	long long int distSold, desSold , dist, des;
	std::cin >> distSold >> desSold;
	if (!std::cin)return false;

	std::cin >> dist >> des;

	long long int distAcum = 0, desAcum = 0;
	long long int dias = 0; bool dest = false;
	while (!dest && (dist != 0 || des != 0)) {
		if (dist > distSold || des > desSold) dest = true;
		else if (distAcum + dist > distSold || desAcum + des > desSold) {
			++dias;
			distAcum = dist;
			if(des > 0)desAcum = des;
			else desAcum = 0;
		}
		else {
			distAcum += dist;
			if(des > 0) desAcum += des;
		}

		std::cin >> dist >> des;
	}

	if (distAcum > 0 || desAcum > 0) ++dias;

	if (dest) std::cout << "DESTITUIDO\n";
	else std::cout << dias<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}