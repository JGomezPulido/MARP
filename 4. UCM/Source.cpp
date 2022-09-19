
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

struct Usuario{
    long id;
    long periodo;
    long momento;
};

bool operator<(Usuario const& i, Usuario const& d) {
    return d.momento < i.momento || (i.momento == d.momento && d.id < i.id);
}

vector<long> orden(priority_queue<Usuario> cola, int k) {
    vector<long> respuesta;
    for (int i = 0; i < k; i++) {
        Usuario k = cola.top(); cola.pop();
        respuesta.push_back(k.id);
        k.momento += k.periodo;
        cola.push(k);
    }
    return respuesta;
}
bool resuelveCaso() {

    int n;
    cin >> n;
    if (n==0)
        return false;

    priority_queue<Usuario> cola;

    for (int i = 0; i < n; i++) {
        long id_us, period;
        cin >> id_us >> period;
        cola.push({ id_us, period, period });
    }

    int k;
    cin >> k;
    // resolver el caso posiblemente llamando a otras funciones
    vector<long> resp = orden(cola, k);
    // escribir la soluci�n
    for (long id : resp) {
        cout << id << "\n";
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
