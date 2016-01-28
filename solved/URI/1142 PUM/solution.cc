#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  int x = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << x << " ";
      x++;
    }
    cout << "PUM" << endl;
    x++;
  }
  return 0;
}
