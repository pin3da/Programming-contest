#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> a(n - 1), b(n - 1);
  for (auto &it : a) {
    cin >> it.first >> it.second;
    if (it.first > it.second) swap(it.first, it.second);
  }
  for (auto &it : b) {
    cin >> it.first >> it.second;
    if (it.first > it.second) swap(it.first, it.second);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long ans = 0;
  int i = 0, j = 0;
  while (i < (n - 1) && j < (n - 1)) {
    if (a[i] == b[j]) {
      ans++;
      i++;
      j++;
    } else if (a[i] < b[j]) {
      i++;
    } else {
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
