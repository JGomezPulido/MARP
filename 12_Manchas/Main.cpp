
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
    using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class MaximaMancha {
private:
    vector<vector<bool>> visitados;
    size_t maximo;
    int num;
    size_t F, C;

    vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {-1, 0}, {0,-1} };

    size_t dfs(vector<string> const& g, int i, int j) {
        visitados[i][j] = true;
        size_t tam = 1;
        
        for (auto dir : dirs) {
            int ni = i + dir.first; int nj = j + dir.second;
            if (correcta(ni, nj) && g[ni][nj] == '#' && !visitados[ni][nj]) {
                tam += dfs(g, ni, nj);
            }
        }
        return tam;
    }

    bool correcta(int i, int j) const{
        return i >= 0 && i < F && j >= 0 && j < C;
    }

public:
    MaximaMancha(vector<string> const& g) : F(g.size()), C(g[0].size()), maximo(0), num(0) {
        visitados = vector<vector<bool>>(F, vector<bool>(C, false));
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!visitados[i][j] && g[i][j] == '#') {
                    ++num;
                    size_t tam = dfs(g, i, j);
                    maximo = max(maximo, tam);
                }
            }
        }
    }

    int numero() { return num; }
    size_t tamano() { return maximo;  }
};

bool resuelveCaso() {

    int F, C;
    cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<string> map(F);
    // resolver el caso posiblemente llamando a otras funciones
    for (auto & s : map) {
        cin >> s;
    }
    // escribir la solución
    MaximaMancha manchas(map);
    cout << manchas.numero() << " " << manchas.tamano() << '\n';
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
