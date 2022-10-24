
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template<typename T>
class Camion {
private:
    vector<bool> visit;
    GrafoValorado<T> grafo;
    bool llegado;

    void dfs(GrafoValorado<T> const& g, int v, int ancho) {
        visit[v] = true;
        for (Arista<T> a : g.ady(v)) {
            if (a.valor() >= ancho) {
                int w = a.otro(v);
                if (!visit[w]) {
                    dfs(g, w, ancho);
                }
            }
        }
    }
public:
    Camion(GrafoValorado<T> const& g, int v, int w, int ancho) : visit(g.V(), false), grafo(g) {
        dfs(g, v, ancho);
        llegado = visit[w];
    }

    bool llega() {
        
        return llegado;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> grafo(cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int N;
    cin >> N;
    int v, w, ancho;
    for (int i = 0; i < N; i++) {
        cin >> v >> w >> ancho;
        bool a = Camion<int>(grafo, v - 1, w - 1, ancho).llega();
        if(a)
            cout << "SI\n";
        else
            cout << "NO\n";
    }
    // escribir la solución

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
