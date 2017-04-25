// http://codeforces.com/contest/632/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, p;
  while (cin >> n >> p) {
    vector<string> a(n);
    for (auto &i : a)
      cin >> i;
    reverse(a.begin(), a.end());

    long long money = 0;
    if (a[0] == "halfplus")
      money = (p >> 1);
    else
      money = p;

    long long apples = 1;
    for (int i = 1; i < n; ++i) {
      apples = apples << 1;
      if (a[i] == "halfplus")
        apples++;
      money += (apples >> 1) * p;
      if (apples & 1)
        money += p >> 1;
    }
    cout << money << endl;
  }
  return 0;
}
