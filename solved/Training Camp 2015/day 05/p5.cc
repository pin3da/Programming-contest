using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

const char start = 'a' - 1;

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> all(n);
  vector<vector<int>> g(30);
  vector<int> in(30, 0);
  for (int i = 0; i < n; ++i) {
    cin >> all[i];
    all[i].push_back(start);
    if (i == 0) continue;
    for (int j = i - 1; j < i; ++j) {
      int k = 0;
      while (k < all[i].size()  && k < all[j].size() && all[i][k] == all[j][k]) k++;
      g[all[j][k] - start].push_back(all[i][k] - start);
      in[all[i][k] - start]++;
      //cout << all[j][k] - start << " bef " << all[i][k] - start << endl;
    }
  }
  deque<int> q;
  vector<int> vi(30, 0);
  for (int i = 0; i < 27; ++i) {
    if (in[i] == 0) {
      q.push_back(i);
    }
  }

  vector<int> ans(30, -1);
  int time = 0;
  while (!q.empty()) {
    int cur = q.front();q.pop_front();
    ans[cur] = time++;
    vi[cur] = true;
    for (int k = 0; k < g[cur].size(); ++k) {
      in[g[cur][k]]--;
      if (in[g[cur][k]] == 0)
        q.push_back(g[cur][k]);
    }
  }

  for (int i = 0; i < 27; ++i) {
    if (!vi[i]) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  if (ans[0] != 0) {
    cout << "Impossible" << endl;
    return 0;
  }

  for (int i = 1; i < 27; ++i) {
    for (int j = 0; j < ans.size(); ++j) {
      if (ans[j] == i)
        cout << char(j + 'a' - 1);
    }
  }
  cout << endl;

  return 0;
}
