#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int n;
  cin >> n;
  vector<int> deg(n);
  vector<int> to(n);
  for (int i = 0; i < n; i++) {
    int t; cin >> t; t--;
    to[i] = t;
    deg[t]++;
  }

  deque<int> s;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) s.push_back(i);
  }

  vector<pair<int, int>> ans;
  while (!s.empty()) {
    int cur = s.front(); s.pop_front();
    int nxt = to[cur];
    deg[nxt]--;
    if (deg[nxt] == 0) {
      ans.emplace_back(cur, nxt);
      s.push_back(nxt);
    }
  }

  set<int> cycle;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      cycle.insert(i);
    }
  }

  int start = 0;

  vector<int> solved(n);

  for (int i = 0; i < n; i++) {
    if (!solved[to[i]] && cycle.count(to[i]) && cycle.count(i) == 0) {
      start = i;

      set<int> seen;
      int cur = to[start];
      seen.insert(cur);
      ans.emplace_back(start, to[start]);
      while (seen.count(to[cur]) == 0) {
        solved[to[cur]] = true;
        solved[cur] = true;
        seen.insert(to[cur]);
        ans.emplace_back(cur, to[cur]);
        cur = to[cur];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (cycle.count(i) && !solved[i]) {
      debug(i);
      start = i;

      set<int> seen;
      int cur = to[start];
      seen.insert(cur);
      ans.emplace_back(start, to[start]);
      while (seen.count(to[cur]) == 0) {
        solved[to[cur]] = true;
        solved[cur] = true;
        seen.insert(to[cur]);
        ans.emplace_back(cur, to[cur]);
        cur = to[cur];
      }

      ans.pop_back();
    }
  }


  reverse(ans.begin(), ans.end());

  for (auto it : ans) {
    cout << it.first + 1 << " " << it.second + 1 << endl;
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

