//Marcos Herrro
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

void resuelveCaso() {
	std::unordered_map<int, int> tabla;
	std::queue<std::string> instrucciones;
	std::queue<int> lineasSaltos;

	int num, renum = 10; std::string instr;
	std::cin >> num;
	while (num != 0) {
		tabla[num] = renum;
		renum += 10;
		std::cin >> instr;
		instrucciones.push(instr);
		if (instr == "GOTO" || instr == "GOSUB") {
			std::cin >> num;
			lineasSaltos.push(num);
		}

		std::cin>> num;
	}

	renum = 10;
	while (!instrucciones.empty()) {
		std::cout <<renum<<' '<< instrucciones.front();
		if (instrucciones.front() == "GOTO" || instrucciones.front() == "GOSUB") {
			std::cout <<' '<< tabla[lineasSaltos.front()];
			lineasSaltos.pop();
		}
		std::cout << '\n';
		renum += 10;
		instrucciones.pop();
	}

	std::cout << "---\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}