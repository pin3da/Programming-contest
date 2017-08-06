#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


const int MAXN = 111;

bool g[MAXN][MAXN], seen[MAXN];
int L, R, matchL[MAXN], matchR[MAXN];

bool assign(int i) {
    for (int j = 0; j < R; ++j) if (g[i][j] and !seen[j]) {
        seen[j] = true;
        if ( matchR[j] < 0 or assign(matchR[j]) )
            return matchL[i] = j, matchR[j] = i, true;
    }
    return false;
}

int maxBipartiteMatching() {
    for (int i = 0; i < L; ++i) matchL[i] = -1;
    for (int j = 0; j < R; ++j) matchR[j] = -1;
    int ans = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < R; ++j) seen[j] = false; // or memset
        if (assign(i)) ans++;
    }
    return ans;
}

typedef vector<pair<long long, long long>> tt;

long long m_dist(pair<long long, long long> a, pair<long long, long long> b) {
  long long x = llabs(a.first - b.first);
  long long y = llabs(a.second - b.second);
  return x + y;
}

bool test(tt &a, tt &b, long long len) {
  memset(g, 0, sizeof g);
  memset(seen, 0, sizeof seen);
  L = a.size();
  R = b.size();
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < R; j++) {
      if (m_dist(a[i], b[j]) <= len)
        g[i][j] = true;
    }
  }
  return maxBipartiteMatching() == L;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<pair<long long, long long>> a(n);
  vector<pair<long long, long long>> b(n);
  for (auto &i : a) cin >> i.first >> i.second;
  for (auto &i : b) cin >> i.first >> i.second;

  long long lo = 0, hi = 1000000000LL;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (test(a, b, mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  cout << lo << endl;
  return 0;
}
