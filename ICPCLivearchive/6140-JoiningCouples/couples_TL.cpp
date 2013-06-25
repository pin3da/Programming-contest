using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>

#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXN 100010

int n,nr;

vector<int> g[MAXN];
vector<int> g2[MAXN];

int d[MAXN], low[MAXN], scc[MAXN], size_scc[MAXN];
int root_scc[MAXN];
int dist_root[MAXN]; //distance to local root (cycle)
int incoming[MAXN];
int droot[MAXN]; // distance to LCA root
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

//////////// start - Union find /////////////

int p[MAXN];
int find_set(int x){return p[x]==x ? x : p[x] = find_set(p[x]);}
int union_set(int x, int y){p[find_set(y)] = find_set(x);}

//////////// end - Union find /////////////

/**
* Tarjan's algorithm for finding strongly connected
* components.
* Complexity: O(E + V)
*/

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
            size_scc[current_scc]++;
        }while (u != v);
        current_scc++;
    }
}

/////////// end - Tarjan SCC ////////////

void build_ng(int node, vector<int> &visited){
    queue<int> Q;
    Q.push(node);
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        visited[act] = true;
        for(int i = 0; i< g[act].size(); ++i){
            if(scc[act] != scc[g[act][i]]){
                root_scc[scc[act]] =  act;
                root_scc[scc[g[act][i]]] = g[act][i];
                g2[scc[act]].push_back(scc[g[act][i]]);
                incoming[scc[g[act][i]]]++;
            }
            if(!visited[g[act][i]]) Q.push(g[act][i]);
        }
        
    }
    if(root_scc[scc[node]]==-1) root_scc[scc[node]] = node;
    
}

void fill_dist(int node){
    
    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(node);
    dist_root[node] = 0;
    
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        visited[act] = true;
        for(int i = 0; i< g[act].size(); ++i){
            if(visited[g[act][i]]) continue;
            if(scc[act] == scc[g[act][i]])
                dist_root[g[act][i]] = dist_root[act] +1;
            Q.push(g[act][i]);
        }
    }
    
}

/////////// start - LCA ////////////

int T[MAXN];
int P[MAXN];
int L[MAXN];

void fill_LAC(int node){
    L[node] = 0;
    droot[node] = 0LL;
    
    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(node);
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        visited[act] = true;
        for(int i = 0; i< g2[act].size(); ++i){
            if(visited[g2[act][i]])continue;
            T[g2[act][i]] = act;
            L[g2[act][i]] = L[act] + 1;
            droot[g2[act][i]] = droot[act] + 1;
            Q.push(g2[act][i]);
        }
    }    
}

void prepare(int root){
    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int node = Q.front();Q.pop();
        if(visited[node])continue;
        visited[node] = true;
        
        if (L[node] < nr)
            P[node] = 1;
        else
            if(!(L[node] % nr)) // beginning of a section
                P[node] = T[node];
            else
                P[node] = P[T[node]];
                
        for(int i = 0; i< g[node].size(); ++i)
            Q.push(g[node][i]);
    }
}

int LCA(int x, int y){
    while (P[x] != P[y])
      if (L[x] > L[y])
         x = P[x];
      else
         y = P[y];
    
    while (x != y)
      if (L[x] > L[y])
         x = T[x];
      else
         y = T[y];
    
    return x;
}

/////////// end - LCA ////////////
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n){
        memset(d,-1,sizeof d);
        memset(scc,-1,sizeof scc);
        memset(stacked,0,sizeof stacked);
        memset(size_scc,0,sizeof size_scc);
        memset(incoming,0,sizeof incoming);
        memset(root_scc,-1,sizeof root_scc);
        s = stack<int> ();
        ticks = 0;
        current_scc = 0;
        nr = sqrt(n);
        for(int i = 0 ; i< n; ++i){
            g[i].clear();
            g2[i].clear();
            p[i] = i;
        }

        int t;
        for(int i = 0; i< n; ++i){
            cin>>t;
            g[i].push_back(t-1);
            union_set(i,t-1);
        }
        
        for(int i = 0; i< n ; ++i)
            if(scc[i] == -1) tarjan(i);
         
           
        vector<int> visited(n,0);
        for(int i = 0; i< n; ++i)
            if(!visited[i])
                build_ng(i,visited);

        
        for(int i = 0; i< current_scc; ++i){
            fill_dist(root_scc[i]);
            if(incoming[i]==0){
                fill_LAC(i);
                prepare(i);
            }
                
        }
                
        int queries;cin>>queries;
        int u,v;
        for(int i = 0; i< queries ; ++i){
            cin>>u>>v;
            u--; v--;
            if(scc[u] == scc[v]){
                int ans = min(fabs(dist_root[u] - dist_root[v]) , size_scc[scc[u]] - fabs(dist_root[u] - dist_root[v]));
//                D(dist_root[u]);
                cout<<ans<<endl;
            }else if(find_set(u) == find_set(v)){
                int ans = droot[scc[u]]+ droot[scc[v]] - 2LL*droot[LCA(scc[u],scc[v])];
                int aa = min(dist_root[u],size_scc[scc[u]] - dist_root[u] );
                int bb = min(dist_root[v],size_scc[scc[v]] - dist_root[v] );
                cout<<ans+aa+bb<<endl;
                
            }else{
                cout<<-1<<endl;
            }
        }
    }
    
    return 0;
}


