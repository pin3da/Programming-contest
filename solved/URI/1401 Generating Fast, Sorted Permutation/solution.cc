#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  string line;
  cin >> n;
  for (int t = 0; t < n; ++t) {
    cin >> line;
    sort(line.begin(), line.end());
    do {
      cout << line << endl;
    } while (next_permutation(line.begin(), line.end()));
    cout << endl;
  }

  return 0;
}
