//Marcos Herrero
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

struct pos {
	bool start;
	long long int x;
	long long int y;

	const bool operator<(pos const & that) const{
		return x < that.x;
	}
};

bool resuelveCaso() {
	int A; //width

	std::cin >> A;

	if (A == 0) return false;

	int N; //number of rectangles

	std::cin >> N;
	std::vector<pos> points;

	int x, y;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;

		points.push_back({true,x,y });
		points.push_back({false,x + A,y });
	}

	std::sort(points.begin(), points.end());

	long long int area = 0;
	std::multiset<int, std::greater<int>> heights;
	heights.insert(0);
	heights.insert(points[0].y);

	for (int i = 1; i < 2*N; ++i) {
		area += (points[i].x - points[i - 1].x)* (*heights.begin());

		if (points[i].start) heights.insert(points[i].y);
		else heights.erase(heights.find(points[i].y)); // this has to be done like this to erase ONLY ONE of  the maybe multiple heihgts with the same value
	}
	
	std::cout << area << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}