#include<bits/stdc++.h>
using namespace std;

vector<int> parent,rankt;
int n;

struct edge{
	int u,v,c;
	edge(){}
	edge(int _u, int _v, int _c):u(_u),v(_v),c(_c){}
	
	bool operator < (const edge & a) const{
		return c < a.c;
	}
	bool operator > (const edge & a) const{
		return c > a.c;
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

	
	for(int i = 0; i < Q.size(); i++){
		edge cur = Q[i];
		
		if(find(cur.u) != find(cur.v) ){
			unionF(cur.u,cur.v);
			MST += cur.c;	
		}
	}
	return MST;
}

int main(){
	int t, nc = 0,u,v,w,n; cin >> t;
	
	parent.resize(1005);rankt.resize(1005);
	
	while( t-- ){
		vector<edge> minQ;

		cin >> n;
		int sum = 0;
		set<int> nodes;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> v;
				sum += v;
				if(v && i != j){
					minQ.push_back(edge(i,j,v));
				}
			}
		}
		sort(minQ.begin(), minQ.end());
		init();
		int sol = kruskal(minQ);	
			
		
		cout << "Case " << ++nc << ": ";
		for(int i = 0; i < n; i++){nodes.insert(find(i));}
		if(nodes.size() == 1 )
			cout << sum - sol << endl;
		else
			cout << -1 << endl;
	}
		
}
