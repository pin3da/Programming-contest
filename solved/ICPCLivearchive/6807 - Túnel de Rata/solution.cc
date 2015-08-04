using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct edge{
  int u, v, c;
  edge() {}
  edge(int a, int b, int d) : u(a), v(b), c(d) {}
  bool operator < (const edge &o) const {
    if (c == o.c) {
      if (u == o.u)
        return v > o.v;
      return u > o.v;
    }
    return c > o.c;
  }
};

const int MN = 100001;
int p[MN];

int fs(int x) {
  return (x == p[x]) ? x : p[x] = fs(p[x]);
}

void join(int x, int y) {
  p[fs(x)] = fs(y);
}

void solve() {
  int s, t;
  cin >> s >> t;
  vector<edge> all(t);
  int u, v, c;
  for (int i = 0; i < t; ++i) {
    cin >> all[i].u >> all[i].v >> all[i].c;
    all[i].u--;all[i].v--;
  }
  sort(all.begin(), all.end());
  for (int i = 0; i < s; ++i) {
    p[i] = i;
  }

  int tot = 0, mmax = 0;
  for (int i = 0; i < t; ++i) {
    u = all[i].u;
    v = all[i].v;
    c = all[i].c;
    if (fs(u) != fs(v)) {
      join(u, v);
    } else {
      tot += c;
      mmax = max(mmax, c);
    }
  }

  cout << tot << " " << mmax << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

