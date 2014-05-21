using namespace std;
#include<bits/stdc++.h>

int main() {
  int a,b;
  while(cin>>a>>b) {
    if(__gcd(a,b) == 1)
    cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
