#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, t;
  cin >> n >> t;

  vector<long long> ans(t + 1);
  vector<int> frec(t + 1);

  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    if (tmp > t) continue;
    frec[tmp]++;
  }

  for (int i = 1; i <= t; i++) {
    if (frec[i]) {
      for (int j = i; j <= t; j += i) {
        ans[j] += frec[i];
      }
    }
  }

  long long best = *(max_element(ans.begin(), ans.end()));
  int sec = 0;
  for (int i = 1; i <= t; i++)
    sec += (ans[i] == best);

  cout << best << " " << sec << endl;
  return 0;
}
