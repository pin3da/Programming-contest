#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve() {
  string line;
  int k = 0;
  cin >> line;
  while (line.back() == '!') {
    k++;
    line.pop_back();
  }
  int n = atoi(line.c_str());
  long long ans = n;
  for (long long i = 1; n - k * i > 0; ++i) {
    ans *= (n - k * i);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--)
    solve();
  return 0;
}
