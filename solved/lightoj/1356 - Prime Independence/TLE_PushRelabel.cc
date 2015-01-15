/**
 *  Cool, but not fast enough solution, reason:
 *
 *    V ** 3 > (V ** 2) * E
 * */
using namespace std;
#include <bits/stdc++.h>
#define D(x) cerr << #x << " = "  << (x) << endl

const int MN = 500001;
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

struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar_unlocked(); }
  void skip() { while (0 <= b && b <= 32) read(); }
  unsigned int next_u32() {
    unsigned int v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
  int next_int() {
    int v = 0; bool s = false;
    skip(); if (b == '-') { s = true; read(); }
    for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
  char next_char() { skip(); char c = b; read(); return c; }
  void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }
  bool has_next() { skip(); return b > 0; }
  bool has_next_u32() { skip(); return 48 <= b && b <= 57; }
  bool has_next_int() { skip(); return b == 45 || (48 <= b && b <= 57); }
  void skip_line() {
    for (; b != 10 && b != 13 && b >= 0; read());
    char p = b; read();
    if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
  void next_line(char *s) {
    for (; b != 10 && b != 13 && b >= 0; read()) *s++ = b; *s = 0;
    while (b == 10 || b == 13) read(); }
  void next_real_line(char *s, int &l) {
    for (l = 0; b != 10 && b != 13 && b >= 0; read()) *s++ = b, ++l;
    *s = 0; char p = b; read();
    if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
};


void solve(vector<int> &primes, vector<int> &divs, Reader &rd) {
  int n = rd.next_int();
  vector<int> seen(MN, -1);
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = rd.next_int();
    seen[nums[i]] = i;
  }

  int source = 2 * n;
  int sink   = source + 1;
  PushRelabel graph(sink + 1);
  for (int i = 0; i < n; ++i) {
    graph.AddEdge(source, i, 1);
    graph.AddEdge(n + i, sink, 1);
  }

  int last = 0;
  for (int i = 0; i < MN; ++i) {
    if (seen[i] > -1)
      last = i;
  }


  for (int i = 0; i < n; ++i) {
    int u = nums[i];
    for (int k = 0; k < primes.size(); ++k) {
      if (u * primes[k] > last) break;
      int v = u * primes[k];
      if (seen[v] != -1) {
        if (!divs[u]) {
          graph.AddEdge(i, n + seen[v], 100);
        }else
          graph.AddEdge(seen[v], n + i, 100);
      }
    }
  }

  printf("%d\n", n - graph.GetMaxFlow(source, sink));

}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  Reader rd;
  int n = rd.next_int();

  vector<int> primes;
  vector<int> sieve(MN, 1), divs(MN, 0);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < MN; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
      for (int j = i + i; j < MN; j += i)
        sieve[j] = false;
    }
  }

  for (int i = 2; i < MN; ++i) {
    int t = i;
    int ans = 0;
    for (int j = 0; primes[j] * primes[j] <= t; ++j) {
      if (t % primes[j]) continue;
      while((t % primes[j]) == 0) {
        t /= primes[j];
        ans ^= 1;
      }
    }
    if (t > 1)
      ans ^= 1;

    divs[i] = ans;
  }


  for (int i = 0; i < n; ++i) {
    printf("Case %d: ", i + 1);
    solve(primes, divs, rd);
  }
  return 0;
}
