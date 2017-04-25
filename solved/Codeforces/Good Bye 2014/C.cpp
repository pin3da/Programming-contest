// http://codeforces.com/contest/500/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


void simulate(deque<pair<int, int> > &st, vector<int> &b) {
  int ans = 0;

  for (int i = 0; i < b.size(); ++i) {
    deque<pair<int, int> > tmp;
    while (st.back().first != b[i]) {
      ans += st.back().second;
      tmp.push_back(st.back());
      st.pop_back();
    }

    pair<int, int> top = st.back();
    st.pop_back();
    while (tmp.size()) {
      st.push_back(tmp.back());
      tmp.pop_back();
    }
    st.push_back(top);

  }

  cout << ans << endl;
}

int main() { ___

  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > w(n);
  vector<int> b(m);

  for (int i = 0; i < n; ++i) {
    cin >> w[i].second;
    w[i].first = i;
  }

  vector<int> visited(n, 0);
  vector<int> order;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    b[i]--;
    if (!visited[b[i]])
      order.push_back(b[i]);
    visited[b[i]] = true;
  }

  deque<pair<int, int> > stack;
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      stack.push_back(w[i]);

  reverse(order.begin(), order.end());

  for (int i = 0; i < order.size(); ++i)
    stack.push_back(w[order[i]]);


  simulate(stack, b);

  return 0;
}