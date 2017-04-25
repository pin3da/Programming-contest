// http://codeforces.com/contest/222/problem/D

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  long long x;
  cin >> n >> x;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a)
    cin >> i;

  for (auto &i : b)
    cin >> i;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());

  int i = 0, j = 0;

  int ans = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] + b[j] >= x) {
      ans++;
      j++;
    }
    i++;
  }
  cout << "1 " << ans << endl;
  return 0;
}
