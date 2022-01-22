//Marcos Herrero

#include <iostream>
#include <set>

struct Fecha {
	int day;
	int month;
};

std::istream & operator>>(std::istream & flujo, Fecha & f) {
	char aux; int year;
	flujo >> f.day >> aux >> f.month >> aux >> year;
	return flujo;
}

bool operator<(Fecha const & f1, Fecha const & f2) {
     if (f1.month < f2.month) return true;
	else if (f1.month == f2.month && f1.day < f2.day )return true;
	else return false;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::set<Fecha> cump;
	Fecha f;  bool rep = false;
	for (int i = 0; i < N; ++i) {
		std::cin >> f;
		if (cump.count(f) == 1)rep = true;
		else cump.insert(f);
	}

	if (rep) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
}