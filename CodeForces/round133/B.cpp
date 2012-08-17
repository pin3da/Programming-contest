using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MP 1010

const double pi=acos(-1);

using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAXNODES 100

typedef vector<int> vi;
typedef vector<vi> vvi;

int N; // number of vertices 
vi W[MAXNODES]; // graph 
vi V; // V is a visited flag 
 
void dfs(int i) { 
	if(!V[i]) { 
            V[i] = true;
            for_each(all(W[i]), dfs); 
    } 
 } 




int main(){
	int n,m;cin>>n>>m;
	int ori,des;
	For(i,m){
		cin>>ori>>des;
		W[--ori].push_back(--des);
	}
	
	int ans=0,sz=n/2;
	vi asig(n, false);
	set<int> g1,g2;
	for(int i=0;i<n && g1.size()< sz;++i){
		int pin=0;
		if(asig[i])continue;
		if(g1.count(i)>0)continue;
		V = vi(n, false);dfs(i);
		foreach(it,g1)
			if(V[(*it)]){
				pin=1;
				break;
			}
			
		if(pin)continue;
		g1.insert(i);
		asig[i]=true;
	}
	
	for(int i=0;i<n && g2.size()< sz;++i){
		int pin=0;
		if(asig[i])continue;
		if(g2.count(i)>0)continue;
		V = vi(n, false);dfs(i);
		foreach(it,g2)
			if(V[(*it)]){
				pin=1;
				break;
			}
		if(pin)continue;
		g2.insert(i);
		asig[i]=true;
	}
	
	
	For(i,n){
		if(!asig[i])ans++;
		//else 		D(i);
	}
		
	cout<<ans<<endl;
	return 0;
}









