
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase
using namespace std;
/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
   
   // leer los datos de la entrad
    int n;
    cin >> n;
    Set<int> set;

   if (n == 0)
      return false;
   
   for (int i = 0; i < n; i++) {
       int e;
       cin >> e;
       set.insert(e);
   }
   int m;
   cin >> m;
   
   vector<int> minimums(m , -1);

   for (int i = 0; i < m; i++) {
       int index;
       cin >> index;
       try {
           minimums[i] = set.kesimoMenor(index);
       }
       catch (std::out_of_range& e) {}
   }
   
   
   // escribir la solución
   for (int e : minimums) {
       if (e != -1) cout << e << endl;
       else cout << "??" << endl;
   }

   for (int i = 0; i < 10; i++) {
       if (i == 0) break;
   }

   cout << "---" << endl;

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
