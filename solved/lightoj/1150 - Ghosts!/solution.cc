using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 55


/**
 * prewritten code of Push Relabel Altorithm
 * by http://www.stanford.edu/~liszt90/acm/notebook.html
 * */
typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
        Gap(dist[v]);
      else
        Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

/**
 * End of Push relabel.
 * */



int n, _H,_G;
char g[MN][MN];
int idg[MN][MN] , idh[MN][MN], visited[MN][MN];
int c[MN][MN];

struct P{
  int x, y,  z;
  P(){}
  P(int a, int b, int c): x(a), y(b), z(c){}
};

int dx[] = { 0, -1, 0 ,1};
int dy[] = { 1, 0, -1, 0};


int check(int m, int s){

  PushRelabel graph(s*2 + 2);

  int source = 2*s;
  int sink = 2*s +1;
  for(int i = 0; i < s; ++i){
    graph.AddEdge(source,i,1);
    graph.AddEdge(i+s,sink,1);
    for(int j = 0; j < s; ++j){
      if(c[i][j] <= m){
        graph.AddEdge(i,s+j,1);
      }
    }
  }

  return graph.GetMaxFlow(source, sink) == _H;



}

void solve(){
  cin>>n;

  memset(idg, -1, sizeof idg);
  memset(idh, -1, sizeof idh);

  _G = 0;
  _H = 0;

  for(int i = 0; i< n; ++i){
    for(int j = 0; j < n; ++j ){
      cin>>g[i][j];
      if(g[i][j] == 'G') idg[i][j] = _G++;
      if(g[i][j] == 'H') idh[i][j] = _H++;
    }
  }

  int s = _G;

  for(int i = 0 ; i < s; ++i)
    for(int j = 0; j < s; ++j) c[i][j] = 666;


  int top = 0;
  for(int i = 0; i< n; ++i){
    for(int j = 0; j < n; ++j){
      if(g[i][j] == 'G'){
        int from = idg[i][j];
        memset(visited, 0, sizeof visited);
        queue<P> q;
        q.push(P(i,j,0));
        while(!q.empty()){
          int x = q.front().x;
          int y = q.front().y;
          int dist = q.front().z;q.pop();
          if(visited[x][y]) continue;
          visited[x][y] = 1;
          if(g[x][y] == 'H'){
            c[from][idh[x][y]] = dist*2 + 2;
            top = max(top, dist*2 + 2);
          }

          for(int k = 0; k < 4; ++k ){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 and nx < n and ny >=0 and ny < n and g[nx][ny] != '#'){
              q.push(P(nx,ny,dist + 1));
            }
          }
        }
      }
    }
  }

  int lo = 0,hi = top;
  while(lo < hi){
    int mid = (lo + hi)>>1;
    if(lo + 1 == hi){
      int a = check(lo,s);
      int b = check(hi,s);
      if(a) lo = lo; // lol XD.
      else if(b) lo = hi;
      else lo = -1;
      break;
    }
    if(check(mid,s))
      hi = mid;
    else
      lo = mid;

  }

  if(lo == -1)
    cout<<"Vuter Dol Kupokat"<<endl;
  else
    cout<<lo<<endl;



}

int main(){ ___
  int tc;cin>>tc;
  for(int i = 0; i < tc; ++i){
    cout<<"Case " <<(i+1)<<": ";solve();
  }
  return 0;
}
