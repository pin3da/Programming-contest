#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int h, w;
  while (cin >> h >> w && (w + h)) {
    vector<int> a(w);
    long long ans = 0;
    for (int i = 0; i < w; ++i) {
      cin >> a[i];
      if (i) {
        if (a[i - 1] > a[i]) {
          ans += a[i - 1] - a[i];
        }
      } else {
        ans += h - a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}

