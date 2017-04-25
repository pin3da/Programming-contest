// http://codeforces.com/contest/567/problem/B

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    char c; int p;
    set<int> seen;
    set<int> start;
    vector<char> ic(n);
    vector<int> ip(n);
    for (int i = 0; i < n; ++i) {
      cin >> c >> p;
      if (c == '-' && !seen.count(p))
        start.insert(p);
      seen.insert(p);
      ic[i] = c;
      ip[i] = p;
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
      char c = ic[i];
      int  p = ip[i];
      best = max<int>(best, start.size());
      if (c == '-')
        start.erase(p);
      else
        start.insert(p);
    }
    best = max<int>(best, start.size());
    cout << best << endl;
  }
  return 0;
}
