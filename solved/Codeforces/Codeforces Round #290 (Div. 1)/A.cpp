// http://codeforces.com/contest/512/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

char MP = 'a' - 1;
char mat[111][111];


int main() { // ___
  int n;
  string line, ant;
  cin >> n;
  vector<int> in;
  memset(mat, MP, sizeof mat);
  cin >> ant;
  vector<int> g[30];
  vector<int> inc(30);
  for (int i = 0; i < n -1; ++i) {
    cin >> line;
    int j;
    for (j = 0; j < min(ant.size(), line.size()); ++j) {
      if (line[j] != ant[j]) break;
    }
    if (j == ant.size()) continue;
    if (j == line.size()) {
      cout << "Impossible" << endl;
      return 0;
    }
    g[ant[j] - 'a'].push_back(line[j] - 'a');
    inc[line[j] - 'a']++;
    ant = line;
  }

  queue<int> q;
  vector<int> ans;
  for (int i = 0; i < 26; ++i) {
    if (inc[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int i = 0; i < g[node].size(); ++i) {
      inc[g[node][i]]--;
      if (inc[g[node][i]] == 0)
        q.push(g[node][i]);
    }
  }
  if (ans.size() < 26) {
    cout << "Impossible" << endl;
    return 0;
  }


  for (int i = 0, j = 0; i < ans.size(); ++i) {
    if (ans[i] >= 0 and ans[i] < 26)
      cout << (char) (ans[i] + 'a');
  }
  cout << endl;

  return 0;
}