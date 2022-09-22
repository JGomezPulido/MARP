/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Jose Maria Gomez Pulido
 * Estudiante 2: Paula Morillas Alonso
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>
 
 Hemos creado una cola de prioridad para ordenar las cajas, que las ordena primero por menor tiempo
 ocupada y despues por menor numero.

 El algoritmo principal va recibiendo lo que tardan los clientes y sumando su tiempo a la caja mas prioritaria.

 El coste es O(C log N), siendo C el numero de clientes y N el numero de cajas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>


struct Caja {
    int num;
    int ocupada;
};

bool operator <(Caja const& iz, Caja const& der) {
    return der.ocupada < iz.ocupada || (der.ocupada == iz.ocupada && der.num < iz.num);
}
using box_queue = priority_queue <Caja, vector<Caja>, less<Caja>>;


bool resuelveCaso() {
  
  // leemos la entrada
  int cajas, clientes;
  cin >> cajas >> clientes;
  if (cajas == 0)
    return false;
  box_queue cajas_q;
  for (int i = 1; i <= cajas; i++) {
      cajas_q.push({ i, 0 });
  }

  int tiempo = 0, cliente;
  for (int i = 0; i < clientes; i++) {
      cin >> cliente;
      auto c = cajas_q.top(); cajas_q.pop();
      c.ocupada += cliente;
      cajas_q.push(c);
  }
  
  // leer el resto del caso y resolverlo
  cout << (cajas_q.top().num) << "\n";
    
  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
  system("PAUSE");
#endif
  return 0;
}
