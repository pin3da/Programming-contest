#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXN = 100000 + 100 + 11;

namespace SuffixArray {
  int t, rank[MAXN], sa[MAXN], lcp[MAXN];

  bool compare(int i, int j){
    return rank[i + t] < rank[j + t];
  }

  void build(const string &s){
    int n = s.size();
    int bc[256];
    for (int i = 0; i < 256; ++i) bc[i] = 0;
    for (int i = 0; i < n; ++i) ++bc[s[i]];
    for (int i = 1; i < 256; ++i) bc[i] += bc[i-1];
    for (int i = 0; i < n; ++i) sa[--bc[s[i]]] = i;
    for (int i = 0; i < n; ++i) rank[i] = bc[s[i]];
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
    // Remove this part if you don't need the LCP
    int size = 0, i, j;
    for(i = 0; i < n; i++) if (rank[i] > 0) {
      j = sa[rank[i] - 1];
      while(s[i + size] == s[j + size]) ++size;
      lcp[rank[i]] = size;
      if (size > 0) --size;
    }
    lcp[0] = 0;
  }
};

using namespace SuffixArray;


// RMQ.
const int MN = 100000 + 10; // Max number of elements
const int ML = 18; // ceil(log2(MN));

struct st {
  int data[MN];
  int M[MN][ML];
  int n;

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = min(M[i][j - 1], M[i + q][j - 1]);
  }
  int query(int b, int e) {
    int k = log2(e - b + 1);
    return min(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};


string line;
st rmq;

int getLcp(int a, int b, int n) {
  /*
  int ans = n;
  for (int i = a; i < b; ++i) {
    ans = min(lcp[i + 1], ans);
  }
  return ans;
  */
  return rmq.query(a + 1, b);
}

void repeated_m_times(int m) {

  int n = line.size();

  int length = 2, position = -1;
  for (int i = 0; i + m < n; ++i) {
    if (getLcp(i, i + m, n) > length) {
      position = sa[i];
      length = getLcp(i, i + m, n);
    }
  }

  if (length > 2)
    cout << line.substr(position, length) << endl;
  else
    cout << "*" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> line) {
    line.push_back('\1');
    build(line);

    for (int i = 0; i < line.size(); ++i)
      rmq.data[i] = lcp[i];

    rmq.n = line.size();
    rmq.build();

    repeated_m_times(1);
  }

  return 0;
}
