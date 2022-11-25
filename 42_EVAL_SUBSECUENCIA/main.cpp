/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Jose Maria Gomez Pulido MARP20
 * Estudiante 2:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#include "Matriz.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución (tanto en
 tiempo como en espacio), en función del tamaño del problema.
 
 El coste del algoritmo en tiempo es del orden O(N*M), siendo N y M las longitudes de ambas palabras, y en espacio es
 el mismo ya que hay que utilizar una Matriz N*M

 Escribe en particular la especificación y definición de la recurrencia
 en la que te has basado para resolver el problema por programación dinámica.

 La recurrencia es subsecuencia(i,j) que indica la mayor longitud posible de la palabra utilizando los caracteres
 de la primera palabra entre 0 e i, y los caracteres de la segunda palabra, entre 0 y j;
 Casos base:
    subsecuencia(i,M) = 0 y subsecuencia(N,j) = 0;

 Casos recursivos:
    subsecuencia(i,j) = subsecuencia(i+1, j+1), si pal1[i] == pal2[j]
    subsecuencia(i,j) = max(subsecuencia(i+1,j), subscuencia(j,i+1)), si pal1[i] != pal2[j]
  
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



bool resuelveCaso() {
  
  // leemos la entrada
  string X, Y;
  cin >> X >> Y;
  
  if (!cin)
    return false;
      
  int N = X.length();
  int M = Y.length();
  Matriz<int> subsecuencia(N + 1, M + 1, 0);

  for (int i = N - 1; i >= 0; i--) {
      for (int j = M - 1 ; j >= 0; j--) {
          if (X[i] == Y[j]) {
              subsecuencia[i][j] = subsecuencia[i + 1][j + 1] + 1;
          }
          else {
              subsecuencia[i][j] = max(subsecuencia[i + 1][j], subsecuencia[i][j + 1]);
          }
      }
  }

 // cout << subsecuencia[0][0] << "\n";
  int i = 0; int j = 0;
  string sol;
  while(i<N && j<M) {
      if (X[i] == Y[j]) {
          sol.push_back(X[i]);
          i++;
          j++;
      }
      else if (subsecuencia[i][j] == subsecuencia[i + 1][j]) {
          i++;
      }
      else {
          j++;
      }
  }
  cout << sol  << "\n";
  // resolver el caso
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
