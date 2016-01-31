using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int id, b;
    cin >> id >> b;
    string line;
    cin >> line;
    int ans = 0;
    for (int j = 0; j < line.size(); ++j) {
      ans *= b;
      ans += (line[j] - '0');
      ans %= b - 1;
    }
    cout << id << " " << ans << endl;
  }

  return 0;
}
