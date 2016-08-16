#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string to_lower(string a) {
  for (int i = 0; i < a.size(); ++i)
    a[i] = tolower(a[i]);
  return a;
}

const long long start_time = 1465948800;
const long long end_time = 1468540800 + 1; // exclusive

int main() {
  assert(setlocale(LC_ALL, "en_US.UTF-8") != NULL);
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string buffer;
  while (getline(cin, buffer)) {
    int n, m;
    stringstream ss(buffer);
    ss >> n >> m;
    vector<string> topics(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, topics[i]);
      topics[i] = to_lower(topics[i]);
    }

    vector<vector<int> > score(1001, vector<int> (m));

    for (int i = 0; i < m; ++i) {
      getline(cin, buffer);
      stringstream ss2(buffer);
      long long r, t; ss2 >> r >> t;
      string line;
      getline(cin, line);
      int points = line.size() >= 100 ? 20 : 10;
      if (t >= start_time && t < end_time) points += 20;
      else points += 10;
      line = to_lower(line);
      for (int j = 0; j < n; ++j) {
        if (line.find(topics[j]) != string::npos) {
          score[r][j] += points;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      int id = -1, best = 0;
      for (int j = 0; j < 1001; ++j) {
        if (score[j][i] > best) {
          best = score[j][i];
          id = j;
        }
      }
      cout << id << endl;
    }
  }
  return 0;
}
