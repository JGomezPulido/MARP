
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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



using min_q = priority_queue<int, std::vector<int>, std::greater<int>>;
using max_q = priority_queue<int, std::vector<int>, std::less<int>>;

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, evt;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    min_q mayores_ig;
    max_q menores;
    int pos = 0;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        std::cin >> evt;
        if (evt == 0) {
            //TODO
            int size = mayores_ig.size() + menores.size();
            if (size == 0) {
                std::cout << "ECSA ";
            }
            else {
                
                std::cout << mayores_ig.top() << " ";
                mayores_ig.pop();
                size -=1 ;
                if (size % 2 == 0 && !menores.empty()) {
                    mayores_ig.push(menores.top()); menores.pop();
                }
            }
           
        }
        else {
            mayores_ig.push(evt);
            int size = mayores_ig.size() + menores.size();
            if(mayores_ig.size() > 1 && size % 2 == 1) {
                auto p = mayores_ig.top(); mayores_ig.pop();
                menores.push(p);
            }
        }
    }
    // escribir la soluci�n
    std::cout << "\n";
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
