// http://codeforces.com/contest/725/problem/A

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  string line;
  while (cin >> n >> line) {
    int left = 0;
    for (int i = 0; i < n; ++i) {
      if (line[i] == '>') break;
      left++;
    }
    for (int i = n - 1; i >= 0; --i) {
      if (line[i] == '<') break;
      left++;
    }
    cout << left << endl;
  }

  return 0;
}
