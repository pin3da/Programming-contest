// http://codeforces.com/contest/528/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


#define MAXN (1<<20)
typedef long long int ll;
struct Segment_tree{
  vector<ll> M;
  vector<ll> pending;
  Segment_tree(int n){
    M.resize(MAXN);
    pending.resize(MAXN);
  }
  void init(int node,int a,int b){
    if(a==b){
      M[node] = pending[node] = 0LL;
    }else{
      init(node<<1,a,(a+b)>>1);
      init((node<<1)+1 ,((a+b)>>1)+1,b);
      M[node] = max(M[node<<1], M[(node<<1)+1]);
    }
  }

  ll query(int node,int a,int b, int i,int j){
    if(a>j or b < i) return 0LL;
    if(a >= i and b<=j)
      return M[node];
    ll p1 = query(node<<1,a,(a+b)>>1,i,j);
    ll p2 = query((node<<1)+1,((a+b)>>1)+1,b,i,j);
    return max(p1, p2);
  }
  void update(int node,int a,int b,ll value,int i,int j){
    if(b < i or a > j) return;
    if(a>=i and b<= j){
      M[node] = value;
      return;
    }
    update(node<<1 , a , (a+b)>>1 ,value,i,j);
    update((node<<1)+1, ((a+b)>>1)+1 , b ,value,i,j);
    M[node] = max(M[node<<1], M[(node<<1)+1]);
  }
};

int main() { ___

  int hiw, hih, n;
  int low = 0, loh = 0;
  cin >> hiw >> hih >> n;
  char op;
  int x;
  set<int> h, w;
  n += 1;
  Segment_tree th(n), tw(n);
  th.init(1,0,n-1);
  tw.init(1,0,n-1);
  h.insert(loh);
  h.insert(hih);
  w.insert(low);
  w.insert(hiw);
  th.update(1, 0, n - 1, hih - loh, 0, 0);
  tw.update(1, 0, n - 1, hiw - low, 0, 0);
  for (int kk = 0; kk < n - 1; kk++) {
    cin >> op >> x;
    if (op == 'H') {
      int i = *(--h.lower_bound(x));
      int j = *h.upper_bound(x);
      h.insert(x);
      // D(i);D(j); D(x);
      th.update(1, 0, n - 1, x - i, i, i);
      th.update(1, 0, n - 1, j - x, x, x);
      // cout << " new val " << (i) << " " << (x - i) << endl;
      // cout << " new val " << (x) << " " << (j - x) << endl;
    } else {
      int i = *(--w.lower_bound(x));
      int j = *w.upper_bound(x);
      w.insert(x);
      // D(i);D(j); D(x);
      tw.update(1, 0, n - 1, x - i, i, i);
      tw.update(1, 0, n - 1, j - x, x, x);
      // cout << " new val " << (i) << " " << (x - i) << endl;
      // cout << " new val " << (x) << " " << (j - x) << endl;
    }
    // cout << low << " " << hiw << " " << loh << " " << hih << endl;
    cout << th.query(1, 0, n - 1, 0, n - 1) * tw.query(1, 0, n - 1, 0, n - 1) << endl;
    // D(th.query(1, 0, n - 1, 0, n - 1));
    // D(tw.query(1, 0, n - 1, 0, n - 1));
  }
  return 0;
}
