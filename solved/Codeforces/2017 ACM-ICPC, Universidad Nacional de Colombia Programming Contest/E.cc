#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

// Reports all occurrences of 'needle' in 'haystack'.
int kmp(const string &needle, const string &haystack) {
  // Precompute border function
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;
  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]]) {
       border[i] = border[border[i] - 1];
    }
    if (needle[i] == needle[border[i]]) border[i]++;
  }

  // Now the actual matching
  int n = haystack.size();
  int seen = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i){
    while (seen > 0 and haystack[i] != needle[seen]) {
      seen = border[seen - 1];
    }
    if (haystack[i] == needle[seen]) seen++;

    if (seen == m) {
      // printf("Needle occurs from %d to %d\n", i - m + 1, i);
      ans++;
      seen = border[m - 1];
    }
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string a, b;
  getline(cin, a);
  getline(cin, b);
  int n;
  string buff;
  getline(cin, buff);
  n = stoi(buff);

  string test = "a";
  test[0] = b[0];
  int possible = kmp(test, a) >= n;

  if (possible) {
    if (kmp(b, a) >= n) {
      cout << b << endl;
      return 0;
    }
    int lo = 1, hi = b.size();
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      test = b.substr(0, mid);
      if (kmp(test, a) >= n) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << b.substr(0, lo) << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
