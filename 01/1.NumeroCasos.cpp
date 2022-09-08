
/*@ <answer>
 *
 * Nombre y Apellidos: José María Gómez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 El algoritmo recorre recursivamente el arbol y va acumulando la altura y comprobando que es binario.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool isAVL(bintree<int> const& tree, int min, int maxi, int & height) {

    if (tree.empty()) {
        height = 0;
        return true;
    }
    else {
        //Es binario de busqueda
        bool avlLeft, avlRight;

        //Altura de ambas ramas
        int hLeft, hRight;

        //Recursion
        avlLeft = isAVL(tree.left(), min, tree.root(), hLeft);
        avlRight = isAVL(tree.right(), tree.root(), maxi, hRight);

        //Calculo de la altura del nodo
        height = max(hLeft,hRight) + 1;

        //Comprobacion de condiciones
        //1º ¿Es binario de busqeda?
        bool bin = (tree.root() < maxi) && (tree.root() > min);
        //2º ¿Esta balanceado?
        bool avl = abs(hLeft - hRight) <= 1;
        //3º ¿Cumple lo anterior y sus hijos son avl?
        return avlLeft && avlRight && bin && avl;
    }
}

bool isAVL(bintree<int>& tree) {
    int height = 0;
    return isAVL(tree, INT_MIN, INT_MAX, height);
}

void resuelveCaso() {

    bintree<int> tree;
    tree = leerArbol(-1);
    int height = 0;

    if (tree.empty()) {
        cout << "SI" << endl;
    }
    else {
        bool esAVL = isAVL(tree);

        cout << (esAVL ? "SI" : "NO") << endl;
    }
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
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
