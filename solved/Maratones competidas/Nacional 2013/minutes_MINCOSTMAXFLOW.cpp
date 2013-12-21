using namespace std;
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define MAXNODES 250
 
typedef int L;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
 
struct Edge {
    int to;
    int cap;
    int flow;
    int cost;
    
    Edge()
    {
                flow = 0;
        }
    
    Edge(int t) {
        to = t;
                flow = 0;
    }
};
    
struct Entry{
    int node;
    int cost;
    
    Entry(int n, int c) : node(n), cost(c){}
 
    bool operator < (const Entry &o) const {
        return cost > o.cost;
    }
};    
 
 
const L INF = numeric_limits<L>::max() / 4;
 
struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

 
int dist(pair<int,int> a , pair<int,int> b){
    return fabs(a.first-b.first) + fabs(a.second-b.second);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,r;
    while(cin>>n>>r){
        vector<pair<int,int> > rest(n),deli(r);
        int a,b;
        for(int i = 0; i < n; ++i){
            cin>>a>>b;
            rest[i] =  make_pair(a,b);
        }
        for(int i = 0; i < r; ++i){
            cin>>a>>b;
            deli[i] =  make_pair(a,b);
        }
            
        MinCostMaxFlow graph(n+r+2);
        
        for(int i = 0; i< n; ++i)
            for(int j = 0; j< r; ++j)
                graph.AddEdge(i+1,j+n+1,1,dist(rest[i],deli[j]));
                
                
        for(int i = 0; i< n; ++i)
            graph.AddEdge(0,i+1,1,0);
        
        for(int i = 0; i< r; ++i)
            graph.AddEdge(n+i+1,n+r+1,1,0);
            
        cout<<graph.GetMaxFlow(0,n+r+1).second<<endl;
        
    }

    return 0;
}
