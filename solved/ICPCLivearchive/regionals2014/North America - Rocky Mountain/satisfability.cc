using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int next_int() {
  string line;
  getline(cin, line);
  return atoi(line.c_str());
}
void solve() {
  string buff;
  getline(cin, buff);
  int n, m;
  stringstream bb(buff);
  bb >> n >> m;
  vector<vector<pair<int, int> > > need(m);
  for (int i = 0; i < m; ++i) {
    string line;
    getline(cin, line);
    for (int j = 0; j < line.size(); ++j)
      if (line[j] == 'v')
        line[j] = ' ';
    stringstream ss(line);
    while (ss >> line) {
      pair<int, int> cur(0, 1);
      if (line[0] == '~') {
        cur.second = false;
        line = line.substr(1);
      }

      line = line.substr(1);
      cur.first = atoi(line.c_str()) - 1;
      need[i].push_back(cur);
    }
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    int sat = true;
    for (int j = 0; j < m; ++j) {
      int ok = false;
      for (int i = 0; i < need[j].size(); ++i) {
        int beep = need[j][i].first;
        int boop = need[j][i].second;
        if (((mask >> beep) & 1) == boop) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        sat = false;
        break;
      }
    }

    if (sat) {
      cout << "satisfiable" << endl;
      return;
    }
  }
  cout << "unsatisfiable" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n = next_int();
  while (n--)
    solve();
  return 0;
}
