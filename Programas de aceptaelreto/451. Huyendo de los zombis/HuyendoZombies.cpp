//Marcos Herrero
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <climits>

struct Edge {
	int dest;
	int hour; //from 0 to 59
	long long int timetakes;
};

struct Node {
	int vert;
	int hour;
	long long int waittime;

	bool operator< (Node const & that)const {
		return waittime > that.waittime;
	}
};

int elapsedTime(int h1, int h2) {
	if (h1 <= h2)return h2 - h1;
	else return 60 - h1 + h2;
}

bool resuelveCaso() {
	int N, M;
	std::cin >> N >> M;
	if (!std::cin)return false;

	std::vector<std::vector<Edge>> G(N+1);
	std::string line;
	std::getline(std::cin, line);
	int first, p1, p2, hour;
	long long int timetakes;
	for (int i = 0; i < M; ++i) {
		std::getline(std::cin, line);
		std::stringstream ss(line);
		hour = 0;

		ss >> p1;
		first = p1;
		while (ss >> timetakes) {
			ss >> p2;

			G[p1].push_back({ p2,hour,timetakes });
			hour = (hour + timetakes)%60; // it should never grow above 60
			p1 = p2;
		}

		G[p1].push_back({ first,hour % 60, (60 - hour) % 60 });
	}

	std::priority_queue<Node> pq;
	std::vector<std::vector<int>> timeWaiting(N + 1, std::vector<int>(60, INT_MAX)); //maps the pair (destiny,hour reached) to minimum time spent waiting
	for (int i = 0; i < 60; ++i)timeWaiting[1][i] = 0;
	
	for (Edge ed : G[1]) {
		timeWaiting[ed.dest][(ed.hour + ed.timetakes)%60] = 0;
		pq.push({ed.dest,(ed.hour + ed.timetakes) % 60,0 });
	}

	while (!pq.empty()) {
		int u = pq.top().vert;
		hour = pq.top().hour;
		int waited = pq.top().waittime;
		pq.pop();

		if (u == N) break;

		for (Edge ed : G[u]) {
			timetakes = waited + elapsedTime(hour, ed.hour);

			if (timetakes < timeWaiting[ed.dest][(ed.hour+ed.timetakes)%60]) {
				timeWaiting[ed.dest][(ed.hour + ed.timetakes) % 60] = timetakes;
				pq.push({ ed.dest,(ed.hour + ed.timetakes) % 60,timetakes});
			}
		}
	}

	int min = timeWaiting[N][0];
	for (int i = 1; i < 60; ++i) {
		if (timeWaiting[N][i] < min)min = timeWaiting[N][i];
	}

	if (min == INT_MAX)std::cout << "Hoy no vuelvo\n";
	else std::cout << min << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}