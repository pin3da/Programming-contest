using namespace std;
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXNODES 1000

typedef vector<int> ad;
typedef map<int, ad> graph;

int color[20005];

int dfs(int n,graph g){
	if(color[n]==1)return true;
	if(color[n]==2)return false;
	color[n]=1;
	for(int i=0;i<g[n].size();++i){
			if(dfs(g[n][i],g))return true;
	}
	color[n]=2;
	return false;
}

void printGraph(graph g){
	foreach(it,g){
		cout<< (*it).first <<" -> ";
		for(int i=0;i<(*it).second.size();++i){
			cout<<(*it).second[i];
		}
		cout<<endl;
	}
}

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		int edges,id=0;cin>>edges;
		map<string, int> cod;
		graph g;
		memset(color,0,sizeof(color));
		while(edges--){
		    string cad;cin>>cad;
		    if(cod.count(cad)==0)
		    	cod[cad]=id++;
		    string cad2;cin>>cad2;
		    if(cod.count(cad2)==0)
		    	cod[cad2]=id++;
		    g[cod[cad]].push_back(cod[cad2]);
		}		
		//printGraph(g);
		int pin=0;
		foreach(it,g){
			if(color[(*it).first]==0)
				if(dfs((*it).first,g)){
					pin=1;
					break;
				}
		}

		cout<<"Case "<<++cid<<": "<<((pin)?"No":"Yes")<<endl;
	}
	
	return 0;
}
