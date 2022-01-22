//Marcos Herrero

#include <iostream>
#include <vector>

struct cofre {
	int prof;
	int oro;
};

int maxVal(std::vector<cofre> const& v, int T, int ini, std::vector<std::vector<int>> & mat) {
	if (ini == v.size()) {
		mat[ini][T] = 0;
		return 0;
	}
	else {
		if (mat[ini + 1][T] == -1) mat[ini + 1][T] = maxVal(v, T, ini + 1, mat);

		if (3 * v[ini].prof > T) mat[ini][T] = mat[ini + 1][T];
		else {
			if (mat[ini + 1][T - 3 * v[ini].prof] == -1) {
				mat[ini + 1][T - 3 * v[ini].prof] = maxVal(v, T - 3 * v[ini].prof, ini + 1, mat);
			}
			
			if (mat[ini + 1][T - 3 * v[ini].prof] + v[ini].oro > mat[ini + 1][T])mat[ini][T] = mat[ini + 1][T - 3 * v[ini].prof] + v[ini].oro;
			else mat[ini][T] = mat[ini + 1][T];
		}

		return mat[ini][T];
	}
}

//Tabulated version?
/*

for(int j = 0; j < T; ++j) mat[v.size()][j] = 0;

for(int i = v.size()-1; i>= 0; --i){
   if(3*v[ini].prof >
}??


*/

bool resuelveCaso() {
	int T, N;
	std::cin >> T >> N;
	if (!std::cin)return false;

	std::vector<cofre> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i].prof >> v[i].oro;

	std::vector<std::vector<int>> mat(N+1, std::vector<int>(T+1, -1));
	int sol = maxVal(v, T, 0, mat);
	std::cout << sol<<'\n';

	int i = 0, j = T;
	std::vector<int> wInd;
	while (i < N && j > 0) {
		if (mat[i + 1][j] < mat[i][j]) {
			wInd.push_back(i);
			j -= 3 * v[i].prof;
		}
		++i;
	}

	std::cout << wInd.size() << '\n';
	for (int i = 0; i < wInd.size(); ++i) {
		std::cout << v[wInd[i]].prof <<' '<< v[wInd[i]].oro << '\n';
	}

	std::cout << "----\n";
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}