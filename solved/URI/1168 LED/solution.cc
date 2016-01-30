#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<long long> c({6, 2, 5, 5, 4, 5, 6, 3, 7, 6});
  int n;
  cin >> n;
  while (n--) {
    string line;
    cin >> line;
    long long ans = 0;
    for (auto &i : line)
      ans += c[i - '0'];
    cout << ans << " leds"<< endl;
  }
  return 0;
}
