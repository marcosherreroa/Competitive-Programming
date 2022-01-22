#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<unsigned long long int>>;

tMatriz expMat(unsigned long long int n) {
	tMatriz sol(2, std::vector<unsigned long long int>(2));
	if (n == 0) {
		sol[0][0] = 1;
		sol[0][1] = 0;
		sol[1][0] = 0;
		sol[1][1] = 1;
		return sol;
	}

	if (n == 1) {
		sol[0][0] = 0;
		sol[0][1] = 1;
		sol[1][0] = 1;
		sol[1][1] = 1;
		return sol;
	}
	else if (n > 1) {
		tMatriz aux = expMat(n / 2);
		sol[0][0] = (aux[0][0] * aux[0][0] + aux[0][1] * aux[1][0])%46337;
		sol[0][1] = (aux[0][0] * aux[0][1] + aux[0][1] * aux[1][1])%46337;
		sol[1][0] = (aux[1][0] * aux[0][0] + aux[1][1] * aux[1][0])%46337;
		sol[1][1] = (aux[1][0] * aux[0][1] + aux[1][1] * aux[1][1])%46337;

		if (n % 2 == 0) return sol;
		else {
			tMatriz sol2(2, std::vector<unsigned long long int>(2));
			sol2[0][0] = sol[0][1];
			sol2[0][1] = (sol[0][0] + sol[0][1])%46337;
			sol2[1][0] = sol[1][1];
			sol2[1][1] = (sol[1][0] + sol[1][1])%46337;
			return sol2;
		}

	}
}

bool resuelveCaso(){
	unsigned long long int n;
	std::cin >> n;

	if (n == 0) return false;
	
	tMatriz matriz = expMat(n - 1);
	std::cout << matriz [1][1]<< '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}