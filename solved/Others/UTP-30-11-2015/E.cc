using namespace std;
#include <bits/stdc++.h>

int main() {
  vector<string> line(4);
  for (auto &i : line) {
    cin >> i;
    i = i.substr(2);
  }
  vector<int> p;
  for (int i = 0; i < 4; ++i) {
    int shorter = 0, longer = 0;
    for (int j = 0; j < 4; ++j) {
      if (i == j) continue;
      if (2 * line[i].size() <= line[j].size()) shorter++;
      if (line[i].size() >= 2 * line[j].size()) longer++;
    }
    if (shorter == 3 || longer == 3)
      p.push_back(i);
  }

  if (p.size() == 1)
    cout << (char) (p[0] + 'A') << endl;
  else
    cout << 'C' << endl;
  return 0;
}
