// http://codeforces.com/contest/618/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  vector<int> d(100000 + 10);
  cin >> n;
  for (int i = 30; i >= 0; --i)
    if ((n >> i) & 1)
      cout << (i + 1) << " ";
  cout << endl;
  return 0;
}

