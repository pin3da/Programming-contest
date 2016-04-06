#include <bits/stdc++.h>

using namespace std;
#define D(x) cout<< #x " = "<<(x)<<endl
#define MAXN (1<<20)

typedef long long int ll;

struct Segment_tree{
  vector<ll> M;
  vector<ll> pending;

  Segment_tree(int n) {
    M.resize(MAXN);
    pending.resize(MAXN);
  }

  void init(int node,int a,int b) {
    if (a==b) {
      M[node] = pending[node] = 0LL;
    }else{
      init(node<<1,a,(a+b)>>1);
      init((node<<1)+1 ,((a+b)>>1)+1,b);

      M[node] = M[node<<1] + M[(node<<1)+1];
    }
  }


  void propagate(int node, int a, int b) {
    if (a == b) {
      M[node] += pending[node];
      pending[node] = 0LL;
      return;
    }
    M[node] += pending[node];
    ll unit = pending[node]/(b-a+1);
    pending[node<<1] += ((ll)(((a+b)>>1) - a + 1)) * unit;
    pending[(node<<1)+1] += ((ll)(b - ((a+b)>>1))) * unit;
    pending[node] = 0LL;
  }

  ll query(int node, int a, int b, int i, int j) {
    propagate(node,a,b);
    if( a > j or b < i) return 0LL;
    if(a >= i and b <= j)
      return M[node];
    ll p1 = query(node<<1,a,(a+b)>>1,i,j);
    ll p2 = query((node<<1)+1,((a+b)>>1)+1,b,i,j);

    return p1 + p2;

  }


  void update(int node, int a, int b, ll value, int i, int j) {
    propagate(node, a, b);
    if (b < i or a > j) return;
    if (a >=i and  b <= j) {
      M[node] += (b-a+1) * value;
      pending[node<<1] += (((a+b)>>1) - a +1) * value;
      pending[(node<<1)+1] += (b - ((a+b)>>1)) * value;
      return;
    }

    update(node<<1 , a , (a+b)>>1 ,value,i,j);
    update((node<<1)+1, ((a+b)>>1)+1 , b ,value,i,j);

    M[node] = M[node<<1] + M[(node<<1)+1];
  }
};


int main() {
  int t;
  scanf("%d", &t);
  for(int ti = 1; ti <= t; ++ti) {
    int n, queries;
    scanf("%d%d", &n, &queries);
    Segment_tree tree(n);
    tree.init(1, 0, n - 1);
    while (queries--) {
      int type;
      scanf("%d", &type);
      if (type) {
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%lld\n", tree.query(1, 0, n - 1, i - 1, j - 1));
      } else {
        int i, j, v;
        scanf("%d%d%d", &i, &j, &v);
        tree.update(1, 0, n - 1, v, i - 1, j - 1);
      }
    }
  }
  return 0;
}

