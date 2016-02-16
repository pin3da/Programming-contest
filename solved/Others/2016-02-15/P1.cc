#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
const int mod = 26;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string line;
    cin >> line;
    int t;
    cin >> t;
    t = (mod - t) % mod;
    for (auto &i : line) {
      i = 'A' + ((i - 'A') + t) % mod;
    }
    cout << line << endl;
  }
  return 0;
}
