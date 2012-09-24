using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl
#define MAXNODES 100002
#define black 1

template <class T> string toStr(const T &x){ stringstream s; s << x; return s.str(); }

struct edge{
	int ancestor, weight;
	int color;
	long long dist_root;
	vector<int> childrens;
	vector<int> q;
	edge(){}
	
	edge(int aa,int ww): ancestor(aa),weight(ww),color(0){}

	bool operator < (const edge &that) const {
		return weight < that.weight;
	}
};

struct consulta{
	int A,B;
	long long ans;
};

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


vector< pair<int,int> > LCA[MAXNODES];
edge G[MAXNODES];
consulta Q[MAXNODES];

void tarjanOLCA(int u){
	make_set(u);
	G[u].ancestor = u;
	foreach(v,G[u].childrens){
		tarjanOLCA(*v);
		merge(u,*v);
		G[find_set(*v)].ancestor = u;
	}
	G[u].color = black;
	int v;
	for(int i = 0;i < G[u].q.size(); ++i){
		if(u == Q[G[u].q[i]].A)v=Q[G[u].q[i]].B;
		else if(u == Q[G[u].q[i]].B)v=Q[G[u].q[i]].A;
		else  throw "Paila "+ toStr(u);
		if(G[v].color == black)
				Q[G[u].q[i]].ans = G[u].dist_root + G[v].dist_root - 2*G[G[find_set(v)].ancestor].dist_root;
	}
}


int main(){
	int nodes,queries;
	int to,we;
	while(1){
		cin>>nodes;
		if(!nodes)break;
		For(i,nodes+2){
			G[i].childrens = vector<int> ();
			G[i].q = vector<int> ();
		}
		G[0].dist_root=0;
		For(i,nodes-1){
			cin>>to>>we;
			G[i+1].color = 0;
			G[i+1].ancestor = to;
			G[to].childrens.push_back(i+1);
			G[i+1].dist_root = G[to].dist_root + we;
		}
		cin>>queries;
		For(i,queries){
			cin>>to>>we;
			Q[i].A = to;
			Q[i].B = we;
			G[to].q.push_back(i);
			G[we].q.push_back(i);
		}
		try {
			tarjanOLCA(0);
		} catch(string c){
			cout<<c<<endl;
		}
		cout<<Q[0].ans;
		for(int i=1;i<queries;++i){
			cout<<" "<<Q[i].ans;
		}
		cout<<endl;
	}

	return 0;
}
