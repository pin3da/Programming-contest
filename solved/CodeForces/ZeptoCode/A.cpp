using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 2020;

struct st{
  int h, m;
  st(){}
  st(int a, int b) : h(a), m(b)  {}
  bool operator < (const st &o) const {
    if (h == o.h) return m > o.m;
    return h < o.h;
  }
};


deque<st> t1, t2;

int main() { ___

  int n,x; cin>>n>>x;

  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    int t,h,m;
    cin>>t>>h>>m;
    if (t == 0) {
      t1.push_back(st(h,m));
    } else {
      t2.push_back(st(h,m));
    }
  }

  sort(t1.begin(), t1.end());
  sort(t2.begin(), t2.end());

  int type;
  if (t1.empty())
    type = 1;
  else if (t2.empty())
    type = 0;
  else if (t2.front().h > t1.front().h)
    type = 0;
  else
    type = 1;

  int ans = 0;
  while (true) {
    if (type == 0) {
      if (t1.empty() or x < t1.front().h) {
        break;
      }
      x += t1.front().m;
      t1.pop_front();
      type ^= 1;
    } else {
      if (t2.empty() or x < t2.front().h) {
        break;
      }
      x += t2.front().m;
      t2.pop_front();
      type ^= 1;
    }
    ans ++;
  }

  cout<<ans<<endl;

  return 0;
}


