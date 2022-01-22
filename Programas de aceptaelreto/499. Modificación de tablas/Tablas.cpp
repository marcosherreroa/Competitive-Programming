//Marcos Herrero

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
//
//struct rango {
//	int ini;
//	int fin;
//};
//
//bool operator<(rango const & r1, rango const & r2) {
//	return r1.ini < r2.ini || (r1.ini == r2.ini && r1.fin < r2.fin);
//}
//
//bool resuelveCaso() {
//	int F, C, N;
//	std::cin >> F >> C >> N;
//	if (F == 0 && C == 0 && N == 0)return false;
//
//	std::vector<std::map<rango, int>> col(C);
//	int I, A, B, M;
//	for (int i = 0; i < N; ++i) {
//		std::cin >> I >> A >> B >> M;
//
//		auto it = col[I].begin();
//		while (it != col[I].end() && it->first.fin < A)++it;
//
//		while (it != col[I].end() && A <= B && it->first.ini <= B) {
//			int ini = it->first.ini;
//			int fin = it->first.fin;
//			int val = it->second;
//			it = col[I].erase(it);
//
//			if (A <= ini && B <= fin) {
//				if(A != ini)col[I].insert({ {A, ini-1}, M });
//				col[I].insert({ {ini, B},M + val });
//				if(B != fin)col[I].insert({ { B+1, fin }, val });
//				A = B+1;
//			}
//			else if (A <= ini && B > fin) {
//				if(A != ini)col[I].insert({ {A, ini-1}, M });
//				
//				col[I].insert({ {ini, fin},M + val });
//				A = fin + 1;
//				
//			}
//
//			else if (B <= fin) {
//				col[I].insert({ {ini, A-1}, val });
//				col[I].insert({ {A, B}, M + val });
//				if(B != fin) col[I].insert({ { B+1, fin }, val });
//				A = B+1;
//			}
//			else {
//				col[I].insert({ {ini, A-1}, val });
//				col[I].insert({ {A, fin}, M + val });
//				A = fin + 1;
//			}
//
//		}
//
//		if (A<= B)col[I].insert({ {A,B}, M });
//
//	}
//
//	std::vector<std::map<rango, int>::iterator> iteradores(C);
//	for (int i = 0; i < C; ++i)iteradores[i] = col[i].begin();
//
//	for (int i = 0; i < F; ++i) {
//		while (iteradores[0] != col[0].end() && iteradores[0]->first.fin< i)++iteradores[0];
//		if (iteradores[0] != col[0].end() && i >= iteradores[0]->first.ini)std::cout << iteradores[0]->second;
//		else std::cout << "0";
//
//		for (int j = 1; j < C; ++j) {
//			while (iteradores[j] != col[j].end() && iteradores[j]->first.fin < i)++iteradores[j];
//			if (iteradores[j] != col[j].end() && i >= iteradores[j]->first.ini)std::cout << ' ' <<iteradores[j]->second;
//			else std::cout << " 0";
//		}
//		
//		std::cout << '\n';
//	}
//
//	return true;
//}

bool resuelveCaso() {
	int F, C, N;
	std::cin >> F >> C >> N;
	if (F == 0 && C == 0 && N == 0)return false;
	
	std::vector<std::vector<int>> tabla(F+1, std::vector<int>(C, 0));
	int I, A, B, M;
	for (int i = 0; i < N; ++i) {
		std::cin >> I >> A >> B >> M;
		tabla[A][I] += M;
		tabla[B+1][I] -= M;
	}

	for (int j = 0; j < C; ++j) {
		int val = 0;
		for (int i = 0; i < F; ++i) {
			val += tabla[i][j];
			tabla[i][j] = val;
		}
	}

	for (int i = 0; i < F; ++i) {

		std::cout << tabla[i][0];
		for (int j = 1; j < C; ++j) {
			std::cout <<' '<< tabla[i][j];
		}
		std::cout << '\n';
	}

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}