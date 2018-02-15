#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MN = 400000 + 100;
const int ML = 19;

struct tree {
  int g[MN];
  long long w[MN];
  int p[MN][ML];
  long long s[MN][ML];
  int great[MN];

  int cur_t;

  tree() {
    cur_t = 1;
  }

  void comp_parents(int id) {
    p[id][0] = g[id];
    s[id][0] = w[id] + w[g[id]];

    for (int j = 1; (1 << j) < MN; j++) {
      if (p[id][j - 1] != 0) {
        p[id][j] = p[p[id][j - 1]][j - 1];
        s[id][j] = s[id][j - 1] + s[p[id][j - 1]][j - 1];
      }
    }
  }

  int add_node(int p, long long x) {
    int id = ++cur_t;
    g[id] = p;
    w[id]= x;

    comp_parents(id);
    return id;
  }

  void add_node(int id, int p, long long x) {
    g[id] = p;
    w[id] = x;

    comp_parents(id);
  }

  int get_greater(int id) {
    int ini = id;
    while (g[id] != 0) {
      int to = great[id] != 0 ? great[id] : g[id];
      if (w[to] >= w[ini]) {
        return great[ini] = to;
      }
      id = to;
    }
    return 0;
  }

  int query(int id, long long sum) {
    long long acc = w[id];
    if (acc > sum) return 0;


    int ans = 1;
    for (int j = ML - 1; j >= 0; j--) {
      if (p[id][j] != 0 && s[id][j] <= sum)  {
        ans += (1 << j);
        sum -= s[id][j];
        id = p[id][j];
      }
    }

    /*
    int ans = 1;
    while (g[id] != 0 && acc + w[g[id]] <= sum) {
      id = g[id];
      acc += w[id];
      ans++;
    }*/

    return ans;
  }
};

tree t1, t2;

void solve() {
  int n; cin >> n;

  long long last = 0;
  while (n--) {
    int op;
    long long p, q;
    long long r, w;
    read(op, p, q);

    r = p ^ last;
    w = q ^ last;

    if (op == 1) {
      int id = t1.add_node(r, w);

      int id_ant = t1.get_greater(id);

      t2.add_node(id, id_ant, w);
    } else {
      long long ans = t2.query(r, w);
      last = ans;
      cout << ans << endl;
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

