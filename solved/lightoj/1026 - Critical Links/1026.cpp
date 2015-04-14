#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#define foreach(x,v) for(typeof ((v).begin()) x = (v).begin(); x != (v).end() ; ++x)
using namespace std;

const int MP = 10001;

int visited[MP];
int prev[MP], low[MP], d[MP];
vector< vector<int> > g;
vector< pair<int,int> > bridges;
int n, ticks;

void dfs(int u){
    visited[u] = true;
    d[u] = low[u] = ticks++;
    for (int i=0; i<g[u].size(); ++i){
        int v = g[u][i];
        if (prev[u] != v){
            if(!visited[v]){
               prev[v] = u;
               dfs(v);
               if (d[u] < low[v]){
                   bridges.push_back(make_pair(min(u,v),max(u,v)));
               }
               low[u] = min(low[u], low[v]);
            }else{
               low[u] = min(low[u], d[v]);
            }
        }
    }
}

int main(){
    int ncases;scanf("%d",&ncases);
    for(int id = 1 ; id<=ncases; ++id){
        printf("Case %d:\n",id);
        scanf("%d",&n);
        memset(visited,false,sizeof(visited));
        memset(prev,-1,sizeof(prev));
        g.assign(n, vector<int>());
        bridges.clear();
        if (n == 0){ printf("0 critical links\n"); continue; }
        
        for (int i=0; i<n; ++i){
            int node, deg;
            scanf("%d (%d)", &node, &deg);
            g[node].resize(deg);
            for (int k=0, x; k<deg; ++k){
                scanf("%d", &x);
                g[node][k] = x;
            }
        }
        
        ticks = 0;
        for (int i=0; i<n; ++i){
            if (!visited[i]){
                dfs(i);
            }
        }
        
        sort(bridges.begin(), bridges.end());

        printf("%d critical links\n", bridges.size());
        foreach(p, bridges)
            printf("%d - %d\n", p->first, p->second);
    }
    return 0;
}

