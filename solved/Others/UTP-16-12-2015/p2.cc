using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int next_int() {
  string line; getline(cin, line); return atoi(line.c_str());
}

vector<int> unpack(vector<int> &a, int mask) {
  vector<int> ans;
  for (int i = 0; i < a.size(); ++i) {
    if ((mask >> i) & 1) ans.push_back(a[i]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t, n;
  while (cin >> t >> n && n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<vector<int>> sol;
    for (int mask = 0; mask < (1 << n); ++mask) {
      vector<int> b = unpack(a, mask);
      if (accumulate(b.begin(), b.end(), 0) == t) {
        sol.push_back(b);
      }
    }
    sort(sol.begin(), sol.end());
    sol.resize(unique(sol.begin(), sol.end()) - sol.begin());
    reverse(sol.begin(), sol.end());
    cout << "Sums of " << t << ":" << endl;
    if (sol.size() == 0) cout << "NONE" << endl;
    for (int i = 0; i < sol.size(); ++i) {
      for (int j = 0; j < sol[i].size(); ++j) {
        if (j) cout << "+";
        cout << sol[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
