/*
Manuel Pineda
No accepted yet
Dijkstra and minimun spanning tree
*/
using namespace std;
#include<iostream>
#include<climits>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#define MAXNODES 1000
/**MST*/
//Complejidad: O(E log V)
struct edge{
int start, end, weight;
bool operator < (const edge &that) const {
//Si se desea encontrar el ´rbol de recubrimiento de
a
//m´xima suma, cambiar el < por un >
a
return weight < that.weight;
}
};

///////////////// Empieza Union find ////////////////////////
//Complejidad: O(m log n), donde m es el n´mero de operaciones
u
//y n es el n´mero de objetos. En la pr´ctica la complejidad
u
a
//es casi que O(m).
int p[MAXNODES], rank[MAXNODES];
void make_set(int x){ p[x] = x, rank[x] = 0; }
void link(int x, int y){
if (rank[x] > rank[y]) p[y] = x;
else{ p[x] = y; if (rank[x] == rank[y]) rank[y]++; }
}
int find_set(int x){
return x != p[x] ? p[x] = find_set(p[x]) : p[x];
}
void merge(int x, int y){ link(find_set(x), find_set(y)); }
///////////////// Termina Union find ////////////////////////

//e es un vector con todas las aristas del grafo ¡El grafo
//debe ser no digirido!
long long kruskal(const vector<edge> &e){
long long total = 0;
sort(e.begin(), e.end());
for (int i=0; i<=n; ++i){
make_set(i);
}
for (int i=0; i<e.size(); ++i){
int u = e[i].start, v = e[i].end, w = e[i].weight;
if (find_set(u) != find_set(v)){
total += w;
merge(u, v);

/**MST-END*/

struct edge{
	int to ,weight;
	edge() {}
	edge(int t, int w) : to(t), weight(w) {}
	bool operator < (const edge &that) const {
		return weight > that.weight;
	}
};

vector<edge> g[MAXNODES];

int d[MAXNODES]; //d[i] = distancia más corta desde s hasta i
int p[MAXNODES]; //p[i] = predecesor de i en la ruta más corta

int n;
int dijkstra(int s, int t){
	for (int i=0; i<n; ++i){
		d[i] = INT_MAX;
		p[i] = -1;
	}
	d[s] = 0;
	priority_queue<edge> q;
	q.push(edge(s, 0));
	while (!q.empty()){
		int node = q.top().to;
		int dist = q.top().weight;
		q.pop();
		if (dist > d[node]) continue;
		if (node == t)
			return dist;
		for (int i=0; i<g[node].size(); ++i){
			int to = g[node][i].to;
			int w_extra = g[node][i].weight;
			if (dist + w_extra < d[to]){
				d[to] = dist + w_extra;
				p[to] = node;
				q.push(edge(to, d[to]));
			}
		}
	}
	return INT_MAX;
}

void printG(){
	for(int i=0;i<n;++i ){
		cout<<i<<"->";
		for(int j =0; j<g[i].size();++j)
			cout<<g[i][j].to<<"-"<<g[i][j].weight<<" / ";
		cout<<endl;
	}
	
}

int main(){
	int numcas;cin>>numcas;
	int m , u,v,w,cas=0 , t;
	while(numcas--){
		cin>>n>>m;
		for(int i =0; i< n+2;++i)
			g[i].clear();
		while(m--){
			cin>>u>>v>>w;
			edge t(v,w);
			edge t2(u,w);
			g[u].push_back(t);
			g[v].push_back(t2);
		}
		cin>>t;
		printG();
		dijkstra(t,n);
		printf("Case %d:\n",++cas);
		for (int i=0; i<n; ++i){
			if(d[i] == INT_MAX)cout<<"Impossible"<<endl;
			else cout<<d[i]<<endl;
		}
	}
	return 0;
}

