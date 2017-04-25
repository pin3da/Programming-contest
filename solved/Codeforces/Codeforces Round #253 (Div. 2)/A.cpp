// http://codeforces.com/contest/443/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    line = line.substr(1, line.size() - 2);
    for (size_t i = 0; i < line.size(); ++i)
      if (line[i] == ',') line[i] = ' ';

    stringstream ss(line);
    set<string> ans;
    string n;
    while (ss >> n)  ans.insert(n);
    cout << ans.size() << endl;
  }
  return 0;
}
