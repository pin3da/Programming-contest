// http://codeforces.com/contest/303/problem/A

using namespace std;
#include<algorithm>
#include<iostream>
#include<queue>

int main() {

  int n;
  cin>>n;

  if (n&1) {
    for(int j = 0; j < 2; ++j) {
      for (int i = 0; i < n; ++i) {
        if(i)cout<<" ";
        cout<<i;
      }
      cout<<endl;
    }
    for (int i = 0; i < n; ++i) {
      if(i) cout<<" ";
      cout<<((i+i)%n);
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }

  return 0;
}