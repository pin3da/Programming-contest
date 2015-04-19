using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    if (n - i <= i) {
      if (n - i == i)
        cout << i << " " << i << endl;
      break;
    }
    cout << i << " " << n - i << endl;
    cout << n - i << " " <<  i << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }
}


