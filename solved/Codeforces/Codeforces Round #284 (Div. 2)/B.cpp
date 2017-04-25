// http://codeforces.com/contest/499/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  map<string, string> cod;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cod[a] = a;
    if (b.size() < a.size())
      cod[a] = b;
  }

  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i) cout << " ";
    cout << cod[a];
  }

  cout << endl;

  return 0;
}
