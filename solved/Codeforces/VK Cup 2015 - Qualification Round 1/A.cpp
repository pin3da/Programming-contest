// http://codeforces.com/contest/522/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const string start = "polycarp";

void t(string &s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void solve(int n) {
  unordered_map<string, vector<string>> g;
  string u, to, v;
  for (int i = 0; i < n; ++i) {
    cin >> u >> to >> v;
    t(u);t(v);
    g[v].push_back(u);
  }
  unordered_map<string, int> dist(n);
  vector<string> q(200 * 200);
  int head = 0, tail = 0;
  dist[start] = 1;
  q[head++] = start;
  while (tail < head) {
    string &cur = q[tail++];
    vector<string> &ne = g[cur];
    for (auto &it : ne) {
      if (dist.count(it) == 0) {
        q[head++] = it;
        dist[it] = dist[cur] + 1;
      }
    }
  }
  int best = 0;
  for (auto &it : dist)
    best = max(it.second, best);

  cout << best << endl;
  // cout << max_element(dist.begin(), dist.end())-> second << endl;
}

int main() {
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
