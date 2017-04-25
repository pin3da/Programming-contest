// http://codeforces.com/contest/451/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

long long n;

int check(long long a, long long b, long long c, long long k) {
  if (a < 0 or b < 0 or c < 0) return false;

  if (a + b + c == k) {
    long long greater = max (max(a, b), c);
    long long rest    = n - k;
    long long need    = (3LL * greater - (a+b+c));
    if (rest >= need and ((rest - need) % 3L) == 0L)
      return true;
  }

  return false;

}

int solve() {
  long long k,d1,d2;
  cin>>n>>k>>d1>>d2;

  long long a,b,c;

  c = (k - d1 - d2 - d2) / 3LL;
  b = d2 + c;
  a = d1 + b;
  if (check(a, b, c, k))
    return true;

  c = (k - d1 + d2 + d2) / 3LL;
  b = c - d2;
  a = d1 + b;
  if (check(a, b, c, k))
    return true;

  c = (k + d1 - d2 - d2) / 3LL;
  b = d2 + c;
  a = b - d1;

  if (check(a, b, c, k))
    return true;


  c = (k + d1 + d2 + d2) / 3LL;
  b = c  - d2;
  a = b - d1;

  if (check(a, b, c, k))
    return true;
  return false;
}

int main() { ___

  int t;cin>>t;
  while (t--) {
    if (solve())
      cout<< "yes"<<endl;
    else
      cout<< "no"<<endl;
  }
  return 0;
}    if (found)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;


  }

  return 0;
}