#include <bits/stdc++.h>

using namespace std;

#define debug2(msg, x) // cerr << " -- " << msg << " -- " << #x " = " << (x) << endl
#define debug(x) // cerr << #x " = " << (x) << endl


const int MAXN = 200000 + 10000;

long long gauss(long long x) {
  return (x * (x + 1)) >> 1;
}

namespace suffix_array {
  int t, rank[MAXN], sa[MAXN], lcp[MAXN];
  int n, next[MAXN];
  string original;

  bool compare(int i, int j) {
    return rank[i + t] < rank[j + t];
  }

  void build(string s) {
    s = s + '\1';
    original = s;
    n = s.size();
    int bc[256];
    for (int i = 0; i < 256; ++i) bc[i] = 0;
    for (int i = 0; i < n; ++i) ++bc[int(s[i])];
    for (int i = 1; i < 256; ++i) bc[i] += bc[i-1];
    for (int i = 0; i < n; ++i) sa[--bc[int(s[i])]] = i;
    for (int i = 0; i < n; ++i) rank[i] = bc[int(s[i])];
    for (t = 1; t < n; t <<= 1){
      for (int i = 0, j = 1; j < n; i = j++){
        while (j < n && rank[sa[j]] == rank[sa[i]]) j++;
        if (j - i == 1) continue;
        int *start = sa + i, *end = sa + j;
        sort(start, end, compare);
        int first = rank[*start + t], num = i, k;
        for(; start < end; rank[*start++] = num){
          k = rank[*start + t];
          if (k != first and (i > first or k >= j))
            first = k, num = start - sa;
        }
      }
    }

    int size = 0, i, j;
    for(i = 0; i < n; i++) if (rank[i] > 0) {
      j = sa[rank[i] - 1];
      while(s[i + size] == s[j + size]) ++size;
      lcp[rank[i]] = size;
      if (size > 0) --size;
    }
    lcp[0] = lcp[n] = 0;

    next[n] = n + 1;
    for (int i = n; i > 0; i--) {
      if (lcp[i] == 0)
        next[i - 1] = i;
      else
        next[i - 1] = next[i];
    }
  }

  int get_by_len(int i, int len) { // get the more distant j such that lcp(i, i + 1, ..., j) >= len
    int cur = MAXN;
    for (int j = i + 1; j <= n; j++) {
      cur = min(lcp[j], MAXN);
      if (cur < len) return j;
    }
    return n;
  }

  char kth_in_all_substr(long long k) {
    debug2("query", k);
    vector<int> start(n);
    for (int i = 1; i < n; i++) {
      debug(i);
      debug(k);

      debug(start[i]);
      int max_len = n - sa[i] - 1;
      for (int len = start[i] + 1; len <= max_len; len++) {
        int j = get_by_len(i, len);
        debug(j);

        for (int w = i + 1; w < j; w++)
          start[w]++;

        long long frec = j - i;
        long long total = frec * len;
        if (total > k) {
          k %= len;
          return original[sa[i] + k];
        } else {
          k -= total;
        }
      }

    }
    assert(false);
    return '\1';
  }
};


void solve() {
  string s; cin >> s;

  suffix_array::build(s);

  long long g = 0;
  int q; cin >> q;
  while (q--) {
    long long p, m; cin >> p >> m;
    long long k = ((g % m) * (p % m)) % m;
    char ans = suffix_array::kth_in_all_substr(k);
    cout << ans << endl;
    g += ans;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  solve();
  return 0;
}
