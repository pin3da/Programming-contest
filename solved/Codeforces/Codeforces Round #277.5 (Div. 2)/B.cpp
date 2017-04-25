// http://codeforces.com/contest/489/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

int main() { ___

  int a; cin >> a;
  vector<int> boy(a);
  for (int i = 0; i < a; ++i)
    cin >> boy[i];

  int b; cin >> b;
  vector<int> girl(b);
  for (int i = 0; i < b; ++i)
    cin >> girl[i];

  sort(boy.begin(), boy.end());
  sort(girl.begin(), girl.end());

  int i = 0, j = 0, ans = 0;

  while (i < a and j < b) {
    if (fabs(boy[i] - girl[j]) <= 1) {
      ans++;
      i++;
      j++;
    } else if(boy[i] > girl[j]) {
      j++;
    } else {
      i++;
    }
  }

  cout << ans << endl;


  return 0;
}