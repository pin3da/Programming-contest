#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int k; cin >> k;
    set<string> a;
    string line;
    while (k--) {
      cin >> line;
      a.insert(line);
    }

    if (a.size() > 1)
      cout << "ingles" << endl;
    else
      cout << *(a.begin()) << endl;

  }

  return 0;
}
