using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

double prob_no(int val, vector<int> &l, vector<int> &r) {
  int n = l.size();
  double ans = 1;
  for (int i = 0; i < n; ++i) {
    if (l[i] > val) return 0;
    if (r[i] < val) continue;
    ans /= (val - l[i] + 1.0);
  }
  return ans;
}

double exp_max(int val, vector<int> &l, vector<int> &r) {
  return 0;
}

int main() { ___

  int n; cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  for (int i = 0; i < n; ++i) {
    double win = 1.0 / (r[i] - l[i] + 1);
    for (int j = l[i]; j <= r[i]; ++j) {
      win *= prob_no(j, l, r);
      win *= exp_max(j - 1, l, r);
    }
  }



  return 0;
}
