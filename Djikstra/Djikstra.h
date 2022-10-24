#pragma once
#include <vector>
#include <limits>
#include <deque>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
template<typename Valor>
class Djikstra {
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) 
	{
		int v = a.desde(); int w = a.hasta();
		if (dist[w] > dist[v] + a.valor) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			pq.update(w, dist[w]);
		}
	};
public:
	Djikstra(DigrafoValorado<Valor> const& g, Valor orig) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) 
	{
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top(); pq.top();
			for (AristaDirigida<Valor> a : g.ady(v))
				relajar(a);
		}
	};

	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }

	template <typename Valor>
	using Camino = std::deque<Valor>;

	Camino<Valor> camino(int v) const {
		Camino<Valor> cam;
		AristaDirigida<Valor> a;
		for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()]) {
			cam.push_front(a);
		}
		cam.push_front(a);
		return cam;
	}
};