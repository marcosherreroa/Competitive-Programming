//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

/*

nways[i,j] = ways to interpret v[i...j-1]

nways[i,i] = 1
nways[i,j] = sum : i <= k <= j-1 && v[i...k] is a code : nways[k+1,j]

*/


bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;

	std::string code;
	std::unordered_set<std::string> codes;
	for (int i = 0; i < N; ++i) {
		std::cin >> code;
		codes.insert(code);
	}

	std::string msg;
	std::cin >> msg;
	int M = msg.size();

	long long int sol = 1;
	int ini = 0, fin;

	while (ini < M) {
		
		fin = ini;
		while (fin < M && msg[fin] != '0')++fin;

		int wordsize = fin - ini;
		std::vector<int> nways(wordsize+1,0);
		nways[0] = 1;

		for (int j = 1; j < wordsize + 1; ++j) {
			for (int k = 1; k <= j; ++k) {
				if (codes.count(msg.substr(ini+j - k, k)) == 1) {
					nways[j] = (nways[j] + nways[j - k])%1000000007;
				}
			}
		}
		
		sol = (sol* nways[wordsize])%1000000007;

		ini = fin;
		while (ini < M && msg[ini] == '0')++ini;
	}

	std::cout << sol << '\n';
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}