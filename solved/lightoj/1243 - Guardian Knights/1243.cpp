/**
* This solution get TIME LIMIT EXCEEDED
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXN 101

char grid[MAXN][MAXN];
int id_pos[MAXN][MAXN];
int visited[MAXN][MAXN];

int valid(char a){
    return (a >= 'A' and a <= 'Z') or a=='m';
}

typedef int ll;

struct flow{
    ll cost, flow;
};

struct edge{
    int v; ll cost, cap, flow;
    edge(): v(0), cost(0), cap(0), flow(0) {}
    edge(int _v, ll _cap, ll _cost, ll _flow):
        v(_v), cap(_cap), cost(_cost), flow(_flow){}
};

int fila[2][MAXN], lbl[2][MAXN], qf[2];
ll dist[MAXN];
edge edges[MAXN*MAXN*2];
int grau[MAXN], pai[MAXN], adj[MAXN][MAXN], NV, S, T, e_counter;
const int inf = 1000000000;

struct MCMF {
    void init(int n) {
        NV = n+2; S = n; T = n+1; e_counter = 0;
        for(int i = 0; i < NV; i++) grau[i] = 0;		
    }
    void insert_edge(int v1, int v2, int cap, int cost) {
        edges[e_counter++] = edge(v2, cap, cost, 0);
        edges[e_counter++] = edge(v1, 0, -cost, 0);
        adj[v1][ grau[v1]++ ] = e_counter - 2;
        adj[v2][ grau[v2]++ ] = e_counter - 1;
    }
    void insert_from_source(int v2, int cap, int cost) {
        insert_edge(S, v2, cap, cost);
    }
    void insert_to_sink(int v1, int cap, int cost) {
        insert_edge(v1, T, cap, cost);
    }
    bool belman() {
        for(int i = 0; i < NV; i++) {
            dist[i] = inf;
            lbl[0][i] = lbl[1][i] = 0;
            pai[i] = -1;
        }
        qf[0] = 0; fila[0][qf[0]++] = S;
        pai[S] = -2; dist[S] = 0;
        for(int k = 0; k < NV; k++) {
            int fila_at = k&1;
            int fila_prox = 1 - fila_at;
            qf[fila_prox] = 0;
            for(int i = 0; i < qf[fila_at]; i++) {
                int v = fila[fila_at][i];
                lbl[fila_at][v] = 0;
                for(int j = 0; j < grau[v]; j++) {
                    edge e = edges[adj[v][j]];
                    edge ei = edges[adj[v][j] ^ 1];
                    int w = e.v;
                    ll cap = e.cap - e.flow, cost = e.cost;
                    if(ei.flow) cost = -ei.cost;
                    if(cap > 0 && dist[w] > dist[v] + cost) {
                        if(!lbl[fila_prox][w]){
                            fila[fila_prox][qf[fila_prox]++] = w;
                            lbl[fila_prox][w] = 1;
                        }
                        dist[w] = dist[v] + cost;
                        pai[w] = adj[v][j];
                    }
                }
            }
        }
        return pai[T] != -1;
    }
    
    flow mcmf() {
        flow f = (flow) { 0 , 0 };
        while(belman()) {
            ll bot = inf, cost = 0;
            for(int v = T; pai[v] >= 0; v = edges[pai[v] ^ 1].v) {
                bot = min (bot , edges[pai[v]].cap - edges[pai[v]].flow);	
            }
            for(int v = T; pai[v] >= 0; v = edges[pai[v] ^ 1].v) {
                edge &e = edges[pai[v]];
                edge &ei = edges[pai[v] ^ 1];
                if(ei.flow) { cost += bot*(-ei.cost); } 
                else { cost += bot*e.cost; }
                e.flow += bot;
                ei.flow -= bot;
            }
            f.flow += bot;
            f.cost += cost;
        }
        return f;
    }
};


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){ ___
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc; ++tid){
    
        int n,k,m;
        cin>>n>>k>>m;    
        vector<pair<int,int> > pos(k);
        memset(id_pos,-1,sizeof id_pos);
        
        int _id = 0;
        
        for(int i = 0; i< n; ++i){
            for(int j = 0; j < n; ++j){
                cin>>grid[i][j];
                
                if(valid(grid[i][j]))
                    id_pos[i][j] = _id++;
                    
                if(isupper(grid[i][j]))
                    pos[grid[i][j] - 'A'] = make_pair(i,j);
            }
        }
        
        int source = _id++;
        int sink = _id++;
        
        MCMF graph;
        graph.init(k+m);
        
        for(int i = 0; i< n; ++i){
            for(int j = 0; j < n; ++j){
                if(isupper(grid[i][j])){
                
                    memset(visited,0,sizeof visited);
                    queue<pair<pair<int,int> ,int> > Q;
                    Q.push(make_pair(make_pair(i,j),0));
                    while(!Q.empty()){
                        int x = Q.front().first.first;
                        int y = Q.front().first.second;
                        int costo = Q.front().second;
                        Q.pop();
                        if(visited[x][y])continue;
                        visited[x][y] = true;
                        
                        if(grid[x][y]=='m'){
                            graph.insert_edge(id_pos[i][j], id_pos[x][y], 1, costo);
//                            cout<<"from "<<i<<" "<<j<<" to "<<x<<" "<<y<<" with cost: "<<costo<<endl;
                        }
                        
                        for(int kk = 0; kk  < 4; ++kk){
                            int nx = x + dx[kk];
                            int ny = y + dy[kk];
                            if(nx >= 0 and nx < n and ny >= 0 and ny < n and !visited[nx][ny] and grid[nx][ny]!='#')
                                Q.push(make_pair(make_pair(nx,ny),costo +1));
                        }
                    }
                    
                }
            }
        }
        
        int tt;
        for(int i = 0; i< k; ++i){
            cin>>tt;
            graph.insert_from_source(id_pos[pos[i].first][pos[i].second], tt,0);
        }
        
        
        for(int i = 0; i< n; ++i)
            for(int j = 0; j< n; ++j)
                if(grid[i][j] == 'm')
                    graph.insert_to_sink(id_pos[i][j],1,0);
         
         
        flow f = graph.mcmf();
        printf("Case %d: %d\n",tid, f.cost);
        
        
    }

    return 0;    
}
