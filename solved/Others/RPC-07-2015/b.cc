using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int read() {
  string line;
  getline(cin, line);
  return atoi(line.c_str());
}

void solve() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  // unordered_map<string, bool> seen;
  vector<bool> seen;
  vector<string> w;
  while (ss >> line) {
    w.push_back(line);
    seen.push_back(0);
  }

  while (getline(cin, line) && line != "what does the fox say?") {
    stringstream aa(line);
    string animal, goes, sound;
    aa >> animal >> goes >> sound;
    for (int i = 0; i < seen.size(); ++i) {
      if (w[i] == sound)
        seen[i] = true;
    }
  }

  bool first = true;
  for (int i = 0; i < seen.size(); ++i) {
    if (!seen[i]) {
      if (!first)
        cout << " ";
      cout << w[i];
      first = false;
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = read();
  while (tc--) solve();
  return 0;
}
