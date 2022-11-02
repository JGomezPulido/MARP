
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int numParches(vector<int> const& agujeros, int parche) {
    int parc = 1;
    int dist = 0;
    for (int i = 1; i < agujeros.size(); i++) {
        if (agujeros[i] - agujeros[i - 1] + dist > parche) {
            dist = 0;
            parc++;
        }
        else {
            dist += agujeros[i] - agujeros[i - 1];
        }
    }
    return parc;
}

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    // escribir la solución
    vector<int> agujeros(N);
    int x;
    for (int i = 0; i < N; i++) {
        
        cin >> agujeros[i];
    }
    

    cout << numParches(agujeros, M) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
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
