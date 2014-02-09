using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 1010

struct ant{
  int l,w,h;
  ant(){}

  bool operator < (const ant & o) const {
    if (h  == o.h) return (l * w * h) > (o.l * o.w * o.h);
    return h > o.h;
  }

};

int main() { ___

  int n;
  while (cin>> n) {
    if (n == 0) break;
    vector<ant> ants(n);
    for (int i = 0; i < n; ++i)
      cin>>ants[i].l>>ants[i].w>>ants[i].h;
    sort(ants.begin(), ants.end());
    int ans = ants[0].w * ants[0].l * ants[0].h;
    cout<<ans<<endl;
  }

  return 0;
}
