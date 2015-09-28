using namespace std;
#include<bits/stdc++.h>
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


int find_w(const vector<int> &sa, const string a, const string &b) {
  if (a.substr(sa[a.size() - 1]) < b) return -1;
  int lo = 0, hi = a.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (a.substr(sa[mid]) >= b)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

void solve() {
  string a, b;
  cin >> a >> b;
  SuffixArray suffix_a(a);
  vector<int> sa = suffix_a.getSuffixArray();

  vector<int> top(a.size(), -1);

  int start = find_w(sa, a, b);
  if (start >= 0 &&  a.substr(sa[start], b.size()) == b) {
    while (start < a.size()) {
      top[sa[start]] = sa[start] + b.size() - 1;
      if (start + 1 < a.size() && suffix_a.lcp(sa[start], sa[start + 1]) < b.size())
        break;
      start++;
    }
  }

  int left = a.size();
  for (int i = a.size() - 1; i >= 0; --i) {
    if (top[i] == -1)
      top[i] = left;
    else
     left   = top[i];
  }

  int ans = 0;
  vector<int> lcp(a.size());

  lcp[0] = 0;
  for (int i = 1; i < a.size(); ++i) {
    lcp[i] = suffix_a.lcp(sa[i], sa[i - 1]);
  }


  int total = 0;
  for (int i = 0; i < a.size(); ++i) {
    int l = sa[i] + lcp[i];
    int r = top[sa[i]];
    if (l < r)
      total += r - l;
  }

  printf("%d\n", total);
  // cout << total << endl;
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
