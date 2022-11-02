
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

int numParches(vector<int> const& agujeros, int parche) {
    int parc = 1;
    int dist = 0;
    for (int i = 1; i < agujeros.size(); i++) {
        if (agujeros[i] - agujeros[i - 1] + dist > parche) {
            dist = 0;
            parc++;
        }
        else {
            dist += agujeros[i] - agujeros[i - 1];
        }
    }
    return parc;
}

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin)
        return false;
    // escribir la soluci�n
    vector<int> agujeros(N);
    int x;
    for (int i = 0; i < N; i++) {
        
        cin >> agujeros[i];
    }
    

    cout << numParches(agujeros, M) << "\n";

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
