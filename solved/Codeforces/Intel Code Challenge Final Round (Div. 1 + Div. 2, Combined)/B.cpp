// http://codeforces.com/contest/724/problem/B

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

bool check(vector<vector<int> > &data, vector<int> &t) {
  for (size_t i = 0; i < data.size(); ++i) {
    int bad = 0;
    for (size_t j = 0; j < data[i].size(); ++j) {
      if (t[j] != data[i][j]) bad++;
    }
    if (bad > 2) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> gen(m);
    vector<vector<int> > data(n, vector<int> (m));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> data[i][j];

    for (int i = 0; i < m; ++i) gen[i] = i + 1;
    vector<vector<int> > target;
    target.push_back(gen);
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        vector<int> ot = gen;
        swap(ot[i], ot[j]);
        target.push_back(ot);
      }
    }

    int ok = false;
    for (size_t i = 0; i < target.size() && !ok; ++i) {
      if (check(data, target[i])) ok = true;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
