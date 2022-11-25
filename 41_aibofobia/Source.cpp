
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int aibofobia_no_rec(string const& pal, vector<vector<int>>& aib) {
    int N = pal.length();
    aib = vector<vector<int>>(N, vector<int>(N, 0));

    //POR FILAS

    /*for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            aib[i][j] = pal[i] == pal[j] ?
                aib[i + 1][j - 1] :
                min(aib[i + 1][j], aib[i][j - 1]) + 1;
        }
    }*/

    //POR DIAGONALES
        
    for(int d = 1; d < N; d++){
        for(int i = 0; i < N - d; i++){
            int j = i + d;
            aib[i][j] = pal[i] == pal[j] ?
                aib[i + 1][j - 1] :
                min(aib[i + 1][j], aib[i][j - 1]) + 1;

        }
    }
    
    
    return aib[0][N - 1];
}

int aibofobia_rec(string const& pal, int i, int j, vector<vector<int>>& aib) {
    int& res = aib[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 0;
        else if (pal[i] == pal[j])
            res = aibofobia_rec(pal, i + 1, j - 1, aib);
        else
            res = min(aibofobia_rec(pal, i + 1, j, aib), aibofobia_rec(pal, i, j - 1, aib)) + 1;
    }
    return res;
}

string reconstruir_no_rec(string const& pal, vector<vector<int>> const& aib) {
    int L = pal.length() + aib[0][pal.length() - 1];
    string sol(L, ' ');

    int i = 0; int j = pal.length() - 1; int k = 0;
    while (i <= j) {
        char c;
        if (pal[i] == pal[j]) {
            c = pal[i];
            i++;
            j--;
        }
        else if(aib[i][j] == aib[i + 1][j] + 1) {
            c = pal[i];
            i++;
        }
        else {
            c = pal[j];
            j--;
        }

        sol[k] = c;
        sol[L - k - 1] = c;
        k++;
    }
    return sol;
}

void reconstruir(string const& pal, vector<vector<int>> const& abi, int i, int j, string& sol) {
    if (i > j) return;
    if (i == j) sol.push_back(pal[i]);
    else if (pal[i] == pal[j]) {
        sol.push_back(pal[i]);
        reconstruir(pal, abi, i + 1, j - 1, sol);
        sol.push_back(pal[j]);
    }
    else if (abi[i][j] == (abi[i + 1][j] + 1)) {
        sol.push_back(pal[i]);
        reconstruir(pal, abi, i + 1, j, sol);
        sol.push_back(pal[i]);
    }
    else if (abi[i][j] == (abi[i][j - 1] + 1)) {
        sol.push_back(pal[j]);
        reconstruir(pal, abi, i, j - 1, sol);
        sol.push_back(pal[j]);
    }
}

bool resuelveCaso() {

    string pal;
    cin >> pal;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<vector<int>> aib(pal.length(), vector<int>(pal.length(), -1));
    // resolver el caso posiblemente llamando a otras funciones
    cout << aibofobia_no_rec(pal , aib) << " ";
    
    
    // escribir la solución
    string sol;
    //reconstruir(pal, aib, 0, pal.length() - 1, sol);
    cout << reconstruir_no_rec(pal,aib) << "\n";
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
