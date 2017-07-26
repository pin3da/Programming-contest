#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long dp[25][4];

long long go(vector<int> &data, vector<int> &carry, int id, int past) {
  if (id == (int)carry.size()) {
    int ans = 0;
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < 10; ++j)
        if ((i + j + past) == data[id]) ans++;

    return ans;
  }

  if (dp[id][past] != -1) return dp[id][past];
  long long ans = 0;
  if (carry[id] == 1) {
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < 10; ++j) {
        int next = i + j + past;
        if ((next >= 10) && ((next % 10) == data[id]))
          ans += go(data, carry, id + 1, 1);
      }
  } else {
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < 10; ++j) {
        int next = i + j + past;
        if ((next < 10) && (next == data[id]))
          ans += go(data, carry, id + 1, 0);
      }
  }
  return dp[id][past] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line; cin >> line;
  vector<int> carry(line.size() - 1);
  int n = line.size() - 1;
  for (int i = 0; i < n; ++i) {
    cin >> carry[i];
  }

  vector<int> data(line.size());
  reverse(line.begin(), line.end());
  for (int i = 0; i < n + 1; ++i)
    data[i] = line[i] - '0';

  /*
  for (auto i : data) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : carry) {
    cout << i << " ";
  }
  cout << endl;
  */

  memset(dp, -1, sizeof dp);
  cout << go(data, carry, 0, 0) << endl;

  return 0;
}
