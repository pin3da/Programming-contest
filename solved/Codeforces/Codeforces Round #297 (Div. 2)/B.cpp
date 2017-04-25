// http://codeforces.com/contest/525/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  cin >> line;
  int m, a;
  cin >> m;
  vector<int> pref(line.size(), 0);
  for (int i = 0; i < m; ++i) {
    cin >> a;
    pref[a - 1] += 1;
    if (line.size() - a + 1 < line.size())
      pref[line.size() - a + 1] -= 1;
  }

  for (int i = 1; i < line.size(); ++i) {
    pref[i] += pref[i - 1];
  }

  for (int i = 0; i < line.size(); ++i) {
    // cout << pref[i] << " ";
    if (pref[i] & 1)
      cout << line[line.size() - i - 1];
    else
      cout << line[i];
  }
  cout << endl;


  return 0;
}

