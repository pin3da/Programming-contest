using namespace std;
#include<bits/stdc++.h>

const int MN = 1000001;
int d[MN];
int ans[MN];


int main() {
  for (long long i = 0; i < MN; ++i) {
    for (long long j = 1; j*j <= i; ++j) {
      if ((i % j) == 0) {
        d[i]++;
      }
    }
  }

  memset(ans, -1, sizeof ans);
  for (int i = 0; i < MN; ++i) {
    if (ans[d[i]] == -1) {
      ans[d[i]] = i;
    }
  }

  for (int i = 0; i < MN; ++i) {
    if (ans[i] != -1) {
      cout<<"mio["<<i<<"] = "<<ans[i]<<";";
    }
  }



  return 0;

}
