// http://codeforces.com/contest/659/problem/A

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, a, b;
  while (cin >> n >> a >> b) {
    a--;
    cout << ((((a + b) % n) + n) % n) + 1 << endl;
  }

  return 0;
}