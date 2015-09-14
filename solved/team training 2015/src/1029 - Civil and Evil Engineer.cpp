#include<bits/stdc++.h>
using namespace std;

vector<int> parent,rankt;

struct edge{
	int u,v,c;
	edge(){}
	edge(int _u, int _v, int _c):u(_u),v(_v),c(_c){}
	
	bool operator < (const edge & a) const{
		return c < a.c;
	}
	
};


int init(){
	for(int i = 0; i < parent.size(); i++){ parent[i] = i; rankt[i] = 0;}
}
int find(int x){
	if(parent[x] == x) return x;
	parent[x] = find(parent[x]);
}

bool unionF(int x,int y){
	int px = find(x),py = find(y);
	if(px == py) return 0;
	if(rankt[px] >= rankt[py]){
		if(rankt[px] == rankt[py]) rankt[px]++;
		parent[py] = px;
	}else{
		parent[px] = py;
	}
	return 1;
}

int kruskal(vector<edge> &Q){
	int MST = 0;
	
	for(int i = 0; i < Q.size();i++){
		edge cur = Q[i];

		if(unionF(cur.u,cur.v)){
			MST += cur.c;	
		}
	}
	return MST;
}

int main(){
	int t, nc = 0,u,v,w,n; cin >> t;
	
	parent.resize(105);rankt.resize(105);
	
	while( t-- ){
		vector<edge> minQ,maxQ;

		cin >> n;
		while(cin >> u >> v >> w && u+v+w){
			minQ.push_back(edge(u,v,w));
			maxQ.push_back(edge(u,v,w));
		}
		sort(minQ.begin(), minQ.end());
		sort(maxQ.rbegin(),maxQ.rend());
		init();
		int sol = kruskal(minQ);	
		init();
		sol += kruskal(maxQ);
			
		
		cout << "Case " << ++nc << ": ";

		if(sol&1){
			cout << sol << "/2" << endl;
		}else{
			cout << sol/2 << endl;
		}
	}
		
}
