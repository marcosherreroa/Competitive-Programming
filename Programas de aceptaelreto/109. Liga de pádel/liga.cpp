//Marcos Herrero

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

struct par {
	std::string nombre;
	int puntos;
};


int casifactorial(int a) {
	return (a - 1) * a;
}
bool resuelveCaso() {
	std::string categoria;
	std::cin >> categoria;
	if (categoria == "FIN") return false;

	std::vector<par> equipos;

	std::string local;
	int setsLocal;
	std::string visitante;
	int setsVisitante;

	std::cin >> local;
	int numPartidos = 0;;
	while (local != "FIN") {
		std::cin >> setsLocal;
		std::cin >> visitante;
		std::cin >> setsVisitante;

		bool found1 = false, found2 = false;
		if (setsLocal > setsVisitante) {
			for (int i = 0; (!found1 || !found2) && i < equipos.size(); ++i) {
				if (equipos[i].nombre == local) {
					found1 = true;
					equipos[i].puntos += 2;
				}
				else if (equipos[i].nombre == visitante) {
					found2 = true;
					equipos[i].puntos += 1;
				}
			}

			if (!found1)equipos.push_back({ local, 2 });
			if (!found2)equipos.push_back({ visitante, 1 });
		}

		else if (setsLocal < setsVisitante) {
			for (int i = 0; (!found1 || !found2) && i < equipos.size(); ++i) {
				if (equipos[i].nombre == visitante) {
					found2 = true;
					equipos[i].puntos += 2;
				}
				else if (equipos[i].nombre == local) {
					found1 = true;
					equipos[i].puntos += 1;
				}
			}

				if (!found1)equipos.push_back({ local, 1 });
				if (!found2)equipos.push_back({ visitante, 2 });

			}

		else{
			for (int i = 0; (!found1 || !found2) && i < equipos.size(); ++i) {
				if (equipos[i].nombre == visitante) {
					found2 = true;
				}
				else if (equipos[i].nombre == local) {
					found1 = true;
				}

				if (!found1)equipos.push_back({ local, 0 });
				if (!found2)equipos.push_back({ visitante, 0});
			}
		}

			++numPartidos;
			std::cin >> local;
	}

	par ganador = equipos[0]; bool empate = false;
	for (int i = 1; i < equipos.size(); ++i) {
		if (equipos[i].puntos > ganador.puntos) {
			ganador = equipos[i];
			empate = false;
		}
		else if (equipos[i].puntos == ganador.puntos)empate = true;
	}

	int partidosNoJugados = casifactorial(equipos.size()) - numPartidos;
	if (empate)std::cout << "EMPATE "<< partidosNoJugados<<'\n';
	else std::cout << ganador.nombre << ' ' << partidosNoJugados<<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}