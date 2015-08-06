using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  while (cin >> a >> b) {
    if (a == -1 && b == -1)
      break;
    if (a == b)
      cout << 1 << endl;
    else if (a == 0 || b == 0) {
      cout << (a + b) << endl;
    } else {
      if (a < b)
        swap(a, b);
      cout << (a + b) / (b + 1) << endl;
    }
  }
  return 0;
}

