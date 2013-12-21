using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define foreach(it,x) for(typeof x.begin() it = x.begin(); it!=x.end(); ++it)
#define MAXNODES 10001

 
int visited[MAXNODES];
int prev[MAXNODES], low[MAXNODES], d[MAXNODES];
int scc[MAXNODES];
int nbridges[MAXNODES];
vector<int> g[MAXNODES];
set<int> g2[MAXNODES];
vector< pair<int,int> > bridges;

int n, m, ticks;
 
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
                   g2[u].erase(v);
                   g2[v].erase(u);
               }
               low[u] = min(low[u], low[v]);
            }else{
               low[u] = min(low[u], d[v]);
            }
        }
    }
}

int main(){ ___
    int tc;cin>>tc;
    
    for(int tid = 1; tid <= tc; ++tid){
        cin>>n>>m;

        for(int i = 0; i< n; ++i){
            g[i].clear();
            g2[i].clear();
        }
        
        int u,v;
        for(int i = 0; i< m; ++i){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            g2[u].insert(v);
            g2[v].insert(u);            
        }
        
        bridges.clear();
        
        ticks = 0;
        memset(visited,0,sizeof visited);
        memset(nbridges,0,sizeof nbridges);
        
        for (int i=0; i<n; ++i){
            if (!visited[i]){
                dfs(i);
            }
        }
        
        int current_scc = 0;
        memset(visited,0,sizeof visited);
        for (int i=0; i<n; ++i){
            if(visited[i])continue;
            
            queue<int> Q;
            Q.push(i);
            
            while(!Q.empty()){
                int act = Q.front();Q.pop();
                if(visited[act])continue;
                visited[act] = true;
                scc[act] = current_scc;
                foreach(h,g2[act])
                    Q.push(*h);
            }
            current_scc++;
        }
        
        foreach(b, bridges){
            nbridges[scc[b->first]]++;
            nbridges[scc[b->second]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < current_scc; ++i)
            if(nbridges[i] == 1) ans++;
        
        ans = (ans + 1)/2;
        
        printf("Case %d: %d\n",tid,ans);
        
    }
    

    return 0;
}

