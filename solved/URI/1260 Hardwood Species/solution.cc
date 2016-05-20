#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void process(vector<string> &d, int b) {
  map<string, int> f;
  for (auto &i : d) f[i]++;
  for (auto &i : f)
    cout << i.first << ' ' << (100.0 * i.second) / d.size() << endl;
  if (b)
    cout << endl;
  d.clear();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cout << fixed << setprecision(4);
  string line; getline(cin, line);
  int n = atoi(line.c_str());
  getline(cin, line);
  vector<string> buff;
  while (getline(cin, line)) {
    if (line.size() == 0)
      process(buff, 1);
    else
      buff.emplace_back(line);
  }
  process(buff, 0);
  return 0;
}
