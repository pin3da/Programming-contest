#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool kmp(const string &needle, const string &haystack) {
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
  for (int i = 0; i < n; ++i){
    while (seen > 0 and haystack[i] != needle[seen]) {
      seen = border[seen - 1];
    }
    if (haystack[i] == needle[seen]) seen++;

    if (seen == m) {
      return true;
      printf("Needle occurs from %d to %d\n", i - m + 1, i);
      seen = border[m - 1];
    }
  }
  return false;
}

void solve() {
  string text; cin >> text;
  int q; cin >> q;
  string pattern;
  while (q--) {
    cin >> pattern;
    bool ok = kmp(pattern, text); // .find(pattern) != string::npos;
    if (ok) cout << 'y' << endl;
    else    cout << 'n' << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
