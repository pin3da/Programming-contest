using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double dp_t;

vector<long long> ans;

int N;

long long dp[(1 << 20) + 10][22][3];

long long go(int mask, int last, int op) {
  if (mask == 0)
    return 1;

  if (dp[mask][last][op] != -1)
    return dp[mask][last][op];

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    if ((mask >> i) & 1) {
      if ((last == 21) || (op && (i > last)) || (!op && (last > i))) {
        int nmask = mask ^ (1 << i);
        ans += go(nmask, i, op ^ 1);
      }
    }
  }
  return dp[mask][last][op] = ans;
}

void solve() {
  int n;
  cin >> n;
  cout << ans[n] << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  /*
     cout << "{";
     for (int i = 1; i < 21; ++i) {
     memset(dp, - 1, sizeof dp);
     N = i;
     if (i > 1) cout << ",";
     cout << go((1 << i) - 1, 21, 0) + go((1 << i) - 1, 21, 1);
     }
     cout << "}";*/
  vector<long long> ans({1,2,4,10,32,122,544,2770,
      15872,101042,707584,5405530,44736512,398721962,
      3807514624,38783024290,419730685952,4809759350882,
      58177770225664, 740742376475050});


  assert(ans.size() == 20);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int id, n;
    cin >> id >> n;
    cout << id << " " << ans[n - 1] << endl;

  }
  return 0;
}
