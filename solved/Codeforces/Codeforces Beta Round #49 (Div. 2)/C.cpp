// http://codeforces.com/contest/53/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(int n) {
  bool first = true;
  if ((n & 1)) {
    cout << n;
    n--;
    first = false;
  }

  int s = 1;
  while (s < n) {
    if (!first) cout << " ";
    cout << s << " " << n;
    first = false;
    s++; n--;
  }
  cout << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) solve(n);
  return 0;
}
