#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string a[] = {"Rolien", "Naej", "Elehcim", "Odranoel"};
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    int k; cin >> k;
    while (k--) {
      int t; cin >> t; t--;
      cout << a[t] << endl;
    }
  }
  return 0;
}
