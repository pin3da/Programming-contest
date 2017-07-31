#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int s, v1,v2,t1,t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a = t1 + s * v1 + t1;
  int b = t2 + s * v2 + t2;
  if (a < b)
    puts("First");
  else if (b < a)
    puts("Second");
  else
    puts("Friendship");

  return 0;
}
