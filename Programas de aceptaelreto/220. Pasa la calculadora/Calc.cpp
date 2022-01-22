#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;
const tMatriz calc = {{7,8,9},{4,5,6},{1,2,3}};

bool gana( int s, int n, int x, int y){
    bool OK = false;
	
	
	for (int j = 0; !OK && j < 3; ++j) {
		if (calc[j][y] != n && s + calc[j][y] < 31) {
			OK = !gana(s + calc[j][y], calc[j][y], j, y);
		}
	}


	for (int i = 0; !OK && i < 3; ++i) {
		if (calc[x][i] != n && s + calc[x][i] < 31) {
			OK = !gana(s + calc[x][i], calc[x][i], x, i);
		}
	}

return OK;
}

void resuelveCaso(){
  int s, n;
  std::cin >> s >> n;
 
  int x,y;
  
  for(int i= 0; i< 3; ++i){
   for(int j = 0; j< 3; ++j){
    if(calc[i][j]== n){
      x = i;
      y = j;
}}}
   
  std::vector<int> v;
  if (s == 31) std::cout << "GANA\n";
  else if(gana(s, n, x , y))std::cout<< "GANA\n";
   else std::cout<<"PIERDE\n";
   

}

int main(){
   long long int n;
   std::cin >> n;
    for (int i = 0; i<n ; ++i) resuelveCaso();

return 0;}