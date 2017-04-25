// http://codeforces.com/contest/225/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool solve(int n) {
  int a, b, c, d, e, f;
  cin >> e >> a >> b;
  d = 7 - b;
  c = 7 - a;
  f = 7 - e;
  n--;
  int ok = true;
  while (n > 0) {
    e = f;
    cin >> a >> b;
    c = 7 - a;
    d = 7 - b;
    int ar[] = {a, b, c, d, e};
    vector<bool> seen(6);
    for (int i = 0; i < 5; ++i)
      seen[ar[i] - 1] = true;
    int hidden = 0, id;
    for (int i = 0; i < 6; ++i) {
      if (!seen[i]) {
        hidden++;
        id = i + 1;
      }
    }
    if (hidden > 1) ok = false;
    f = id;
    n--;
  }
  return ok;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n)
    cout << (solve(n) ? "YES" : "NO") << endl;
  return 0;
}
