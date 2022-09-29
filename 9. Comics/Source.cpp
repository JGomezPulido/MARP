/*@ <answer>
 *
 * Sara Isabel Garcia
 *
 @ </answer>/
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

struct comic
{
    int id, indice;
};


bool operator < (comic a, comic b) {
    return b.id < a.id;
}

bool resuelveCaso() {
    int N, k, cont = 0, menorAbsoluto=INT_MAX, id;
    // leer los datos de la entrada
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<list<comic>> v(N);
    priority_queue<comic>tops;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> id;
            if (id < menorAbsoluto) menorAbsoluto = id;
            v[i].push_front({ id, i });
        }
    }

    int menor=INT_MAX;

    //Meto todos los tops
    for (int i = 0; i < N; i++)
        tops.push(*v[i].begin());

    while (menor!=menorAbsoluto)
    {
        auto aux = tops.top();
        tops.pop();
        menor = aux.id;
        v[aux.indice].pop_front();
        if(v[aux.indice].begin() != v[aux.indice].end()) tops.push(*v[aux.indice].begin());
        cont++;
    }
    cout << cont << "\n";

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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}