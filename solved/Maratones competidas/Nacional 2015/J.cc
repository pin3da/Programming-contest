// Sol by @carlos4rias
#include<bits/stdc++.h>

using namespace std;

#define oo 100000000

int main(){
  int n,r;
  char c;
  while( cin >> n >> r >> c){
    pair<int,string> rounds[r];

    for(int i = 0; i < r; i++) cin >> rounds[i].first >> rounds[i].second;

    int G[n][n];
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)G[i][j] = oo;

    for(int i = 'a'; i < 'a' + n;i++){
      for(int j = i + 1; j < 'a' + n;j++){
        int score1 = 0;
        int score2 = 0;
        for(int k = 0; k < r; k++){
          int c1 = rounds[k].second.find((char)i,0);
          int c2 = rounds[k].second.find((char)j,0);
          if(c1 < c2) score1 += rounds[k].first;
          else        score2 += rounds[k].first;
        }

        if(score1 == score2 ){
          if((char)i == c)
            G[i - 'a'][j - 'a'] = 1;
          if((char)j == c)
            G[j - 'a'][i - 'a'] = 1;
        }else if(score1 > score2){
          G[i - 'a'][j - 'a'] = 1;
        }

        else{
          G[j - 'a'][i - 'a'] = 1;
        }
      }
    }

    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          G[i][j] = min(G[i][j],G[i][k] + G[k][j]);

    int sol = 0;
    for(int i = 0; i < n;i++){
      if(i != c-'a' &&  G[c-'a'][i] != oo ) sol++;
    }

    if(sol >= n-1) cout << "Y" << endl;
    else           cout << "N" << endl;
  }
}
