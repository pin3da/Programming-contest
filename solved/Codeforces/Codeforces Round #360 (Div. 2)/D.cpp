// http://codeforces.com/contest/688/problem/D

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

long long lcm(long long a, long long b) {
 return a / __gcd(a, b) * b;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, k;
  while (cin >> n >> k) {
    vector<long long> a(n);
    long long l = 1;
    for (auto &i : a) {
      cin >> i;
      l = lcm(l, __gcd(i, k));
    }
    puts(l == k ? "Yes" : "No");
  }
  return 0;
}
