
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
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
struct Tesoro {
    int profundidad;
    int valor;
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int T, N;

    cin >> T >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<Tesoro> tesoros(N);
    for (int i = 0; i < N; i++) {
        cin >> tesoros[i].profundidad >> tesoros[i].valor;
    }

    vector<vector<int>> valor(N + 1, vector<int>(T + 1, 0));
    for (int i = 1; i <= N; i++) {
        
        for (int j = 1; j <= T; j++) {

            valor[i][j] = 3 * tesoros[i - 1].profundidad <= j ?
                max(valor[i - 1][j], valor[i - 1][j - 3 * tesoros[i - 1].profundidad] + tesoros[i - 1].valor) :
                valor[i-1][j];
         
        }
    }
    // escribir la soluci�n
    cout << valor[N][T] << "\n";
    int i = N, j = T;
    int num = 0;
    list<Tesoro> sol;
    while (i > 0 && j > 0) {
        if(valor[i][j] != valor[i-1][j]){
            ++num;
            j -= 3 * tesoros[i - 1].profundidad;
            sol.push_front(tesoros[i - 1]);
        }
        i--;
    }
    cout << num << "\n";
    for(auto t : sol)
        cout << t.profundidad << " " << t.valor << "\n";
    cout << "---\n";
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
