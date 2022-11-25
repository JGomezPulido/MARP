/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: JOSE MARIA GOMEZ PULIDO MARP20
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El coste en tiempo del algoritmo es de o(B*PMAX), siendo B el numero de bombillas, y PMAX la potecia maxima, 
 si se hace con una matriz, el coste en espacio es el mismo que el de tiempo. Si se utiliza un vector, el coste 
 en espacio seria O(PMAX)

 La recursion utilizada es la siguiente:
 coste(i,j) = coste minimo necesitado para satisfacer la potencia j, con bombillas de clase entre 1 e i;

 casos base:
 coste(0,j) = INF, si j > 0
 coste(i,0) = 0

 casos recursivos:
 coste(i,j) si potencia[i] > j == coste(i-1,j)
 coste(i,j) si potencia[i] <= j == min(coste(i-1,j), coste(i, j - potencia[i]) + coste[i]) 

 Escribe también una demostración que justifique que tu solución encuentra
 siempre soluciones óptimas.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

const int INF = 100000000;

struct Bombilla {
    int potencia;
    int coste;
};

bool resuelveCaso() {
    int B, PMAX, PMIN;
    cin >> B >> PMAX >> PMIN;
    if (!cin)
        return false;

    vector<Bombilla> bombillas(B + 1); // 1-based
    
    for (int i = 1; i <= B; ++i) {
        cin >> bombillas[i].potencia;
    }

    for (int i = 1; i <= B; ++i) {
        cin >> bombillas[i].coste;
    }

    //SOLUCION CON MATRIZ
    /*vector<vector<int>> costes(B + 1, vector<int>(PMAX + 1, INF));
    for (int i = 0; i <= B; ++i)
        costes[i][0] = 0;

    for(int i = 1; i<=B; i++)
    {
       
        for (int j = 1; j <= PMAX; ++j) {
            if (bombillas[i].potencia > j)
                costes[i][j] = costes[i - 1][j];
            else
                costes[i][j] = min(costes[i - 1][j], costes[i][j - bombillas[i].potencia] + bombillas[i].coste);
        }
    }

    int solucion = INF;
    int jSol = 0;
    for(int j = PMIN; j <= PMAX; j++ ){
        if (costes[B][j] < solucion) 
        {
            solucion = costes[B][j];
            jSol = j;
        }
    }
    if (solucion < INF)
    {
        cout << solucion << " " << jSol << "\n";
    }
    else
        cout << "IMPOSIBLE\n";*/

    //SOLUCION CON VECTOR
    vector<int> coste(PMAX + 1, INF);
    coste[0] = 0;

    for (int i = 1; i <= B; i++) {
        for (int j = bombillas[i].potencia; j <= PMAX; j++) {
            coste[j] = min(coste[j], coste[j - bombillas[i].potencia] + bombillas[i].coste);
        }
    }

    int solucion = INF;
    int jSol = 0;
    for (int j = PMIN; j <= PMAX; j++) {
        if (coste[j] < solucion)
        {
            solucion = coste[j];
            jSol = j;
        }
    }
    if (solucion < INF)
    {
        cout << solucion << " " << jSol << "\n";
    }
    else
        cout << "IMPOSIBLE\n"; 
    return true;

}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
