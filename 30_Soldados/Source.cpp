
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
using intPQ = priority_queue<int, std::vector<int>, std::greater<int>>;

int defensa(intPQ& ciudades, intPQ& equipos) {
    int numEquipos = 0;
    int ciudad = ciudades.top(); ciudades.pop();
    while (!equipos.empty()) {
        int equipo = equipos.top(); equipos.pop();
        
        if (equipo >= ciudad) {
            numEquipos++;
            if(!ciudades.empty())
                ciudad = ciudades.top(); ciudades.pop();
        }
    }
    return numEquipos;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin)
        return false;
    // escribir la solución
    intPQ ciudades;
    intPQ equipos;

    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        ciudades.push(x);
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        equipos.push(x);
    }

    cout << defensa(ciudades, equipos) << "\n";

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
