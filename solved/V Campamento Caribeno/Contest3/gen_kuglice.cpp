using namespace std;
#include<bits/stdc++.h>

const int MN = 200;
int main () {
  srand(time(0));
  cout<<MN<<endl;
  for (int i = 2; i < MN + 1; ++i)
    cout<<i<<" ";
  cout<<1<<endl;
  int t = MN;
  cout<<t<<endl;
  while (t--) {
    cout<<(rand() % 2) + 1;
    cout<<" "<< ((rand()% MN ) + 1)<< endl;
  }
}
