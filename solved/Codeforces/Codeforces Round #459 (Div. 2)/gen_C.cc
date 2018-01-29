#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main(int argc, char **argv) {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));

  string ca = ")(?";
  int n = atoi(argv[1]);
  for (int i = 0; i < n; i++) {
    cout << ca[random() % 3];
  }
  cout << endl;
  return 0;
}
