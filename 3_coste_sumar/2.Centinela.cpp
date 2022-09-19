
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
long long calculaCoste(std::priority_queue<long long, std::vector<long long>, std::greater<long long>> & nums) {
    long long coste = 0;
    while (nums.size() > 1) {
        long long a = nums.top(); nums.pop();
        long long b = nums.top(); nums.pop();
        long costeTemp = a + b;
        coste += costeTemp;
        nums.push(costeTemp);
    }
    return coste;
}


bool resuelveCaso() {
   
   // leer los datos de la entrada
    long long n = 0;
    cin >> n;

   if (n == 0)
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<long long, std::vector<long long>, std::greater<long long>> nums;

   for (long long i = 0; i < n; i++) {
       long long  num;
       cin >> num;
       nums.push(num);
   }

   cout << calculaCoste(nums) << "\n";
   // escribir la solución

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
#define DOMJUDGE
int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt.in");
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
