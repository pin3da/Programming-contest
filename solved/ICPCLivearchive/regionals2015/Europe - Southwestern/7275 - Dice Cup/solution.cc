#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  int first = true;
  while (cin >> n >> m) {
    vector<int> frec(n + m + 1);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        frec[i + j]++;

    if (!first)
      cout << endl;
    first = false;

    int best = *max_element(frec.begin(), frec.end());
    for (int i = 0; i < frec.size(); ++i)
      if (frec[i] == best)
        cout << i << endl;
  }
  return 0;
}
