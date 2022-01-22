//Marcos Herrero
#include <iostream>

/*
P:={L>= 1}
fun longit(L: ent) dev p:ent
Q:={p= sum i: 1<=i && (L/2^(i-1))>= 1: 4^i*(L/2^(i-1))}

p = sum i: 1<=i && (L/2^(i-1))>= 1: 4^i*(L/2^(i-1)) 
  =  4*L + sum i: 2<= i && (L/2^(i-1)) >= 1: 4^i*(L/2^(i-1)) =
  = 4*L + sum i: 1<=i && (L/2)/2^(i-1)>= 1:4^(i+1)*L/2^i = 
  =  4*L+ 4*(sum i: 1<=i && (L/2)/2^(i-1)>= 1:4^i*(L/2)/2^(i-1))

  p(L) = 4*L +4*p(L/2)

Casos: L= 1 -> dev p = 4L= 4;
    Si L>1 -> p(L) = 4*L+4*p(L/2)

	glongit(L,x) = 4*x+4*longit(L)= 4*x+4*(4*L+4*longit(L/2)) = 4*x+16*L+16*longit(L/2)
    go
	int glongit(int L, int x, int y){
	   if(L==1) return 4*x+16;
	   else 
	}

	int glongit(int L, int x, int y){
	   while(L != 1){
	   L/=2;
	   x= x+4*y*L;
	   y= 4*y;
	   }
	   p= x+4*y;
	}
*/

int glongit(int L, int x, int y) {
	if (L == 1) return x + 4 * y;
	else return glongit(L / 2, x + 4 * y*L, 4 * y);
}

int longit(int L) {
	return glongit(L, 0, 1);
	//if (L == 1) return 4;
    //else return 4*L + 4*longit(L / 2);
}




bool resuelveCaso() {
	int L;
	std::cin >> L;

	if (!std::cin) return false;

	std::cout << longit(L)<<'\n';

	return true;

}

int main() {
	while (resuelveCaso());
}