
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

 // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


int bfs(int ori, int K, int end, vector<int> const& conectados){
    if (ori == end) return 0;
    vector<int> distancia(conectados.size(), INT_MAX);
    distancia[ori - 1] = 0;
    queue<int> cola; cola.push(ori - 1);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 1; i <= K; i++) {
            int w = v + i;  
            if (w < conectados.size()) {
                if (conectados[w] != -1) w = conectados[w];
                if (distancia[w] == INT_MAX) {
                    distancia[w] = distancia[v] + 1;

                    if (w == end - 1) return distancia[w];
                    else cola.push(w);
                }
            }
        }   
    }
    return 0;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, K, S, E;
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0) {
        return false;
    }
    vector<int> conectados(N * N, -1);
    int a, b;
    for (int i = 0; i < S + E; i++) {
        cin >> a >> b;
        conectados[a - 1] = b - 1;
    }

    cout << bfs(1, K, N * N, conectados) << "\n";
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
