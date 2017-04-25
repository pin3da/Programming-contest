// http://codeforces.com/contest/166/problem/C

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    int x; cin >> x;
    deque<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int less = 0, greater = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] < x)
        less++;
      else if (a[i] > x)
        greater++;

    int equals = n - less - greater;
    int ans = 0;
    while (less + equals < greater || !equals) {
      ans++;
      equals++;
    }
    while (greater + equals <= less) {
      ans++;
      equals++;
    }
    cout << ans << endl;
  }
  return 0;
}
