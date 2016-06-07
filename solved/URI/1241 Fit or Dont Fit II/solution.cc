#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool ends(const string &a, const string &b) {
  if (b.size() > a.size()) return false;
  int n = a.size() - 1, m = b.size() - 1;
  for (int i = 0; i < b.size(); ++i) {
    if (a[n - i] != b[m - i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    string a, b;
    cin >> a >> b;
    if (ends(a, b))
      cout << "encaixa" << endl;
    else
      cout << "nao encaixa" << endl;
  }

  return 0;
}
