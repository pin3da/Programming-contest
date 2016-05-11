#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    reverse(line.begin(), line.end());
    cout << line << endl;
  }

  return 0;
}
