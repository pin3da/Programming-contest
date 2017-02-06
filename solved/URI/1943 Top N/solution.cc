#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int mark[] = {1, 3, 5, 10, 25, 50, 100};
  int n; cin >> n;
  for (int i = 0; i < 7; ++i) {
    if (n <= mark[i]) {
      cout << "Top " << mark[i] << endl;
      break;
    }
  }
  return 0;
}

