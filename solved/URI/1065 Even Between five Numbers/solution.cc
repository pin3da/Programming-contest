#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> n;
    ans += abs(n) & 1;
  }
  cout << 5 - ans << " valores pares" << endl;
  return 0;
}
