using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl


int main() {

  int tc;cin>>tc;
  for (int t = 0; t < tc; ++t) {
    int mask1 = 0, mask2 = 0;
    int where;cin>>where;
    where--;
    int tmp;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        cin>>tmp; if (i == where) mask1 = mask1 | (1<<(tmp));
      }

    cin>>where;
    where--;

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) {
        cin>>tmp; if (i == where) mask2 = mask2 | (1<<(tmp));
      }


    int ans = mask2 & mask1;
    cout<<"Case #"<<(t+1)<<": ";
    if (ans == 0)
      cout<<"Volunteer cheated!"<<endl;
    else if (__builtin_popcount(ans) > 1)
      cout<<"Bad magician!"<<endl;
    else
      for (int i = 1; i <= 16; ++i)
        if ((ans>>i) & 1)
          cout<<i<<endl;


  }

  return 0;
}
