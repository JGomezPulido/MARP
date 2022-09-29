
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "median_priority_queue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {

    // leer los datos de la entrada
    int N, evt;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    median_priority_queue cola;
    int pos = 0;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        std::cin >> evt;
        if (evt == 0) {
            //TODO
            if (cola.empty()) {
                cout << "ECSA ";
            }
            else {
                cout << cola.top() << " ";
                cola.pop();
            }
        }
        else {
            cola.push(evt);
        }
    }
    // escribir la solución
    std::cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
