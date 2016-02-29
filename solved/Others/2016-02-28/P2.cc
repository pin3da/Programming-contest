#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end(), [](int x, int y) {
    if ((x & 1) != (y & 1)) {
      return (x & 1) < (y & 1);
    } else {
      if (x & 1)
        return x > y;
      return x < y;
    }
  });

  for (auto &i : a)
    cout << i << endl;

  return 0;
}
