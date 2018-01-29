#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int valid(string &line, int i, int j) {
  if (j < i) return true;
  if (i == j) return false;
  int ans = valid(line, i + 1, j - 1)
    && ((line[i] == '(') || (line[i] == '?'))
    && ((line[j] == ')') || (line[j] == '?'));

  for (int k = i + 1; k < j; k++)
    ans |= (valid(line, i, k) && valid(line, k + 1, j));
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  string line;
  cin >> line;
  long long ans = 0;
  int n = line.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (valid(line, i, j)) {
        ans++;
        cerr << i << " " << j << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
