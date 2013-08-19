using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 101
#define MH 30

int height[MP][MP];
int idsEntrada[MP][MP][MH];
int idsSalida[MP][MP][MH];

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!dad[e.to] && e.cap - e.flow > 0) {
      dad[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

struct pos{
    int x,y;
    pos(){}
};

int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int main(){ __
    
    int n,k,h;
    while(cin>>n>>k>>h and n+k+h){
        for(int i = 0; i< n; ++i)
            for(int j = 0; j< n; ++j)
                cin>>height[i][j];
                
        vector<pos> cows(k);
        for(int i = 0; i< k; ++i)
            cin>>cows[i].x>>cows[i].y;
            
        vector<int> level(h);
        for(int i = 0; i< h; ++i)
            cin>>level[i];
           
        
        int _id = 0;
        int source = _id++;
        int sink = _id++;
        for(int i = 0; i <= h; i++){
            int altura = i == 0 ? -1 : level[i - 1];
            for(int j = 0; j < n; j++){
                for(int l = 0; l < n; l++){
                    if(height[j][l] <= altura)
                        idsEntrada[j][l][i] = idsSalida[j][l][i] = -1;
                    else{
                        idsEntrada[j][l][i] = _id++;
                        idsSalida[j][l][i] = _id++;
                    }
                }
            }
        }
        
        Dinic graph(_id);
        
        
        for(int i = 0; i <= h; i++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < n; l++){
                    if(i == h){
                        if(idsSalida[j][l][i] == -1) continue;
                        graph.AddEdge(idsSalida[j][l][i], sink, 1);
                    }else{
                        for(int p = 0; p < 5; ++p){
                            int iN = j + dx[p];
                            int jN = l + dy[p];
                            if(iN >= 0 && iN < n && jN >= 0 && jN < n){
                                if(idsSalida[j][l][i] == -1 or idsEntrada[iN][jN][i + 1] == -1) continue;
                                graph.AddEdge(idsSalida[j][l][i], idsEntrada[iN][jN][i + 1], 1);
                            }
                        }
                    }
                    if(idsEntrada[j][l][i] == -1 or idsSalida[j][l][i] == -1) continue;
                    graph.AddEdge(idsEntrada[j][l][i], idsSalida[j][l][i], 1);
                }
            }
        }
        
        for(int i = 0; i < k; ++i)
            graph.AddEdge(source, idsEntrada[cows[i].x][cows[i].y][0], 1);
                    
        cout<<graph.GetMaxFlow(source,sink)<<endl;
        
        
    }

}

