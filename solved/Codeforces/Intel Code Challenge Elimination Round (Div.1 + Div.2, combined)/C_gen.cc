#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int n = 100;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  srand(time(0));
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << rand() % 10 <<  ' ';
  }
  cout << endl;

  vector<int> id(n);
  for (int i = 0; i < n; ++i) id[i] = i + 1;
  random_shuffle(id.begin(), id.end());
  for (int i = 0; i < n; ++i)
    cout << id[i] << ' ';
  cout << endl;
  return 0;
}
