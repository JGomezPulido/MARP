/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1: Jose Maria Gomez Pulido MARP20
  * Estudiante 2: Paula Morillas Alonso MARP31
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 El coste en tiempo del problema es O(NlogN), por la ordenacion del vector de pesos.

 Escribe tambi�n una demostraci�n que justifique que tu soluci�n encuentra
 siempre soluciones �ptimas.

 V A1,B1 ... A2,B2 | Ai, Bi 
    ==          ==      !=
 O C1,D1 ... C2,D2 | Ci = Ai, Di .... Cj, Dj = Bi

 La solucion voraz esta ordenada en orden decreciente de A y creciciente de B, La optima solo esta ordenada en orden decreciciente en C.
 Ademas, si una silla va sola, su ocupante esta en A o en C;
 Sabemos que Di >= Bi, porque no ha aparecido aun en la voraz.

 Caso 1: Bi va vacia.
    en este caso si Di va vacia, es la misma solucion. Ademas, sabemos que Di no puede ir ocupada, porque entonces habria sido
    emparejada en la voraz.
 Caso 2: Bi va ocupada.
    -Si Di va ocupada, entonces Bi va a poder emparejarse con Ci, porque ya han sido emparejados en la voraz y Di va a sumar lo mismo o 
      menos con Cj porque este es <= que Ci.
    -Si Di va vacia, se pueden intercambiar sin problemas, ya que Bi esta emparejada con Ci en la voraz, y Cj entra en la silla el solo.
 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>



bool resuelveCaso() {

    int P, N;
    cin >> P >> N;  // n�mero de partidos

    if (!cin)
        return false;

    // leer el resto del caso y resolverlo
    vector<int> pesos(N);
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }
    sort(pesos.begin(), pesos.end());

    int numSillas = 0;
    int j = N - 1;
    for (int i = 0; i < N && j >= i;) {
        if (j == i) {
            --j;
            numSillas++;
        }
        else if (pesos[i] + pesos[j] <= P) {
            ++i;
            --j;
            numSillas++;
        }
        else {
            --j;
            numSillas++;
        }
    }

    cout << numSillas << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

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
