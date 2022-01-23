//Marcos Herrero
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

std::vector<int> const neighx = { -1,0,1,0 };
std::vector<int> const neighy = { 0,1,0,-1 };

struct pos {
	int x;
	int y;
};

struct touchwall {
	bool touched[4]; //0 norte, 1 este, 2 sur, 3 oeste
};


bool passable(pos const &  p, std::vector<std::vector<char>> const & board) {
	return 0 <= p.x && p.x < board.size() && 0 <= p.y && p.y < board[0].size() && board[p.x][p.y] != '#';
}

int minPasos(std::vector<std::vector<char>> const & board, pos const & posorig) {

	std::vector<std::vector<int>> dist(board.size(), std::vector<int>(board[0].size(), INT_MAX));
	std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));

	pos currpos = posorig;
	int sol = -1;

	std::queue<pos> q;
	dist[posorig.x][posorig.y] = 0;
	q.push(posorig);

	bool found = false;
	while (!q.empty() && !found) {
		currpos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			pos aux = { currpos.x + neighx[i], currpos.y + neighy[i] };

			if (passable(aux,board) && ! visited[aux.x][aux.y]) {
				visited[aux.x][aux.y] = true;
				dist[aux.x][aux.y] = 1 + dist[currpos.x][currpos.y];
				if (board[aux.x][aux.y] == 'T') {
					found = true;
					sol = dist[aux.x][aux.y];
					break;
				}

				q.push(aux);
			}
		}
	}

	return sol;
}

int rightHand(std::vector<std::vector<char>> const & board, pos const & posorig) {
	pos currpos = posorig;
	int dir = 0;

	int numPasos = 0;
	bool found = false;
	std::vector<std::vector<std::vector<bool>>> visited(board.size(), std::vector<std::vector<bool>>(board[0].size(), std::vector<bool>(4,false)));

	while (true) {
		pos newpos = { currpos.x + neighx[dir], currpos.y + neighy[dir] };


		while (!passable(newpos, board)) {
			dir = dir - 1;
			if (dir < 0)dir += 4;
			newpos = { currpos.x + neighx[dir], currpos.y + neighy[dir] };
		}
		
		currpos.x += neighx[dir];
		currpos.y += neighy[dir];
		++numPasos;

		if (visited[currpos.x][currpos.y][dir]) break;

		visited[currpos.x][currpos.y][dir] = true;

		if (board[currpos.x][currpos.y] == 'T') {
			found = true;
			break;
		}

		pos dcha = { currpos.x + neighx[(dir+1)%4],currpos.y + neighy[(dir+1)%4] };
		if (passable(dcha,board)) {
			dir = (dir + 1) % 4;

			currpos.x += neighx[dir];
			currpos.y += neighy[dir];
			++numPasos;

			if (visited[currpos.x][currpos.y][dir]) break;

			visited[currpos.x][currpos.y][dir] = true;

			if (board[currpos.x][currpos.y] == 'T') {
				found = true;
				break;
			}
		}
	}

	if (!found) return -1;
	else return numPasos;
}

bool resuelveCaso() {
	int tx, ty;

	std::cin >> tx >> ty;
	if (!std::cin) return false;

	std::vector<std::vector<char>> board(ty, std::vector<char>(tx, 0));
	
	pos source;
	for (int i = 0; i < ty - 1; ++i) {
		for (int j = 0; j < tx; ++j) {
			std::cin >> board[i][j];
		}
	}

	for (int j = 0; j < tx; ++j) {
		std::cin >> board[ty-1][j];
		if (board[ty - 1][j] == '.') {
			source.x = ty - 1;
			source.y = j;
		}
	}

	int minsteps = minPasos(board, source);

	if (minsteps == -1) std::cout << "IMPOSIBLE\n";

	else {

		int othersteps = rightHand(board, source);

		if (othersteps == -1)std::cout << "INF\n";
		else if (minsteps == othersteps)std::cout << "IGUAL\n";
		else std::cout << othersteps - minsteps << '\n';
	}

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}