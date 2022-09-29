/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1: Jose Maria Gomez Pulido MARP20	
  * Estudiante 2: Paula Morillas Alonso MARP31
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;
#include "median_priority_queue.h"

/*@ <answer>

 El problema se resuelve con una cola de medianos, que esta formada por una cola de maximos para
 los menores o iguales que la mediana; y una cola de prioridad de mimimos para los mayores que la mediana.

 Los costes de las operaciones de esta cola son de la misma complejidad que los de priority_queue.

 Por tanto el coste total de el algoritmo, que pushea las parejas y mira el mediano, es n*log(n) siendo
 n el numero de parejas.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>



bool resuelveCaso() {
	int N, M;
	cin >> N >> M;

	if (N == 0 && M == 0) return false;

	median_priority_queue cola;

	cola.push(N);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cola.push(a);
		cola.push(b);
		cout << cola.top() << " ";
	}
	cout << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
#define DOMJUDGE
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
