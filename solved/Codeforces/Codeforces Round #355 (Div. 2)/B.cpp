// http://codeforces.com/contest/677/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, h, k;
  while (cin >> n >> h >> k) {
    vector<long long> a(n);
    for (auto &i : a) cin >> i;

    long long rem = 0;
    long long ans = 0;
    for (auto &i : a) {
      if (rem + i > h) {
        ans += (rem + k - 1) / k;
        ans += i / k;
        rem = i % k;
      } else {
        long long t = rem + i;
        ans += t / k;
        rem = t % k;
      }
    }
    ans += (rem + k - 1) / k;
    cout << ans << endl;
  }
  return 0;
}
