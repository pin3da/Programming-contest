#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> min_salary(n);
  for (auto &i : min_salary) cin >> i;
  vector<long long> offer(m), jobs(m);
  for (int i = 0; i < m; i++) {
    cin >> offer[i] >> jobs[i];
  }

  vector<vector<bool>> like(n, vector<bool> (m));
  for (int i = 0; i < n; i++) {
    string line; cin >> line;
    for (int j = 0; j < m; j++)
      like[i][j] = (line[j] == '1');
  }

  long long accepted = 0, salaries = 0;
  vector<long long> taken(m);
  for (int i = 0; i < n; i++) {
    int id_best = -1;
    long long best = 0;
    for (int j = 0; j < m; j++) {
      if ((jobs[j] - taken[j] > 0) && like[i][j]) {
        if (offer[j] > best) {
          id_best = j;
          best = offer[j];
        }
      }
    }
    if (best > min_salary[i]) {
      accepted++;
      salaries += best;
      taken[id_best]++;
    }
  }

  int out = 0;
  for (int i = 0; i < m; i++)
    out += (taken[i] == 0);
  cout << accepted << " " << salaries << " " << out << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
