//Marcos Herrero

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Fecha {
	int dia;
	int mes;
	int year;
};

std::istream & operator>>(std::istream & flujo, Fecha & f) {
	char aux;
	flujo >> f.dia >> aux >> f.mes >> aux >> f.year;
	return flujo;
}

struct Par {
	int entra;
	int sale;
};

bool operator<(Fecha const & f1, Fecha const & f2) {
	if (f1.year < f2.year)return true;
	else if (f1.year == f2.year && f1.mes < f2.mes) return true;
	else if (f1.year == f2.year && f1.mes == f2.mes && f1.dia < f2.dia) return true;
	else return false;
}

bool operator ==(Fecha const & f1, Fecha const & f2) {
	return f1.year == f2.year && f1.mes == f2.mes && f1.dia == f2.dia;
}

//bool operator ==(Par const & p1, Par const & p2) {
//	return p1.f == p2.f;
//}
//
//bool operator<(Par const & p1, Par const & p2) {
//	return p1.f < p2.f;
//}

struct FechaSol {
	Fecha f;
	int sol;
};

struct comp {
	bool operator()(FechaSol* f1, FechaSol* f2) {
		return f1->f < f2->f;
	}
};

bool resuelveCaso() {
	int v;
	std::cin >> v;
	if (v == 0)return false;

	std::map<Fecha, Par> viajes; // true entra, false sale
	Fecha f;
	f = { 12, 6, 1968 };

	viajes[f].entra = 1;
	viajes[f].sale = 0;
	for (int i = 0; i < v; ++i) {
		std::cin >> f;
		++viajes[f].sale;

		std::cin >> f;
		++viajes[f].entra;
	}

	int c;
	std::cin >> c;
	std::vector<FechaSol> consultas(c);
	std::vector<FechaSol*> punts(c);
	for (int i = 0; i < c; ++i) {
		std::cin >> consultas[i].f;
		punts[i] = &consultas[i];
	}

	std::sort(punts.begin(), punts.end(), comp());

	int j = 0, numMartys = 0;
	auto it = viajes.begin();
	while (it != viajes.end() && j < c) {
		while (j < c && punts[j]->f < it->first) {
			punts[j]->sol = numMartys;
			++j;
		}
		numMartys += it->second.entra;
		while (j < c && punts[j]->f == it->first) {
			punts[j]->sol = numMartys;
			++j;
		}
		numMartys -= it->second.sale;
		++it;
	}

	while (j < c) {
		punts[j]->sol = numMartys;
		++j;
	}

	for (int i = 0; i < c; ++i)std::cout << consultas[i].sol << '\n';
	std::cout << "----\n";
	return true;
}

int main() {
	while (resuelveCaso());
}