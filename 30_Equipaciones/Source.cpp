
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
using intPQ = priority_queue<int, std::vector<int>, std::greater<int>>;

int defensa(intPQ& jugadores, intPQ& equips) {
    int camisetas = jugadores.size();
    int jugador = jugadores.top(); jugadores.pop();
    while (!equips.empty() && camisetas > 0) {
        int equipo = equips.top(); equips.pop();
        
        if (equipo == jugador || equipo == jugador + 1) {
            camisetas--;
            if (!jugadores.empty()) {
                
                jugador = jugadores.top(); jugadores.pop();
            }
        }
    }
    return camisetas;
}

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    // escribir la soluci�n
    intPQ jugadores;
    intPQ equips;

    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        jugadores.push(x);
    }
    for (int i = 0; i < M; i++) {
        cin >> x;
        equips.push(x);
    }

    cout << defensa(jugadores, equips) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
