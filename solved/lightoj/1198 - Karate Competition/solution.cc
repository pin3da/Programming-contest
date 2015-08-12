using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  int score = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (a[j] != -1) {
      if (a[j] > b[i]) {
        score += 2;
        a[j] = b[i] = -1;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) if (b[i] != -1) {
    for (int j = 0; j < n; ++j) if (a[j] != -1) {
      if (a[j] == b[i]) {
        score += 1;
        a[j] = b[i] = -1;
        break;
      }
    }
  }

  printf("%d\n", score);

}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
