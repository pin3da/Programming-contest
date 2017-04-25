// http://codeforces.com/contest/451/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

const int MN  = 100100;
const int inf = 1000000010;
int num[MN];

int main() { ___

  int n;cin>>n;

  if (n == 1) {
    cout<<"yes"<<endl;
    cout<<"1 1"<<endl;
    return 0;
  }


  for (int i = 0 ; i < n; ++i)
    cin>>num[i];


  int test = 1;

  for (int i = 0; i + 1 < n; ++i) {
    if (num[i] > num[i + 1])
      test = 0;
  }

  if (test) {
    cout<<"yes"<<endl;
    cout<<"1 1"<<endl;
    return 0;
  }

  int ini = 1;
  while ( num[ini] > num[ini - 1] and ini < n) ini++;
  int end = n - 1;
  while ( num[end] > num[end - 1] and end > 1) end--;


  ini--;

  if (ini > end) {
    cout<<"no"<<endl;
  } else {

    int ok  = 1;
    reverse(num + ini, num + end + 1);

    for (int i = 0; i + 1 < n; ++i) {
      if (num[i] > num[i + 1])
        ok = 0;
    }
    if (!ok) {
      cout<<"no"<<endl;
    } else {
      cout<<"yes"<<endl;
      cout<<(ini + 1)<<" "<<(end + 1)<<endl;
    }

  }


  return 0;
}