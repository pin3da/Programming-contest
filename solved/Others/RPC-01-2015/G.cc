using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int INF = 20000000;
struct edge {
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
	int N;
	vector<vector<edge> > G;
	vector<edge *> dad;
	vector<int> Q;
	Dinic (int N) : N(N) , G(N), dad(N), Q(N) {}
	void addEdge(int from, int to, int cap) {
		G[from].push_back(edge(from, to, cap, 0, G[to].size()));
		if (from == to) 
			G[from].back().index++;
		G[to].push_back(edge(to, from, 0, 0, G[from].size() - 1));
	}
	long long blockingFlow(int s, int t) {
		fill(dad.begin(), dad.end(), (edge *) NULL);
		dad[s] = &(G[0][0]) - 1;
		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail) {
			int x = Q[head++];
			for (int i = 0; i < G[x].size(); ++i) {
				edge &e = G[x][i];
				if (!dad[e.to] && e.cap - e.flow > 0) {
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}
		if (!dad[t])
			return 0;
		long long totflow = 0;
		for (int i = 0; i < G[t].size(); ++i) {
			edge * start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for (edge * e = start; amt && e != dad[s]; e = dad[e->from]) {
				if (!e) {
					amt = 0;
					break;
				}
				amt = min(amt, e->cap - e->flow);
			}
			if (amt == 0) 
				continue;

			for (edge * e = start; amt && e != dad[s]; e = dad[e->from]) {
				e-> flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		return totflow;
	}
	long long getMaxFlow(int s, int t) {
		long long totflow = 0;
		while (long long flow = blockingFlow(s, t))
			totflow += flow;
		return totflow;
	}
}; 

void solve() {
	int n, m, k;
	cin >> n >> m >> k; 
	double x, y;
	int source = n + m;
	int sink   = source + 1;
	Dinic g(sink + 10);

	for (int i = 0; i < k; ++i)	{
		cin >> x >> y;
		int nx = floor(x);
		int ny = floor(y);
		g.addEdge(nx, ny + n, 1);
	}

	for (int i = 0; i < n; ++i)	{
		g.addEdge(source, i, 1);
	}

	for (int i = 0; i < m; ++i) {
		g.addEdge(n + i, sink, 1);
	}

	cout << g.getMaxFlow(source, sink) << endl;

}

int main() {
	int R;
	cin >> R;
	for (int tc = 0; tc < R; ++tc) 	{
		solve();
	}
	return 0;
}