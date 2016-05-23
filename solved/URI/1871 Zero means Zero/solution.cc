#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b && (a + b)) {
    string line = to_string(a + b);
    for (auto &i : line)
      if (i != '0')
        cout <<  i;
    cout << endl;
  }

  return 0;
}
