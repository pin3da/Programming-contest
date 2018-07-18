#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


struct Dsu {
  vector<int> p, s;

  Dsu(int n) {
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

  int Join(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return 0;
    p[px] = py;
    s[py] += s[px];
    return 1;
  }

  int Size(int x) {
    return s[Find(x)];
  }
};


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string line;
  cin >> line;
  int n = line.size();
  // debug(n);

  Dsu dsu(n + 1);

  for (int i = 2; i <= n; i++) {
    for (int j = i + i; j <= n; j += i)
      dsu.Join(i, j);
  }

  vector<pair<int, char>> frec(30);
  for (char c = 'a'; c <= 'z'; c++) frec[c - 'a'].second = c;

  for (auto c : line)
    frec[c - 'a'].first++;

  set<pair<int, char>> f;
  for (auto it : frec) {
    f.insert(it);
  }

  vector<pair<int, int>> req;
  set<int> roots;
  for (int i = 1; i <= n; i++) {
    roots.insert(dsu.Find(i));
  }

  for (auto r : roots) {
    req.emplace_back(dsu.Size(r), r);
   // debug(req.back().first, req.back().second);
  }

  sort(req.rbegin(), req.rend());

  int ok = true;
  string ans = line;
  for (auto it : req) {
    if (f.size() == 0) {
      ok = false;
      break;
    }
    auto tt = f.end();
    tt--;
    auto tmp = *(tt);
    f.erase(tt);

   // debug(tmp.first, it.first);

    if (tmp.first < it.first) {
      ok = false;
      break;
    } else {
      tmp.first -= it.first;
     // debug(tmp.first);
      for (int i = 1; i <= n; i++) {
        if (dsu.Find(i) == it.second) ans[i - 1] = tmp.second;
      }
      if (tmp.first) {
        f.insert(tmp);
      }
    }
  }

  if (ok) {
    cout << "YES" << endl;
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
