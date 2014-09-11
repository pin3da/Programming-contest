/**
 * Not solved yet
 * */

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'


long long w,m,k;

long long ten[20];
long long accum[20];


int f(long long cur) {

  int bottom = ceil(log(m) / log(10.0));
  int top    = ceil(log(m + cur) / log(10.0));

  if (bottom == top) {
    return k * bottom * (cur) <= w;
  }

  long long begin  = ten[bottom] - m;
  long long end    = (m + cur) - ten[top - 1];
  long long others = (ten[top - 1] - ten[bottom]);

/*
  D(bottom);
  D(top);
  D(begin);
  D(end);
  D(others);
  D(accum[top - 1] - accum[bottom]);
  D(begin * bottom);
  D(end * top);
  cout<<endl<<endl;*/


  return k * ((begin * bottom) + (end * top) + others * (accum[top - 1] - accum[bottom]) ) <= w;

}


int main() { ___

  long long cur = 1;

  for (int i = 0; i < 20; ++i) {
    ten[i] = cur;
    accum[i] += (i + 1) * (cur * 10);
    if (i) accum[i] += accum[i - 1];
    cur *= 10;
  }

  cin>>w>>m>>k;

  long long lo = 0, hi = w;

  //f(7);
  f(10000000000000000);



  while (lo < hi) {

    if (lo + 1LL == hi) {
      if (f(hi))
        lo = hi;
      break;
    }
    long long mid = (lo + hi)>>1;
    if (f(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout<<lo<<endl;


  return 0;
}
