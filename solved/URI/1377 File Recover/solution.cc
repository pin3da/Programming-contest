#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXN = 100000 + 100 + 10 + 1;
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

int number_of_repeated_substrings(int n) {
  // Number of substrings that appear at least twice in the text.
  // The trick is that all 'spare' substrings that can give us
  // Lcp(i - 1, i) can be obtained by Lcp(i - 2, i - 1)
  // due to the ordered nature of our array.
  // And the overall answer is
  // Lcp(0, 1) +
  //     Sum(max[0, Lcp(i, i - 1) - Lcp(i - 2, i - 1)])
  //     for 2 <= i < n
  // File Recover
  int cnt = lcp[1];
  for (int i = 2; i < n; ++i) {
    cnt += max(0, lcp[i] - lcp[i-1]);
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line && line != "*") {
    line.push_back('\1');
    build(line);
    cout << number_of_repeated_substrings(line.size()) << endl;
  }
  return 0;
}
