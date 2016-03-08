#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int p; cin >> p;
    vector<int> a(p);
    for (auto &i : a)
      cin >> i;
    string line;
    cin >> line;
    int hits = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == 'S' && a[i] <= 2)
        hits++;
      if (line[i] == 'J' && a[i] > 2)
        hits++;
    }
    cout << hits << endl;
  }
  return 0;
}

