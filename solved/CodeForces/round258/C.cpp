using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

int found;


long long n,k,d1,d2;

void search(long  long a, long long b, long long c) {

  if (a < 0LL or b < 0LL or c < 0LL) return;

  if (a +  b + c == k) {
    long long mmax = max(a, max(b, c));
    long long queda = n - k;
    long long nece = (mmax - a + mmax - b + mmax - c);
    if (queda >= nece and ((queda - nece) % 3LL == 0LL))
      found = true;
  }
}

int main() { ___

  int t;cin>>t;

  while (t--) {
    cin>>n>>k>>d1>>d2;

    found = 0;

    if (n % 3LL and n) {
      cout<<"no"<<endl;
      continue;
    }

    long long a,b,c;

    c = (k - d1 - d2 - d2) / 3LL;
    b = d2 + c;
    a = d1 + b;

    search(a, b, c);

    c = (k - d1 + d2 + d2) / 3LL;
    b = c - d2;
    a = d1 + b;

    search(a, b, c);

    c = (k + d1 - d2 - d2) / 3LL;
    b = d2 + c;
    a = b - d1;

    search(a, b, c);

    c = (k + d1 + d2 + d2) / 3LL;
    b = c  - d2;
    a = b - d1;


    search(a, b, c);


    if (found)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;


  }

  return 0;
}
