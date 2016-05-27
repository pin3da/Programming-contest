#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool ends_with(string a, string b) {
  if (b.size() > a.size()) return false;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < b.size(); ++i)
    if (a[i] != b[i]) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  int tc; cin >> tc;
  while (tc--) {
    cin >> a >> b;
    if (ends_with(a, b))
      cout << "encaixa" << endl;
    else
      cout << "nao encaixa" << endl;
  }
  return 0;
}
