// WIP
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define null NULL

const long long mod = 1e9 + 7;
const int MN = 100000 + 100;

long long add(long long x, long long y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

long long lucas[MN];
long long invluc[MN];

long long get_lucas(int a, int b) {
  if (a) return add(lucas[b], mod - lucas[a - 1]);
  return lucas[b];
}

struct node {
  node *l, *r;
  int a, b, p; // check if pending in the interval [a, b]
               // use invluc if a > b
  long long sum;
  node (long long val) : sum(val),
                         p(0),
                         l(null),
                         r(null)
  {}
  node () : sum(0), p(0), r(null), l(null) {}
};

typedef node* pnode;

pnode create(int l, int r) {
  if (l == r)  return new node();
  pnode cur = new node();
  int m = (l + r) >> 1;
  cur -> l = create(l, m);
  cur -> r = create(m + 1, r);
  return cur;
}

void del(pnode cur) {
  if (cur) {
    del(cur-> l);
    del(cur-> r);
    delete cur;
  }
}

void push_down(pnode cur) {
  if (cur-> p) {
    int a = cur-> a, b = cur-> b;
    if (a <= b) {
      cur-> sum = add(cur-> sum, get_lucas(a, b));
      int mid = (a + b) >> 1;
      if (cur-> l) {

      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  lucas[1] = 3;
  lucas[2] = 4;
  for (int i = 3; i < MN; ++i)
    lucas[i] = add(lucas[i - 1], lucas[i - 2]);
  memcpy(invluc, lucas, sizeof lucas);
  reverse(invluc + 1, invluc + MN);
  for (int i = 2; i < MN; ++i) {
    lucas[i] = add(lucas[i], lucas[i - 1]);
    invluc[i] = add(invluc[i], invluc[i - 1]);
  }

  return 0;
}
