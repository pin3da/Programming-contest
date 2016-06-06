#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool subseq(const string &b, const string &a) {
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] == b[j])
      j++;
    i++;
  }
  return (j == b.size());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    string haystack; cin >> haystack;
    int q; cin >> q;
    while (q--) {
      string needle; cin >> needle;
      if (subseq(needle, haystack))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
