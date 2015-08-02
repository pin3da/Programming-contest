using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while ( cin >> line && line != "*") {
    line = "a" + line + "a";
    vector<int> d(line.size(), 0);
    for (int i = 1; i < line.size(); ++i) {
      d[i] = (line[i] - line[i - 1]);
      if (d[i] < 0) d[i] += 26;
    }
    sort(d.begin(), d.end());
    int ans = 0;
    int i = 0, j = d.size() - 1, k;
    while (i < j) {
      while ( i < j && d[i] == 0) i++;
      while ( i < j && d[j] == 0) j--;
      k = d[i];
      if (26 - d[j] < k)
        k = 26 - d[j];
      d[i] = d[i] - k;
      d[j] = (d[j] + k) % 26;
      ans += k;
    }
    if (j == i)
      ans += d[i];
    cout << ans << endl;
  }
  return 0;
}
