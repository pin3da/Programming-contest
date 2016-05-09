#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    for (int i = 2; i <= n; i += 2)
      cout << i << "^2 = " << i * i << endl;
  }
  return 0;
}
