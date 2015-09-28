using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

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

  vector<int> getSuffixArray(){
    vector<int> &rank = P.back();
    vector<pair<int, int> > inv(rank.size());
    for (int i = 0; i < rank.size(); ++i)
      inv[i] = make_pair(rank[i], i);
    sort(inv.begin(), inv.end());
    vector<int> sa(rank.size());
    for (int i = 0; i < rank.size(); ++i)
      sa[i] = inv[i].second;
    return sa;
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

int get_class(const string &a, const string &b, const string &c, int id) {
  if (id < a.size()) return 0;
  id = id - a.size() - 1;
  if (id < b.size()) return 1;
  return 2;
}

void solve() {

  string a, b, c;
  cin >> a >> b >> c;
  string cur = a + "#" + b + "$" + c + "%";
  SuffixArray suf_a(cur);
  vector<int> sa = suf_a.getSuffixArray();
  vector<int> lcp(sa.size());
  lcp[0] = 0;
  for (int i = 1; i < sa.size(); ++i)
    lcp[i] = suf_a.lcp(sa[i - 1], sa[i]);

  // for (int i = 0; i < sa.size(); ++i)
  //  cout << cur.substr(sa[i]) << endl;

  int best = 0;
  for (int i = 4; i < sa.size(); ++i) {
    int c1 = get_class(a, b, c, sa[i]);
    int c2 = get_class(a, b, c, sa[i - 1]);
    int c3 = get_class(a, b, c, sa[i - 2]);
    if (c1 == c2 || c1 == c3 || c2 == c3) continue;
    best = max(best, min(lcp[i], lcp[i - 1]));
  }
  printf("%d\n", best);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
