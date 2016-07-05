#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long line[100];

long long op[] = {1, 10, 100, 1000, 10000};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    long long real = 0, best = 0;
    for (int i = 0; i < m; ++i) {
      long long b; cin >> b;
      long long tot = 0;
      for (int j = 0; j < n; ++j) {
        cin >> line[j];
        if (j) tot += line[j];
      }
      if (tot + line[0] <= b) real += line[0];

      for (int j = 4; j >= 0; --j) {
        if (op[j] + tot <= b) {
          best += op[j];
          break;
        }
      }
    }
    cout << best - real << endl;
  }

  return 0;
}
