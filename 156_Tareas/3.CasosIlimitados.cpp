
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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class OrdenacionTopografica {
private:
    vector<bool> visit, apilado;
    deque<int> ordenacion;
    bool ciclico;

    void dfs(Digrafo const& g, int v) {
        visit[v] = true;
        apilado[v] = true;
        for (int w : g.ady(v)) {
            if (ciclico) return;
            if (!visit[w]) {
                dfs(g, w);
            }
            else if (apilado[w]) {
                ciclico = true;
            }
        }
        ordenacion.push_front(v+1);
        apilado[v] = false;
    }

public:
    OrdenacionTopografica(Digrafo const& g) : visit(g.V()), apilado(g.V()), ordenacion(), ciclico(false) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                dfs(g, i);
            }
        }
    }

    bool esCiclico() { return ciclico; }
    deque<int> orden() {
        return ordenacion;
    }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
    Digrafo d(cin, 1);
   
   if (!std::cin)  // fin de la entrada
      return false;
   
   OrdenacionTopografica sol(d);
   if (sol.esCiclico())
       cout << "Imposible\n";
   else {
       for (auto i : sol.orden()) {
           cout << i << " ";
       }
       cout << "\n";
   }
   // resolver el caso posiblemente llamando a otras funciones
   
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
