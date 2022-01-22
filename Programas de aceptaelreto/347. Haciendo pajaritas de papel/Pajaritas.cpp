//Marcos Herrero
#include <iostream>

int pajaritas(int ancho, int alto) {
	if (ancho < 10 || alto < 10) return 0;
	else if (ancho >= alto) return ancho/alto + pajaritas(ancho % alto, alto);
	else return alto/ancho + pajaritas(ancho, alto%ancho);
}

bool resuelveCaso() {
	int ancho, alto;
	std::cin >> ancho >> alto;

	if (ancho == 0 && alto == 0) return false;

	std::cout<< pajaritas(ancho, alto)<<'\n';
	return true;
}

int main() {
	while (resuelveCaso());
}