using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define IsComp(n) (_c[n>>5]&(1<<((n)&31)))
#define SetComp(n) _c[n>>5]|=(1<<((n)&31))

const long long MN = 30003;
const long long MAXP = MN * MN;
int _c[(MAXP>>5)+1];

void solve(vector<int> &ans) {
  long long count = 1;
  for (long long i = 1; i < MN; ++i) {
    for (long long j = i; j <= i * i; j += i) {
      if (!IsComp(j)) {
        count++;
        SetComp(j);
      }
    }
    ans[i] = count;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
   vector<int> ans(MN);
   memset(_c, 0, sizeof _c);
   solve(ans);

  int t, n; cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << ans[n] << endl;
  }

  return 0;
}
