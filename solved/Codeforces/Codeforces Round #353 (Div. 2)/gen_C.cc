#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int n = atoi(argv[1]), m = 50;
  vector<int> a(n);
  while (m > 0) {
    int k = (rand() % m) + 1;
    a[rand() % n] += k;
    a[rand() % n] -= k;
    m -= k;
  }
  cout << n << endl;
  for (auto &i : a)
    cout << i << ' ';
  cout << endl;
  return 0;
}
