// http://codeforces.com/contest/216/problem/B

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

int N;
vvi W;
vi V; 
vi C; 
 
bool dfs(int i,int col) {
	if(!V[i]) { 
		V[i] = true;
        C[i] = col;
		foreach(it,W[i]){
			if( !dfs((*it),(col+1)%2) )
				return false;
        }
		return true;
    }else{
    	return col==C[i];
    }
 } 




int main(){
	int n,m;cin>>n>>m;
	int ori,des;
	W = vvi(n);
	V = vi(n,0);
	C = vi(n);
	For(i,m){
		cin>>ori>>des;
		W[--ori].push_back(--des);
		W[des].push_back(ori);
	}
	
	int ans=0;
	For(i,n){
		if(V[i])continue;
		if( !dfs(i,0))ans++;
	}

	if ((n - ans)%2!=0)
        ans++;
	cout<<ans<<endl;
	return 0;
}









