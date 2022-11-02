
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
    // escribir la soluci�n
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
