#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MAXN = 30;
const int MAXE = 12345;

struct dir_eulerian {
  size_t ne;
  int N, last[MAXN],to[MAXE],next[MAXE],cur[MAXN];
  int in[MAXN],out[MAXN];
  int start,end;
  vector<int> path;

  dir_eulerian(){}

  void clear(int V_){
    N = V_; ne = 0;
    memset(last,-1,sizeof last);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
  }

  void add_edge(int u, int v) {
    to[ne] = v; next[ne] = last[u]; last[u] = ne++;
    ++out[u]; ++in[v];
    start = u;
  }

  bool check() {
    int cont = 0, aux = start;
    start = end = -1;
    for (int i = 0; i < N;++i) {
      if (in[i] == out[i]) ++cont;
      else if (out[i] == in[i] + 1) start = i;
      else if (in[i] == out[i] + 1) end = i;
      else return false;
    }

    if (cont == N) {
      start = end = aux;
      return true;
    }

    return (cont == N - 2 && start != -1 && end != -1);
  }

  bool build() {
    stack<int> s;
    s.push(start);
    memcpy(cur, last, sizeof last);
    path.clear();

    while (!s.empty()) {
      int u = s.top();

      if (cur[u] == -1) {
        path.push_back(u);
        s.pop();
      } else {
        int v = to[ cur[u] ];
        cur[u] = next[ cur[u] ];
        s.push(v);
      }
    }

    reverse(path.begin(),path.end());
    return path.size() == ne + 1;
  }
};

dir_eulerian g;
vector<string> dir[MAXN][MAXN];

void save_edge(int u, int v, string &s) {
  dir[u][v].push_back(s);
}

string get_edge(int u, int v) {
  string ans = dir[u][v].back();
  dir[u][v].pop_back();
  return ans;
}

void solve() {
  for (int i = 0; i < MAXN; ++i)
    for (int j = 0; j < MAXN; ++j)
      dir[i][j].clear();

  int n;
  cin >> n;
  g.clear(26);
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int u = a[i][0] - 'a';
    int v = a[i][a[i].size() - 1] - 'a';
    g.add_edge(u, v);
    save_edge(u, v, a[i]);
  }

  if (g.check() && g.build()) {
    cout << "Yes" << endl;
    for (size_t i = 1; i < g.path.size(); ++i) {
      if (i > 1) cout << ' ';
      cout << get_edge(g.path[i - 1], g.path[i]);
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  int tc; cin >> tc;
  int id = 1;
  while (tc--) {
    cout << "Case " << (id++) << ": ";
    solve();
  }
  return 0;
}
