#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  string line;
  getline(cin, line);
  while (n--) {
    getline(cin, line);
    for (auto &i : line) {
      if (isalpha(i))
        i += 3;
    }
    reverse(line.begin(), line.end());
    for (int i = line.size() / 2; i < line.size(); ++i) {
      line[i]--;
    }
    cout << line << endl;
  }

  return 0;
}
