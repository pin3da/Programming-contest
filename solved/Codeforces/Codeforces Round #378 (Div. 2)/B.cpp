// http://codeforces.com/contest/733/problem/B

#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl


const int MN = 1e5 + 100;

int l[MN], r[MN];


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  long long tl = 0, tr = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    tl += l[i]; tr += r[i];
  }

  long long best = llabs(tl - tr);
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    tl -= l[i]; tr -= r[i];
    swap(l[i], r[i]);
    tl += l[i]; tr += r[i];
    if (best < (llabs(tl - tr))) {
      ans = i;
      best = llabs(tl - tr);
    }
    tl -= l[i]; tr -= r[i];
    swap(l[i], r[i]);
    tl += l[i]; tr += r[i];
  }


  cout << ans + 1<< endl;
  return 0;
}
