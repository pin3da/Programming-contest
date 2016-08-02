#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, x;
  while(cin >> n) {
    int odd = 0, eve = 0, sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> x;
      odd += (x & 1);
      eve += !(x & 1);
      sum += x;
    }
    if(sum & 1) {
      cout << odd << endl;
    }else{
      cout << eve << endl;
    }
  }
  return 0;
}
