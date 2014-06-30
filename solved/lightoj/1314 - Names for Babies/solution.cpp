/**
 * Suffix array
 * See http://web.stanford.edu/class/cs97si/suffix-array.pdf for reference
 * */

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl

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
    return P.back();
  }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int longestCommonPrefix(int i, int j) {
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

int main() {

  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;cin>>tc;
  for (int t = 1; t <= tc; ++t) {
    string line;cin>>line;
    SuffixArray sa(line);
    vector<int> arr = sa.getSuffixArray();
    int p, q;
    cin>>p>>q;
    vector<pair<int, int> > rank(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
      //cout<<arr[i]<<" ";
      rank[i].first = arr[i];
      rank[i].second = i;
    }
    //cout<<endl;
    sort(rank.begin(), rank.end());

    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a = (i > 0) ? sa.longestCommonPrefix(rank[i].second, rank[i - 1].second) : 0;
      int b = n - rank[i].second;

      int aa = max(p, a + 1);
      int bb = min(b, q);

      if (bb >= aa) ans += (bb - aa + 1);
    }

    cout<<"Case "<<t<<": "<<ans<<endl;
  }

  return 0;
}
