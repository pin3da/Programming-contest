using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 40

int a[MP];
int g[MP];

void precompute(){
  memset(g, 0, sizeof g);

  g[1] = 1;
  g[2] = 2;
  for (int i = 3; i < MP; ++i) {
    memset(a,0,sizeof a);

    for (int j = 0; j < i; ++j) {
      a[g[j] ^ g[i - j - 1]] = true; //Taking 1 petal
      if (i - j - 2 >= 0)
        a[g[j] ^ g[i - j - 2]] = true; //Taking 2 petals
    }
    int j = 0;
    while (a[j]) ++j;
    g[i] = j;
  }
}


int main() { ___

  int t; cin>>t;
  precompute();
  for (int tid = 1; tid <= t; ++tid) {
    int n, m;cin>>n>>m;
    vector<int> petals(n);
    int index;
    for (int i = 0; i < m; ++i) {
      cin>>index;
      index--;
      petals[index] = true;
    }

    int tam = 0;
    int nim = 0;
    for (int i = 0; i < n; ++i) {
      int pos = (index + i) % n;
      if (petals[pos]) {
        nim ^= g[tam];
        tam = 0;
      } else {
        tam++;
      }
    }
    nim ^= g[tam];

    cout<<"Case "<<tid<<": ";
    if (nim) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }

  return 0;
}
