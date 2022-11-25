
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
const int INF = 1000000000;
struct Varilla {
    int longitud;
    int precio;
};
void soloUnVector(vector<Varilla>& varillas, vector<bool>& posible, int N, int L) {
    posible = vector<bool>(L + 1, false);
    posible[0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = L; j >= varillas[i].longitud; j--) {
            posible[j] = posible[j - varillas[i].longitud] || posible[j];
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, L;
    cin >> N >> L;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<Varilla> varillas(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> varillas[i].longitud >> varillas[i].precio;
    }

    //vector<vector<bool>> posible(N + 1, vector<bool>(L + 1));

    //for (int i = 0; i <= N; i++) {
    //    posible[i][0] = true;
    //}

    //for (int i = 1; i <= L; i++) {
    //    posible[0][i] = false;
    //}
    //// resolver el caso posiblemente llamando a otras funciones

    //for(int i = 1; i <= N; i++)
    //{
    //    for (int j = 1; j <= L; j++) {
    //        posible[i][j] = varillas[i].longitud <= j ?
    //            posible[i - 1][j - varillas[i].longitud] ||
    //            posible[i - 1][j] :
    //            posible[i - 1][j];
    //    }
    //}
    vector<bool> posible;
    soloUnVector(varillas, posible, N, L);
    // escribir la solución
    if (posible[L])
        cout << "SI\n";
    else
        cout << "NO\n";

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
