using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool dist[200002];
int holes[200002];
int d[200002];

void solve(int n) {
  memset(dist, 0, sizeof dist);
  //memset(holes, 0, sizeof holes);
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    dist[t] = true;
    d[i] = t;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> holes[i];
  }

  sort(holes, holes + m);
  int ans = 0, j = 0;
  for (int i = 0; i < m; ++i) {
    if (dist[holes[i]])
      ans++;
    else {
      if (j)
        j--;
      for ( ; j < n && d[j] < holes[i]; ++j) {
        if (dist[holes[i] - d[j]]) {
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
