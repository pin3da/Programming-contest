// http://codeforces.com/contest/495/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  int a,b;
  cin >> a >> b;

  if (a < b) {
    cout << 0 << endl;
    return 0;
  }

  if (a == b) {
    cout << "infinity" << endl;
    return 0;
  }

  int t = a - b;
  vector<int> ans;
  for (int i = 1; i * i <= t; ++i)
    if (t % i == 0) {
      if (i > b) ans.push_back(i);
      if (t / i != i and t / i > b) ans.push_back(t / i);
    }

  cout << ans.size() << endl;

  return 0;
}