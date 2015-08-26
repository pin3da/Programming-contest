using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

void solve() {
  string line;
  cin >> line;

  int carry = 1;
  for (int i = line.size() - 1; i >= 0 && carry; --i) {
    if (line[i] + carry <= '9') {
      line[i]++;
      carry = 0;
    } else {
      line[i] = '0';
    }
  }

  if (carry)
    line = "1" + line;

  carry = 0;
  const int n = line.size() - 1;
  vector<int> pending(line.size());
  for (int i = 0; i < line.size(); ++i) {
    if (carry && line[n - i] < '9') {
      line[n - i]++;
      carry = 0;
    } else if (carry) {
      line[n - i] = '0';
    }

    if (i <= n - i) {
      if (line[i] > line[n - i]) {
        line[n - i] = line[i];
      } else if (line[i] < line[n - i]) {
        carry  = true;
      }
    } else {
      line[i] = line[n - i];
    }
  }
  // cout << line << endl;
  puts(line.c_str());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    // cout << "Case " << i + 1 << ": ";
    solve();
  }
  return 0;
}
