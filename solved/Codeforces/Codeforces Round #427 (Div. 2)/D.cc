#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 5001;

struct entry{
  int a, b, p;
  entry(){}
  entry(int x, int y, int z): a(x), b(y), p(z){}
  bool operator < (const entry &o) const {
    return (a == o.a) ? (b == o.b) ? ( p < o.p) : (b < o.b) : (a < o.a);
  }
};

struct SuffixArray{
  const int N;
  string s;
  vector<vector<int> > P;
  vector<entry> M;

  SuffixArray(const string &s) : N(s.length()) , s(s), P(1, vector<int> (N, 0)), M(N) {
    for (int i = 0; i < N; ++i)
      P[0][i] = (int) s[i];

    for (int skip = 1, level = 1; skip < N; skip *= 2, level++) {
      P.push_back(vector<int>(N, 0));
      for (int i = 0 ; i < N; ++i) {
        int next = ((i + skip) < N) ? P[level - 1][i + skip] : -10000;
        M[i] = entry(P[level - 1][i], next, i);
      }
      sort(M.begin(), M.end());
      for (int i = 0; i < N; ++i)
        P[level][M[i].p] =  (i > 0 and M[i].a == M[i - 1].a and M[i].b == M[i - 1].b) ? P[level][M[i - 1].p] : i;
    }
  }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int lcp(int i, int j) {
    int len = 0;
    if (i == j) return N - i;
    for (int k = P.size() - 1; k >= 0 && i < N && j < N; --k) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
};


int ans[2][MN][MN];

bool is_pal(string &s, int i, int j) {
  if (j <= i) return true;
  if (ans[0][i][j] != -1) return ans[0][i][j];
  return s[i] == s[j] && is_pal(s, i + 1, j - 1);
}

bool same(string &s, int i, int j, int len) {
  for (int k = 0; k < len; ++k)
    if (s[i + k] != s[j + k]) return false;
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line; cin >> line;
  int n = line.size();

  int tmp = 0;
  memset(ans[0], -1, sizeof ans[0]);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (is_pal(line, i, j)) tmp++;
    }
  }
  cout << tmp << " ";

  int cur = 1;

  SuffixArray suffix_array(line);

  for (int k = 1; k < n; ++k) {
    int last = cur ^ 1;
    memset(ans[cur], 0, sizeof ans[cur]);
    int min_len = 1 << (k - 1);
    int max_len = (n + 1) / 2;
    if (min_len > max_len) cout << 0 << " ";
    else {
      for (int i = 0; i < n; i++) {
        for (int l = min_len; l <= max_len; ++l) {
          int j = i + l - 1;
          int len = (j - i + 1) >> 1;
          if (len == 0) continue;
          if (suffix_array.lcp(i, j - len +1) >= len && ans[last][i][i + len - 1]) {
            ans[cur][i][j] = true;
            tmp++;
          }
        }
      }
      cur ^= 1;
      cout << tmp << " ";
    }
  }
  cout << endl;
  return 0;
}
