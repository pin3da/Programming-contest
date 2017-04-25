// http://codeforces.com/contest/129/problem/B

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
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;



int main(){
    int nodos,aristas;cin>>nodos>>aristas;
    vector< set<int> >  G(nodos);
    For(i,aristas){
        int u,v;cin>>u>>v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    int ans = 0;
    while(true){
        int b = 0;
        vector< set<int> > G2 = G;
        int todocero = 1;
        For(i,nodos){
            b |= G[i].size()==1;
            todocero &= G[i].size()==0;
            if(G[i].size()==1){
                if(G2[*G2[i].begin()].find(i)!=G2[*G2[i].begin()].end())
                    G2[*G2[i].begin()].erase(G2[*G2[i].begin()].find(i));
                G2[i].clear();
            }
        }
        G= G2;
        if(!b or todocero)break;
        ans++;
        
    }
    cout<<ans<<endl;
    return 0;
}
