// http://codeforces.com/contest/416/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n;
  while (cin>>n) {
    long long mmin = -2 * 1e9;
    long long mmax = 2  * 1e9;
    long long a;
    string op;
    string ans;
    while (n--) {
      cin>>op>>a>>ans;
      if (ans == "N") {
        if (op == ">=") op = "<";
        else if (op == "<=") op = ">";
        else if (op == ">") op = "<=";
        else op = ">=";
      }

      if (op == "<=") {
        mmax = min(a, mmax);
      } else if (op == ">=") {
        mmin = max(a, mmin);
      } else if (op == ">") {
        mmin = max(mmin, a + 1);
      } else {
        mmax = min(mmax, a - 1);
      }

      if (mmin > mmax) {
        cout<<"Impossible"<<endl;
        exit(0);
      }
    }
    cout<<mmin<<endl;
  }

  return 0;
}