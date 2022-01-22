//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<char>>;

bool descubrir(int x, int y, tMatriz & tablero){
	if ( tablero[x][y] == '*') return false; 
	else if (tablero[x][y] != '-') return true;
	else{
		int minas = 0; 
		if (y + 1 < tablero[0].size() && tablero[x][y + 1] == '*') ++minas;
		if (x + 1 < tablero.size() && y + 1 < tablero[0].size() && tablero[x + 1][y+1] == '*') ++minas;
		if (x + 1 < tablero.size() && tablero[x + 1][y] == '*') ++minas;
		if (x + 1 < tablero.size() && y - 1 >= 0 && tablero[x + 1][y - 1] == '*') ++minas;
		if (y - 1 >= 0 && tablero[x][y - 1] == '*') ++minas;
		if (x - 1 >= 0 && y - 1 >= 0 && tablero[x - 1][y - 1] == '*') ++minas;
		if (x - 1 >= 0 && tablero[x - 1][y] == '*')++minas;
		if (x - 1 >= 0 && y + 1 < tablero[0].size() && tablero[x - 1][y + 1] == '*') ++minas;

		if (minas == 0){
			tablero[x][y] = ' ';
			if (y + 1 < tablero[0].size()) descubrir(x, y + 1, tablero);
			if (x + 1 < tablero.size() && y + 1 < tablero[0].size()) descubrir(x+1, y+1, tablero);
			if (x + 1 < tablero.size()) descubrir(x + 1, y, tablero);
			if (x + 1 < tablero.size() && y - 1 >= 0) descubrir(x + 1, y - 1, tablero);
			if (y - 1 >= 0 ) descubrir(x, y - 1, tablero);
			if (x - 1 >= 0 && y - 1 >= 0) descubrir(x - 1, y - 1, tablero);
			if (x - 1 >= 0 ) descubrir(x-1, y, tablero);
			if (x - 1 >= 0 && y + 1 < tablero[0].size()) descubrir(x - 1, y + 1, tablero);
		}
		else tablero[x][y] = '0' + minas;
		return true;
	}
}

bool resuelveCaso(){
	int f, c;
	std::cin >> f >> c;
	if (!std::cin) return false;

	tMatriz tablero(f, std::vector<char>(c));
	for (int i = 0; i < f; ++i){
		for (int j = 0; j < c; ++j){
			std::cin >> tablero[i][j];
		}
	}

	int k;
	std::cin >> k;
	bool OK = true;
	for (int i = 0; OK && i < k; ++i){
		int x, y;
		std::cin >> x >> y;
		OK= descubrir(x-1, y-1, tablero);
	}

	if (!OK)  std::cout << "GAME OVER\n";
	else for (int i = 0; i < f; ++i){
		for (int j = 0; j < c; ++j){
			if (tablero[i][j] == '-'|| tablero[i][j]== '*' ) std::cout << 'X';
			else if (tablero[i][j] == ' ') std::cout << '-';
			else std::cout << tablero[i][j];
		}
		std::cout << '\n';
	}

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}