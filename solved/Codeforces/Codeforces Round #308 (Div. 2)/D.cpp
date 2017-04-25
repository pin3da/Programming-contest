// http://codeforces.com/contest/552/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<int, int> > p(n);
  map<pair<int, int>, int> co;
  long long total = n * (n - 1) * (n - 2);
  for (int i = 0; i < n; ++i)
    cin >> p[i].first >> p[i].second;

  for (int i = 0; i < n; ++i) {
    co.clear();
    for (int j = 0; j < n; ++j)
      if (i != j) {
        pair<int, int> other(p[i].second - p[j].second, p[i].first - p[j].first);
        int g = __gcd(other.second, other.first);
        other.first /= g;
        other.second /= g;
        co[other]++;
      }

    for (auto &it : co) {
      long long t = it.second;
      total -= t * (t - 1);
    }
  }
  cout << total / 6 << endl;
  return 0;
}
