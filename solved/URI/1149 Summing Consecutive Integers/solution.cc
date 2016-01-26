#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, n;
  cin >> a;
  while (cin >> n && n <= 0);
  long long total = 0;
  while (--n >= 0) {
    total += a + n;
  }
  cout << total << endl;
  return 0;
}
