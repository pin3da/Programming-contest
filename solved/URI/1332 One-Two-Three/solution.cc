#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int cmp(string a, string b) {
  int match = 0;
  for (int i = 0; i < a.size(); ++i)
    match += a[i] == b[i];
  return match >= (a.size() - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    string line; cin >> line;
    if (line.size() == 5)
      cout << 3 << endl;
    else
      if (cmp("one", line))
        cout << 1 << endl;
      else
        cout << 2 << endl;
  }

  return 0;
}
