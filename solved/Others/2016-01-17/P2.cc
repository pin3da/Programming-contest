#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void print_block(int a, int b, char c, int nl = 0) {
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j)
      cout << c;
    if (nl) cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int s, t, n;
  int tc = 1;
  while (cin >> s >> t >> n && (s + t + n)) {
    cout << "Case " << tc << ":" << endl;
    tc++;
    print_block(t, (n + 1) * t + n * s, '*', 1);

    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < s; ++j) {
        print_block(1, t, '*');
        for (int i = 0; i < n; ++i) {
          print_block(1, s, '.');
          print_block(1, t, '*');
        }
        cout << endl;
      }
      print_block(t, (n + 1) * t + n * s, '*', 1);
    }
    cout << endl;
  }
  return 0;
}
