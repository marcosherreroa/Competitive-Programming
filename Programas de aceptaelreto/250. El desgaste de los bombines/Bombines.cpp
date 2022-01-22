//Marcos Herrero

#include <iostream>
#include <vector>
#include <math.h>

/*
P:={N>0}
   fun(v[0,...,N-1] de ent) dev d: ent
Q:={0 <= d <= N-1 && abs(S(0,d-1) - S(d,N-1))= min i: 0 <= i <= N-1: abs(S(0,i-1) - S(i, N-1)) && 
    d= min i:( 0<=i<=N-1 && S(0,i-1)-S(i, N-1)= S(0,d) - S(d+1, N-1)) : i}


I1:= 0<= m <= N && suma= sum i : 0<= i <= m-1: v[i]
B1:= m < N

I2:= 0<= n <= N-1 && 0<= d <= n && s1= S(0,n-1) && s2= S(n,N-1) && absdif = min i: 0<= i <= n: abs(S(0,i-1) - S(i,N-1)) && 
     suma = S(0, N-1) &&
     abs(S(0,d-1)-S(d, N-1))= absdif && d= min i:( 0<=i<=n && S(0,i-1)-S(i, N-1)= abs(S(0,d-1) - S(d, N-1))) : i
B:= n < N-1
R2:=  0<= n+1 <= N-1 && 0<= d <= n+1 && s1= S(0,n) && s2= S(n+1,N-1) && absdif = min i: 0<= i <= n+1: abs(S(0,i-1) - S(i,N-1)) && suma = S(0, N-1) && abs(S(0,d-1)-S(d, N-1))= absdif && d= min i:( 0<=i<=n+1 && S(0,i-1)-S(i, N-1)= abs(S(0,d-1) - S(d, N-1))) : i

*/     

int diaCerrajero(std::vector<int> & v, int N) {
	int n, d, s1, s2, absdif, suma, m;

	m = 0;
	suma = 0;

	while (m < N) {
		suma += v[m];
		m = m+1;
	}

	n = 0;
	s1 = 0;
	s2 = suma;
	absdif = abs(suma);
	d = 0;

	while (n < N-1) {
		s1 += v[n];
		s2 -= v[n];

		if (abs(s1 - s2) < absdif) {
			absdif = abs(s1 - s2);
			d = n+1;
		}
		n = n + 1;
	}

	return d;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << diaCerrajero(v, N) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}