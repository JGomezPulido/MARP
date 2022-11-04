
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
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
using intPQ = priority_queue<int, vector<int>, std::greater<int>>;

int defensa(intPQ& jugadores, intPQ& equips) {
    int camisetas = jugadores.size();
    int equipo, jugador;
    deque<int> aux;
    while (!jugadores.empty() && camisetas > 0) {
        jugador = jugadores.top(); jugadores.pop();
        
        while (!equips.empty())
        {
            equipo = equips.top(); equips.pop();
            if (equipo == jugador || equipo == jugador + 1) {
                camisetas--;
                break;
            }
            else if(equipo > jugador + 1) {
                aux.push_back(equipo);
                break;
            }
        }
        while (!aux.empty()) {
            equips.push(aux.front());
            aux.pop_front();
        }
    }
    return camisetas;
}

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    // escribir la solución
    intPQ jugadores;
    intPQ equips;

    int x;
   
    //deque<int> equips(M);
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
