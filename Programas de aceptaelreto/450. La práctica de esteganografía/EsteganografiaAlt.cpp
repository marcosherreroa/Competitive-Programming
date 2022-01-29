//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

bool resuelveCaso() {
	int R, N;
	std::cin >> R >> N;
	if (!std::cin)return false;

	std::vector<short> key(R);
	for (int i = 0; i < R; ++i) std::cin >> key[i];

	std::vector<int> seqs (R-1,-1); // maps each character of the key to  -1 if there is no sequence in that state or to the position of its first character
	                             // in the message

	int minLeng = INT_MAX, leng;
	short e;
	for (int i = 0; i < N; ++i) {
		std::cin >> e;

		if (e == key[0]) seqs[0] = i;
		
		for (int j = 1; j < R-1; ++j) {
			if (seqs[j-1] != -1 && e == key[j]) {
				seqs[j] = seqs[j-1];
				seqs[j - 1] = -1;
			}
		}

		if (seqs[R - 2] != -1 && e == key[R - 1]) {
			leng = i - seqs[R - 2] + 1;
			if (leng < minLeng)minLeng = leng;
			seqs[R - 2] = -1;
		}
	}

	std::cout << minLeng << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}