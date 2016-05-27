#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b)
    cout << llabs(a - b) << endl;

  return 0;
}
