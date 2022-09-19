
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Tarea {
    long long ini;
    long long fin;
    long long period;
};

bool operator<(Tarea const& i, Tarea const& d) {
    return d.ini < i.ini || (d.ini == i.ini && d.fin < i.fin);
}

bool solapamiento(priority_queue<Tarea> &cola, int t) {
    Tarea top = cola.top(); cola.pop();
    if (top.period > -1) {
        cola.push({ top.ini + top.period, top.fin + top.period, top.period });
    }
    bool solap = false;
    if(top.ini < t)
    {
        while (!solap && !cola.empty() && cola.top().ini < t) {
            Tarea sec = cola.top(); cola.pop();
            solap = sec.ini < top.fin;
            if (sec.period > -1) {
                cola.push({ sec.ini + sec.period, sec.fin + sec.period, sec.period });
            }
            top = sec;
        }
    }
    return solap;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m, t; 
    cin >> n >> m >> t;

    if (!std::cin)  // fin de la entrada
        return false;
   
    priority_queue<Tarea> cola;

    int i;
    for (i = 0; i < n; i++) {
        long long ini, fin;
        cin >> ini >> fin;
        cola.push({ ini, fin, -1 });
    }
    for (i = 0; i < m; i++) {
        long long ini, fin, per;
        cin >> ini >> fin >> per;
        cola.push({ ini, fin, per });
    }
    // resolver el caso posiblemente llamando a otras funciones
    bool solap = solapamiento(cola, t);
    // escribir la solución
    cout << (solap ? "SI" : "NO") << "\n";
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
