// http://codeforces.com/contest/412/problem/A

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'



int main() { ___

  string line;
  int a, b;
  cin>>a>>b;
  cin>>line;

  if (b - 1 <= (a - b)) {
    for (int i = 0; i < b - 1; ++i) {
      cout<<"LEFT"<<endl;
    }
    for (int i = 0; i < a; ++i) {
      cout<<"PRINT "<<line[i]<<endl;
      if (i < a - 1)
        cout<<"RIGHT"<<endl;
    }
  } else {
    for (int i = 0; i < (a - b); ++i) {
      cout<<"RIGHT"<<endl;
    }
    for (int i = a - 1; i >= 0; --i) {
      cout<<"PRINT "<<line[i]<<endl;
      if (i > 0)
        cout<<"LEFT"<<endl;
    }


  }

  return 0;
}