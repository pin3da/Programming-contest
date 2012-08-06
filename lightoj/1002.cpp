using namespace std;
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAXNODES 505
// 1000 nodes
// 10000 edges

int n;

const int inf=500000;

struct edge{
    int start, end, weight;
    edge() {}
    edge(int s, int e,int w) : start(s), end(e), weight(w) {}
    bool operator < (const edge &that) const {
        return weight < that.weight;
    }
};

int p[MAXNODES], rank[MAXNODES];

/**
Dijkstra
**/

struct ed2{
	int to,weight;
	ed2(){}
	ed2(int t,int w): to(t),weight(w){}
	bool operator < (const ed2 &that) const{
		return weight > that.weight;
	}
};

vector<ed2> g[MAXNODES];
int d[MAXNODES];
int d2[MAXNODES];
int pi[MAXNODES];

int dijkstra(int s, int n){
	//s = nodo inicial, n = n´mero de nodos
	for (int i=0; i<n; ++i){
		d[i] = inf;
		pi[i] = -1;
		d2[i] = 0;
	}
	d[s] = 0;
	priority_queue<ed2> q;
	q.push(ed2(s, 0));
	while (!q.empty()){
		int node = q.top().to;
		int dist = q.top().weight;
		q.pop();
		if (dist > d[node]) continue;
		for (int i=0; i<g[node].size(); ++i){
			int to = g[node][i].to;
			int w_extra = g[node][i].weight;

			if (dist + w_extra < d[to]){
				d[to] = dist + w_extra;
				d2[to]= (d2[node]<w_extra)?w_extra:d2[node];
				pi[to] = node;
				q.push(ed2(to, d[to]));
			}
		}
	}
	return inf;

}



//end Dijkstra

void make_set(int x){ p[x] = x, rank[x] = 0; }

void link(int x, int y){
    if (rank[x] > rank[y]) p[y] = x;
    else{ p[x] = y; if (rank[x] == rank[y]) rank[y]++; }
}
int find_set(int x){
    return x != p[x] ? p[x] = find_set(p[x]) : p[x];
}
void merge(int x, int y){ link(find_set(x), find_set(y)); }

long long kruskal(vector<edge> &e){
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
            g[u].push_back(ed2 (v,w));
            g[v].push_back(ed2 (u,w));
        }
    }    
    return total;
}

int main(){
    int m,cid=0;cin>>m;
    while(m--){
        vector<edge> gr;
        cin>>n;
        int b,t;cin>>b;
        while(b--){
            edge mio;
            cin>>mio.start;
            cin>>mio.end;
            cin>>mio.weight;
            gr.push_back(mio);
        }
        cin>>t;
        memset(p,0,sizeof(p));
      	memset(rank,0,sizeof(rank));
      	for(int i=0;i<MAXNODES;++i)g[i].clear();
		kruskal(gr);
		dijkstra(t,n);
		cout<<"Case "<<++cid<<":\n";
		for(int i=0;i<n;++i)
			if(d[i]!=inf)
				cout<<d2[i]<<endl;
			else 
				cout<<"Impossible"<<endl;
    }
    return 0;
}
