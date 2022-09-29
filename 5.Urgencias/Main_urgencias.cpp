
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
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

struct Paciente {
    int orden;
    int gravedad;
    string nombre;
};

bool operator<(Paciente const izq, Paciente const& der) {
    return (izq.gravedad < der.gravedad || (izq.gravedad == der.gravedad && der.orden < izq.orden));
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    priority_queue<Paciente> cola;

    vector<string> pacientes;
    char ev;
    for (int i = 0; i < n; i++) {
       
        cin >> ev;
        if (ev == 'I') {
            string nombre;
            int grav;
            cin >> nombre >> grav;
            cola.push({i, grav, nombre });
        }
        else if (ev == 'A') {
            auto p = cola.top(); cola.pop();
            pacientes.push_back(p.nombre);
        }
    }

    for (auto n : pacientes) {
        cout << n << "\n";
    }
    cout << "---" << "\n";
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
