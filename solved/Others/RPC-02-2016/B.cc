#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void paintV(int y, int k, vector<vector<char> > &b){
  for(int i = 0; i < (k * 4) + 1; i++){
    b[i][y] = '*';
  }
}

void paintH(int x, int k, vector<vector<char> > &b){
  for(int i = 0; i < (k * 4) + 1; i++){
    b[x][i] = '*';
  }
}

void paintDz(int x, int y, int k, vector<vector<char> > &b){
  for(int i = 0; i < (k * 3) + 1; i++){
    b[x + i][y + i] = '*';
  }
}

void paintDd(int x, int y, int k, vector<vector<char> > &b){
  for(int i = 0; i < (k * 3) + 1; i++){
    b[x + i][y - i] = '*';
  }
}

int main(){
  int n;
  while(cin >> n){
    vector<vector<char> > b(n * 4 + 1, vector<char>(n * 4 + 1, ' '));
    vector<vector<int> > pre(n * 4 + 2, vector<int>(n * 4 + 2, 0));
    paintV(n, n, b);
    paintV(n * 3, n, b);

    paintH(n, n, b);
    paintH(n * 3, n, b);

    paintDz(0, n, n, b);
    paintDz(n, 0, n, b);

    paintDd(0, n * 3, n, b);
    paintDd(n, n * 4, n, b);

    for(int i = 0; i < b.size(); i++){
      for(int j = b[i].size() - 1; j >= 0; j--){
        pre[i][j] = pre[i][j + 1] + (b[i][j] == '*');
      }
    }

    for(int i = 0; i < b.size(); i++){
      for(int j = 0; j < b[i].size(); j++){
        if(pre[i][j] == 0) break;
        cout << b[i][j];
      }
      cout << endl;
    }

  }
}
