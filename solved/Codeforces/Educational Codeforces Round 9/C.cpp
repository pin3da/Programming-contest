// http://codeforces.com/contest/632/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<string> a(n);
    for (auto &i : a)
      cin >> i;
    sort(a.begin(), a.end(), [] (string x, string y) {
      return x + y < y + x;
    });

    for (auto &i : a)
      cout << i;
    cout << endl;
  }
  return 0;
}
