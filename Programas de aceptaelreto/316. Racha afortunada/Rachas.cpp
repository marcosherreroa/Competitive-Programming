//Marcos Herrero

#include <iostream>
#include <vector>

/*
S(p,q) = sum i: p<= i =q;
long(p,q) = q-p+1

P:={N>0}
   fun rachas(v[0,...,N-1] de ent) dev <ini, fin>: ent     
Q:={ S(ini) = max i,j: 0<= i <= j <= N-1: S(i,j) && long(ini, fin) = min i,j: 0<= i <= j <= N-1 && 
     S(ini, fin) = S(i,j<): long(i,j) && ini= min i: (exist j: i <= j < N-1: S(i,j)=S(ini, fin) && long(i,j)= long(ini,fin)}

	 
I:= 0<= n <= N && r = max i,j: 0<= i <= j <= n-1: S(i,j) && l = min i,j: 0<= i <= j <= n-1 && S(i,j)= r: long(i,j) 
     r = S(i,j<): long(i,j) && ini= min i: (exist j: i <= j < n-1: S(i,j)=r && long(i,j)= l &&
	 r= S(ini, fin) && l= long(ini, fin) &&
	 && s= max i: 0<= i <= n-1: S(i,n-1) && s= S(c, n-1)
B:= n < N

R:= 0<= n+1 <= N && r = max i,j: 0<= i <= j <= n: S(i,j) && l = min i,j: 0<= i <= j <= n && 
     r = S(i,j): long(i,j) && ini= min i: (exist j: i <= j < n: S(i,j)=r && long(i,j)= l &&
	 r= S(ini, fin) && l= long(ini, fin) &&
	 && s= max i: 0<= i <= n: S(i,n) && s= S(c, n)

*/

int sumaVector(std::vector<int> & v, int ini,int fin) {
	int suma = 0;

	while (ini < fin) {
		suma += v[ini];
		++ini;
	}
	return suma;
}

void rachas(std::vector<int> & v, int N, int & ini, int & fin) {
	int n, r, s, l, ls, c;

	n = 1;
	r = v[0];
	s = v[0];
	l = 1;
	ls = 1;
	ini = 0;
	fin = 0;
	c = 0;
	
	while (n < N) {
		if (s > 0) {
			s = s + v[n];
			++ls;
		}

		else {
			s = v[n];
			c = n;
			ls = 1;
		}
		
		if (s > r || s== r  && ls< l || s==r && l==ls && c<ini ) {
			r = s;
			ini = c;
			fin= n;
			l = ls;
		}
		
		n = n + 1;
	}
	
}
void resuelveCaso() {
	int N;
	std::cin >> N;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	int ini, fin;
	rachas(v, N, ini, fin);
	std::cout << ini+1 <<' '<< fin+1 << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();

	return 0;
}