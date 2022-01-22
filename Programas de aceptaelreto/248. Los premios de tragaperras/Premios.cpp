//Marcos Herrero
#include <iostream>
#include <vector>

/*
P:={N>0}
  fun maxmonedas(v[0, ..., N - 1] de ent) dev r : ent;
q:={ r= max i,j: 0<=i<=j<=2N-1: S(i,j)}
     r

I:= 0<= n <= N && r = max i,j: 0<=i<=j<=n-1: S(i,j) && s1 = max i: 0<=i<=n-1: S(i,n-1) s2= max i: 0<= i<=n-1: S(0, i)
B:= n < N
C= N-n


  */



bool resuelveCaso() {
	int N,n, r, s1, s2, suma, v, t;
	std::cin >> N;

	if (N == 0) return false;

	std::cin >> v;

	n = 1;
	r = v;
	s1 = v;
	s2 = v;
	suma = v;

	while (n < N) {
		std::cin >> v;
		suma += v;

		if (s1 > 0) s1 += v;
		else s1 = v;

		if (suma > s2) s2 = suma;
		if (s1 > r) r= s1;

		++n;
	}

	t = s1 + s2;
	if (t > r) r = t;

	std::cout << r << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}