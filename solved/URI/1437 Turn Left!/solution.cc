#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string dir = "NLSO";

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    string line;
    cin >> line;
    int t = 0;
    for (auto &i : line)
      if (i == 'D') t++;
      else t--;

    t %= 4;
    t += 4;
    t %= 4;
    cout << dir[t] << endl;
  }
  return 0;
}

