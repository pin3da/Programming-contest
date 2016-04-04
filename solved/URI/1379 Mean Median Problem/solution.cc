#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b && (a + b)) {
    cout << a - (b - a) << endl;
  }
  return 0;
}
