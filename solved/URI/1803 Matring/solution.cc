#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<string> line(4);
  for (auto &i : line)
    cin >> i;

  string ls, fs;
  for (int i = 0; i < 4; ++i) {
    fs += line[i][0];
    ls += line[i].back();
  }

  int l = atoi(ls.c_str()), f = atoi(fs.c_str());

  for (int i = 1; i < line[0].size() - 1; ++i) {
    string mi;
    for (int j = 0; j < 4; ++j)
      mi += line[j][i];

    int m = atoi(mi.c_str());
    cout << char ((f * m + l) % 257);
  }
  cout << endl;
  return 0;
}

