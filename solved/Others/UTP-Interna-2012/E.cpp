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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
const double eps = 1e-9;
typedef long long int lli;
typedef pair<int , int> pii;

int visited[1001];
map<int,int> tol;
map<string,int> cod;
map<int,string> decod;

int bfs(vector<vector<int> > &G ,int s){
    queue<int> Q;
    Q.push(s);
    int val=0,ans;
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        if(visited[act]) continue;
        visited[act] = true;
        if(tol[act] > val){
            val = tol[act];
            ans = act;
        }
        For(i,G[act].size()){
            Q.push(G[act][i]);
        }
    }
    return ans;

}

int main(){
    int n,m;
    while(cin>>n>>m and n+m){
        tol.clear();
        cod.clear();
        decod.clear();
        string name;
        int tolerancia;
        int actual = 0;
        For(i,n){
            cin>>name>>tolerancia;
            cod[name] = actual;
            decod[actual] = name;
            tol[actual] = tolerancia;
            actual++;
        }
        string u,v;
        vector< vector<int> > G(n);
        For(i,m){
            cin>>u>>v;
            G[cod[u]].push_back(cod[v]);
            G[cod[v]].push_back(cod[u]);
        }
        memset(visited,0,sizeof(visited));
        set<string> ans;
        For(i,n){
            if(visited[i])continue;
            ans.insert(decod[bfs(G,i)]);
        }
        foreach(xx,ans){
            cout<<(*xx)<<endl;
        }
        
    }
    
    return 0;
}
