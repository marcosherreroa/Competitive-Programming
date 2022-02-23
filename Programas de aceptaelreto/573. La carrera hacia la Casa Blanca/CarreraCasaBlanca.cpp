//Marcos Herrero

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

/*

minConv[i][j] : minimum number of people from states v[0..i-1] to obtain j delegates
0 <= i <= N, 0<= j <= M

Sol: minConv[N][M]

minConv[i][0] = 0  for all i
minConv[0][j] = inf for all j >= 1

minConv[i][j] = min (minConv[i-1][j], minPeopState[i-1]+minConv[i-1][j-deleg[i-1]])


*/


struct state{
	int ndeleg;
	int donalds;
	int nodonalds;
	int question;
};

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;

	std::vector<int> deleg(N);
	std::vector<int> minPeopState(N);
	int donalds, nodonalds, question, majority;
	for (int i = 0; i < N; ++i) {
		std::cin >> deleg[i] >> donalds >> nodonalds >> question;
		majority = (donalds + nodonalds + question) / 2 + 1;
		if (majority > donalds + question) minPeopState[i] = INT_MAX;
		else if (donalds >= majority) minPeopState[i] = 0;
		else minPeopState[i] = majority - donalds;
	}

	int M = 0;
	for (int i = 0; i < N; ++i) M += deleg[i];
	M /= 2;
	++M; //number of delegates donald needs

	std::vector<int> minConv(M+1,INT_MAX); //represents a row of the matrix
	minConv[0] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= 1; --j) {
			if (minPeopState[i - 1] < INT_MAX && minConv[std::max(0, j - deleg[i - 1])] < INT_MAX) {
				minConv[j] = std::min(minConv[j], minPeopState[i - 1] + minConv[std::max(0, j - deleg[i - 1])]);
			}
		}
	}

	if (minConv[M] == INT_MAX)std::cout << "IMPOSIBLE\n";
	else std::cout << minConv[M] << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}