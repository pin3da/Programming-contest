#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  if (n == 2) {
    cout << "2 1" << endl;
    return;
  }

  vector<int> a(n);
  a[0] = 3;
  a[1] = 1;
  a[2] = 2;

  for (int i = 3; i < n; ++i) {
    if (i & 1) {
      a[i] = a[i - 1];
      a[i - 1] = i + 1;
    } else {
      a[i] = a[i - 2];
      a[i - 2] = i + 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) solve(n);
  return 0;
}
