#pragma once
#include "Grafo.h"
#include <vector>
#include <deque>

class ArbolLibre {
private:
	std::vector<bool> visit;
	std::vector<int> ant;
	std::vector<int> arist;
	std::vector<bool> comprob;
	int s;
	bool libre;

	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dfs(G, w);
			}
		}
	};

	bool hayCamino(int v) const {
		return visit[v];
	};

	using Camino = std::deque<int>; // para representar caminos
	// devuelve un camino desde el origen a v (debe existir)
	Camino camino(int v) const {
		if (!hayCamino(v))
			throw std::domain_error("No existe camino");
		Camino cam;
		// recuperamos el camino retrocediendo
		for (int x = v; x != s; x = ant[x])
			cam.push_front(x);
		cam.push_front(s);
		return cam;
	};

	bool esConexo() {
		bool conexo = true;
		int i = 0;
		while (conexo && i < visit.size()) {
			conexo = visit[i];
			i++;
		}
		return conexo;
	};

	bool esAciclico(Grafo const& g) {
		/*for (int i = 0; i < g.V(); i++) {
			if (hayCamino(i)) {
				Camino cam = camino(i);
				for (int j = cam.size() - 1; j > 1; j--) {
					int vert = cam[j];
					if(!comprob[vert])
					{
						for (int a : arist) {
							if (vert == a) {
								return false;
							}
						}
						comprob[vert] = true;
					}
				}
			}
		}
		return true;*/

		return true;
	};

public:
	ArbolLibre(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), s(s), comprob(g.V(), false) {
		dfs(g, s);
		arist = g.ady(s);
		libre = esAciclico(g) && esConexo();
	};

	bool esLibre() const {
		return libre;
	};
};