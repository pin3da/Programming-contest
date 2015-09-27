#include <bits/stdc++.h>
using namespace std;
const int MN = 100010;

int n, m;
int h[MN];
bool possible(int max_cover) {
  int router = max_cover + h[0];
  int routers_used = 1;
  for (int i = 1; i < m; i++)
    if (h[i] - router > max_cover) {
      router = h[i] + max_cover;
      routers_used++;
    }

  return routers_used <= n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cin >> h[i];
      h[i] *= 10;
    }
    sort(h, h + m);
    
    int lo = -1, hi = 10010000;
    while (hi - lo > 1) {
      int mid = (hi + lo) >> 1;
      if (possible(mid))
    	hi = mid;
      else
    	lo = mid;
    }

    cout << hi / 10 << "." << hi % 10 << endl;
  }
  
  return 0;
}
