#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));
  int ok = random() & 1;
  puts(ok ? "First" : "Second");
  return 0;
}
