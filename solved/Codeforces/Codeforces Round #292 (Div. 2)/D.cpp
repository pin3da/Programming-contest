// http://codeforces.com/contest/515/problem/D

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

string cod[] = {"<>", "^v", "><", "v^"};

void cooling(vector<vector<char>> &a, vector<vector<int>> &degree, queue<pair<int, int>> &q, int i, int j) {
  int n = a.size(), m = a[0].size();
  for (int k = 0; k < 4; k++) {
    int x = i + dx[k];
    int y = j + dy[k];
    if (x >= 0 and x < n and y >= 0 and y < m and a[x][y] != '*') {
      degree[x][y]--;
      if (degree[x][y] == 1)
        q.push({x, y});
    }
  }
}

int main() { ___

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> degree(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 and x < n and y >= 0 and y < m and a[x][y] != '*')
          degree[i][j]++;
      }
    }
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (degree[i][j] == 1) {
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    if (a[i][j] != '.')
      continue;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 and x < n and y >= 0 and y < m and a[x][y] == '.') {
        a[i][j] = cod[k][0];
        a[x][y] = cod[k][1];
        cooling(a, degree, q, x, y);
        break;
      }
    }
  }

  int ok = true;
  for (int i = 0; i < n and ok; i++) {
    for (int j = 0; j < m and ok; j++) {
      if (a[i][j] == '.')
        ok = false;
    }
  }

  if (ok) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  else {
    cout << "Not unique" << endl;
  }


  return 0;
}