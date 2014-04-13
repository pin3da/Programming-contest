using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl



int main() {

  int tc;cin>>tc;
  for (int tid = 0; tid < tc; ++tid) {
    int n;cin>>n;
    deque<int> a(n),b(n);

    double tmp;
    for (int i = 0; i < n; ++i) {
      cin>>tmp;
      a[i] = round(tmp * 1000000);
    }
    for (int i = 0; i < n; ++i) {
      cin>>tmp;
      b[i] = round(tmp * 1000000);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    /*for ( int i = 0; i < n; ++i) cout<<a[i]<<" ";
    cout<<endl;
    for ( int i = 0; i < n; ++i) cout<<b[i]<<" ";
    cout<<endl;*/

    deque<int> f = a, s = b;
    int ans1 = 0;
    while (f.size()) {
      if (f.back() < s.back()) {
        f.pop_front();
        s.pop_back();
      } else {
        f.pop_back();
        s.pop_back();
        ans1++;
      }
    }

    f = b; s = a;

    int ans2 = 0;
    set<int> aa(a.begin(), a.end()), bb(b.begin(), b.end());
    for(set<int>::iterator it = aa.begin(); it != aa.end(); ++it) {
      int act = *(it);
      set<int>::iterator otro = bb.lower_bound(act);
      if (otro == bb.end()) {
        ans2++;
        bb.erase(bb.begin());
      } else {
        bb.erase(otro);
      }
    }

    cout<<"Case #"<<(tid+1)<<": "<<ans1<<" "<<ans2<<endl;

  }

  return 0;
}
