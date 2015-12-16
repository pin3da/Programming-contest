using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int next_int() {
  string line; getline(cin, line);
  return atoi(line.c_str());
}


void solve() {
  int k = next_int()
    , t;
  map<char, int> p;
  char c;
  string line;
  for (int i = 0; i < k; ++i) {
    getline(cin, line);
    stringstream ss(line);
    ss >> c >> t;
    p[c] = t;
  }

  k = next_int();
  long long total = 0;
  for (int i = 0; i < k; ++i) {
    getline(cin, line);
    for (int j = 0; j < line.size(); ++j) {
      if (p.count(line[j]))
        total += p[line[j]];
    }
  }
  cout << total / 100 << "." << (total % 100 < 10 ? "0" : "" ) << total % 100  << "$" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n = next_int();
  for (int i = 0; i < n; ++i)
    solve();
  return 0;
}
