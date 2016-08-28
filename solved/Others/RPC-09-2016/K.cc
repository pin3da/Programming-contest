#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct pt {
  int x, y, id;
  bool operator < (const pt & o) const {
    if (y == o.y) return x < o.x;
    return y < o.y;
  }
};


bool cmpx(const pt &a, const pt &b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

bool cmpy(const pt &a,const pt &b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y < b.y;
}

void solve(int n) {
  vector<pt> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }

  vector<pt> ori = a;
  sort(a.begin(), a.end(), cmpx);

  map<int, vector<pt> > e;
  for (int i = 0; i < a.size(); ++i) {
    e[a[i].x].push_back(a[i]);
  }

  vector<vector<int> > g(a.size());
  for (map<int, vector<pt> >::iterator it = e.begin(); it != e.end(); it++) {
    assert(!(it-> second.size() & 1));
    for (int i = 0; i  + 1 < it-> second.size(); i += 2) {
      int u = it-> second[i].id;
      int v = it-> second[i + 1].id;
      g[u].push_back(v);
      g[v].push_back(u);
      // cout << "from "  << u << " to " << v << endl;
    }
  }

  // cout << endl;

  sort(a.begin(), a.end(), cmpy);

  e.clear();
  for (int i = 0; i < a.size(); ++i) {
    e[a[i].y].push_back(a[i]);
  }

  for (map<int, vector<pt> >::iterator it = e.begin(); it != e.end(); it++) {
    assert(!(it->second.size() & 1));
    for (int i = 0; i  + 1 < it-> second.size(); i += 2) {
      int u = it-> second[i].id;
      int v = it-> second[i + 1].id;
      g[u].push_back(v);
      g[v].push_back(u);
      // cout << "from "  << u << " to " << v << endl;
    }
  }

  int cur = min_element(ori.begin(), ori.end())-> id;
  set<int> seen;
  int total = 0;
  while (true) {
    seen.insert(cur);
    cout << " " << cur + 1;
    int toid = -1;
    for (int i = 0; i < g[cur].size() && toid == -1; ++i) {
      pt mio = ori[cur];
      pt other = ori[g[cur][i]];
      if (seen.count(other.id)) continue;
      if (mio.y == other.y && other.x > mio.x) {
        toid = i;
      }
    }


    for (int i = 0; i < g[cur].size() && toid == -1; ++i) {
      pt mio = ori[cur];
      pt other = ori[g[cur][i]];
      if (seen.count(other.id)) continue;
      if (mio.x == other.x && other.y > mio.y) {
        toid = i;
      }
    }

    for (int i = 0; i < g[cur].size() && toid == -1; ++i) {
      pt mio = ori[cur];
      pt other = ori[g[cur][i]];
      if (seen.count(other.id)) continue;
      if (mio.y == other.y && other.x < mio.x) {
        toid = i;
      }
    }

    for (int i = 0; i < g[cur].size() && toid == -1; ++i) {
      pt mio = ori[cur];
      pt other = ori[g[cur][i]];
      if (seen.count(other.id)) continue;
      if (mio.x == other.x && other.y < mio.y) {
        toid = i;
      }
    }
    total++;
    if (toid == -1) break;
    cur = g[cur][toid];
    // debug(cur);
  }
  assert(total == n);
  cout << endl;

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  int tid = 1;
  while (cin >> n && n) {
    cout << "Polygon #" << (tid++) << ":";
    solve(n);
  }
  return 0;
}
