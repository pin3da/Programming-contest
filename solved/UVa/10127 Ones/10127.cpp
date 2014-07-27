using namespace std;
#include<bits/stdc++.h>

int main() {

  int n;
  while (cin>>n) {
    int ans = 0;
    int num = 0;
    do {
      num = (num * 10) % n;
      num = (num + 1) %n;
      ans++;
    } while (num);

    cout<<ans<<endl;
  }
  return 0;
}
