using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 2000

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

int pagina[5010];

vector<int> G[5010];
int padre[5010];
int numpag[5010];
int ultimo[5010];

pair<int,int> bfs(int start,int pactual){
	int visited[5010];
	queue<pair<int,int> > Q;
	memset(visited,0,sizeof(visited));
	Q.push(make_pair(start,0));
	int mmin = 1<<30;
	int mmax = -1;
	int posmin=start;
	int posmax=start;
	
	if(G[start].size()==0){
		return make_pair(ultimo[start] - pactual+1, ultimo[start] - pactual+1);
	}
	
	while(!Q.empty()){
		pair<int,int> actual = Q.front();Q.pop();
		int act = actual.first;
		if(visited[act])continue;
		visited[act] = true;
		if(G[act].size()==0){
			mmax = max(mmax,actual.second+numpag[act]);
			mmin = min(mmin,actual.second+numpag[act]);
		}
		foreach(h,G[act]){
			if(act==start)
				Q.push(make_pair( (*h), ultimo[act]-pactual+1));
			else
				Q.push(make_pair((*h),actual.second+ numpag[act]));
		}
	}
	return make_pair(mmin,mmax);
}

int contar(int nfin,int nini,int actual){
	int ans=0;
	int mio = nfin;
	while(mio!=nini){
		ans+= numpag[mio];
		mio = padre[mio];
	}
	ans += ultimo[mio]-actual +1;
	return ans;
}


int main(){	
	int T;cin>>T;
	for(int tid= 1;tid<=T;tid++){
		int nnodes;cin>>nnodes;
		For(i,nnodes)
			G[i].clear();
		memset(padre,0,sizeof(padre));
		
		For(i,nnodes){
			int a,b;cin>>a>>b;
			numpag[i] = b-a+1;
			ultimo[i] = b;
			for(int j=a;j<=b; ++j) pagina[j]=i;
			int desde;cin>>desde;
			if(desde != -1){
				G[desde].push_back(i);
				padre[i] = desde;
			}
		}
		int queries;cin>>queries;
		cout<<"Caso "<<tid<<":"<<endl;
		For(i,queries){
			int actual;cin>>actual;
			pair<int,int> ans = bfs(pagina[actual],actual);
			//cout<<contar(ans.first,pagina[actual],actual)<<" "<<contar(ans.second,pagina[actual],actual)<<endl;
			cout<<ans.first<<" "<<ans.second<<endl;
			
		}
	
	}

	return 0;
}
