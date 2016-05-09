#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int a[] = {100, 50, 20, 10, 5, 2, 1};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    cout << n << endl;
    for (int i = 0; i < 7; ++i) {
      cout << n / a[i] << " nota(s) de R$ " << a[i] << ",00" << endl;
      n %= a[i];
    }
  }
  return 0;
}
