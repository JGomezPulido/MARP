
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

using Map = vector<string>;

class Mancha {
    Map map;
    int max_set;
    ConjuntosDisjuntos conjunto;

public:
    Mancha(Map const& mapa) : map(mapa), conjunto(mapa.size() * mapa.size()) {

    };
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int F, C;
    cin >> F >> C;

    if (!std::cin)  // fin de la entrada
        return false;

    Map mapa(F, string(C,' '));
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < F; i++) {
        getline(cin, mapa[i]);
    }

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
    // escribir la soluci�n

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
