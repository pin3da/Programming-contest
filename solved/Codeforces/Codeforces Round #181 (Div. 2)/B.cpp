// http://codeforces.com/contest/300/problem/B

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
#define MAXNODES 100

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;
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
int visited[MAXNODES];
int impreso[MAXNODES];
vector<int> cuantos[MAXNODES];

int main(){
    For(i,MAXNODES)make_set(i);
    memset(visited,0,sizeof(visited));
    memset(cuantos,0,sizeof(cuantos));
    memset(impreso,0,sizeof(impreso));
    int n,m;cin>>n>>m;
    int u,v;
    
    For(i,m){
        cin>>u>>v;        
        merge(u,v);
        visited[u] = visited[v] = 1;
    }
    int paila = 0;
    for(int i=1;i<=n;++i){    
        cuantos[find_set(i)].push_back(i);
        if(cuantos[find_set(i)].size() > 3) paila = 1;
    }
    int salida[n/3][3];
    if(!paila){
        int linea = 0;
        for(int i=1;i<=n;++i){    
            if(impreso[i])continue;
            int faltan  = 3;
            int col = 0;
            if(cuantos[find_set(i)].size()==1)continue;
            For(j,cuantos[find_set(i)].size()){
                //cout<<cuantos[find_set(i)][j]<<" ";
                salida[linea][col] = cuantos[find_set(i)][j];
                impreso[cuantos[find_set(i)][j]] = 1;
                faltan--;
                col++;
            }
            for(int j = 1; j<= n and faltan > 0;++j){
                if(!visited[j] and !impreso[j]){
                    //cout<<j<<" ";
                    salida[linea][col] = j;
                    faltan--;
                    visited[j] = 1;
                    impreso[j] = 1;
                    salida;
                }
            }
//            cout<<endl;
            linea++;
            if(faltan!=0) paila = 1;
        }
        int cont = 0;
        int col = 0;
        for(int i=1;i<=n;++i){
            if(cont==3){
              //  cout<<endl;
              linea++;
              col = 0;
                cont = 0;
            }
            if(!impreso[i]){
                //cout<<i<<" ";
                salida[linea][col] = i;
                col++;
                cont++;
            }
            if(i==n and cont==3)linea++;//cout<<endl;
        }
    }
    if(paila)cout<<"-1"<<endl;
    else{
        For(i,n/3){
            For(j,3){
                cout<<salida[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
    
}
