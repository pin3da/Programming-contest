// http://codeforces.com/contest/614/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
long long inf = 1000000000000000000LL;


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long r, l, k;
  while (cin >> l >> r >> k)  {
    long long cur = 1;
    int seen = 0;
    while (cur <= r) {
      if (cur >= l) {
        cout << cur << ' ';
        seen = true;
      }
      if (r / k < cur) break;
      cur *= k;
    }
    if (!seen)
      cout << - 1 ;
    cout << endl;
  }
  return 0;
}
