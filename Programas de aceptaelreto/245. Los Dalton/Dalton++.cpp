#include <iostream>

bool resuelveCaso() {
	long long int N;
	std::cin >> N;

	if (N == 0) return false;

	bool crec = true, decrec = true;
	long long int D0, D1;
	std::cin >> D0;
	for (int i = 1; i < N; ++i) {
		std::cin >> D1;
		if (D0 >= D1) crec = false;
		if (D0 <= D1) decrec = false;

		D0 = D1;
	}
	
	if (crec || decrec) std::cout << "DALTON\n";
	else std::cout << "DESCONOCIDOS\n";

	return true;
}


int main(){
	while (resuelveCaso());
}