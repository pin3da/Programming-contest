//Not correct yet.

using namespace std;
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
#include <cstring>
#define MAXN 20005
#define D(x) cout<< #x " = "<<(x)<<endl

vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan(int u){
	d[u] = low[u] = ticks++;
	s.push(u);
	stacked[u] = true;
	const vector<int> &out = g[u];
	for (int k=0, m=out.size(); k<m; ++k){
		const int &v = out[k];
		if (d[v] == -1){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (stacked[v]){
			low[u] = min(low[u], low[v]);
		}
	}
	if (d[u] == low[u]){
	int v;
	do{
		v = s.top();
		s.pop();
		stacked[v] = false;
		scc[v] = current_scc;
	}while (u != v);
	current_scc++;
	}
}

int main(){
    int numcas;cin>>numcas;
    int cid=0;
	while(numcas--){
		map<string, int> cod;  
		for(int i =0;i<MAXN;++i){
			g[i].clear();
			d[i]=-1;
			scc[i]=-1;
			low[i]=-1;
			stacked[i]=false;
		}
		stack<int> s1;
		s=s1;
		ticks=current_scc=0;
		int edges,id=0;cin>>edges;
		while(edges--){
		    string cad;cin>>cad;
		    if(cod.count(cad)==0)
		    	cod[cad]=id++;
		    string cad2;cin>>cad2;
		    if(cod.count(cad2)==0)
		    	cod[cad2]=id++;
		    g[cod[cad]].push_back(cod[cad2]);
		}
		tarjan(0);
		char check[id];
		char pin=0;
		memset(check,0,sizeof(check));
		for(int i=0;i<id;++i){
			if(check[scc[i]]!=0){
				pin=1;
				//break;
			}
			check[scc[i]]++;
		}
		cout<<"Case "<<++cid<<": "<<((pin)?"No":"Yes")<<endl;
	}
    return 0;
}
