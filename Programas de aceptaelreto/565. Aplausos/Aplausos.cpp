//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
Some testcases:

4
1 1
2 3
2 4
3 4
Salida : 1

4
1 1
2 3
3 4
4 4
Salida: 1

4
1 1
2 4
3 4
4 1
Salida: 4


*/

struct person {
	int t;
	int p;

	bool operator<(person const & that)const {
		if (t < that.t) return true;
		else if (t == that.t && p > that.p) return true;
		else return false;
	}
};

struct personByNeed {
	int ind;
	int p;

	bool operator<(personByNeed const & that)const {
		if (p > that.p)return true;
		else if (p == that.p && ind < that.ind)return true;
		else return false;
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::vector<person> v(N);
	std::vector<personByNeed> peopByNeed(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> v[i].t >> v[i].p;
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		peopByNeed[i] = { i,v[i].p };
	}

	std::sort(peopByNeed.begin(), peopByNeed.end());

	int npeop = N, secs = 0, j = 0;
	for (int i = 0; npeop > 0 && i < N; ++i) {
		if (v[i].p <= npeop) {
			secs = v[i].t;
			--npeop;
		}

		while (j < N && peopByNeed[j].p > npeop) {
			if (peopByNeed[j].ind > i)--npeop;
			++j;
		}
	}

	std::cout << secs << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}