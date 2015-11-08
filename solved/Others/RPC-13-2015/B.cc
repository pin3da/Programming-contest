using namespace std;
#include <bits/stdc++.h>

void check(vector<vector<int> > &g, int node, vector<int> &vi) {
  if (vi[node]) return;
  vi[node] = true;
  for (int i = 0; i < g[node].size(); ++i) 
    check(g, g[node][i], vi);
}

void solve(int n) {
  vector<int> x(n), y(n), r(n);
  int last = 0;
  vector<vector<int> > g(n + 2);
   
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
    if (x[i] <= r[i]) {
      g[n].push_back(i);
      g[i].push_back(n);
    }
    if (x[i] + r[i] >= 200) {
      g[n + 1].push_back(i);
      g[i].push_back(n + 1);
    }
    
    for (int j = 0; j < i; ++j) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      if (dx * dx + dy * dy <= (r[i] + r[j]) * (r[i] + r[j])) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
    vector<int> vi(n + 2);
    check(g, n, vi);
    if (!vi[n + 1]) 
      last = i + 1;      
  }  
  
  cout << last << endl;
}

int main() {
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}

