
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
const int MAX = 10000;
const int INF = 1000000000;
int ady(int n, int i) {
    switch (i) {
        case 0: return (n + 1) % MAX;
        case 1: return (n * 2) % MAX;
        case 2: return (n / 3);
    }
}

int bfs(int origen, int destino) {
    if (origen == destino) return 0;
    vector<int> distancia(MAX, INF);
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 0; i < 3; i++) {
            int w = ady(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
                cola.push(w);
            }
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, d;
    cin >> n >> d;

    if (!std::cin)  // fin de la entrada
        return false;

    cout << bfs(n, d) << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
