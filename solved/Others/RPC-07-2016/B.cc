#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
//#define endl '\n'

using namespace std;
typedef vector<vector<char> > vc;

void do_background(vc &b1, vc &b2, vc &back, char cmp) {
  for(int i = 0; i < b1.size(); i++) {
    for(int j = 0; j < b1[0].size(); j++) {
      if(b1[i][j] == cmp) {
        back[i][j] = b2[i][j];
      }else if(b2[i][j] == cmp) {
        back[i][j] = b1[i][j];
      }else{
        back[i][j] = b1[i][j];
      }
    }
  }
}

void move_pattern(vc &pat, int x, int y, char p) {
  vc tm = pat;
  for(int i = 0; i < pat.size(); i++) {
    for(int j = 0; j < pat[i].size(); j++) {
      if(tm[i][j] == p) {
        int tx = i + x;
        int ty = j + y;
        if(tx >= 0 && tx < pat.size() && ty >= 0 && ty < pat[0].size()) {
          pat[tx][ty] = p;
        }
        pat[i][j] = ' ';
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,m;
  string pat;
  while(cin >> n >> m >> pat && n + m) {
    vector<pair<int, int> > to;
    vector<vector<char> > b1(n, vector<char>(m, ' ')), b2, back, pattern;
    b2 = pattern = back = b1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> b1[i][j];
        if(b1[i][j] == pat[1] && to.size() == 0){
          to.push_back(make_pair(i, j));
        }
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> b2[i][j];
        if(b2[i][j] == pat[1] && to.size() == 1){
          to.push_back(make_pair(i, j));
        }
        if(b2[i][j] == pat[1]){
          pattern[i][j] = pat[1];
        }
      }
    }

    do_background(b1, b2, back, pat[1]);
    int dy = to[1].second - to[0].second;
    int dx = to[1].first - to[0].first;
    move_pattern(pattern, dx, dy, pat[1]);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(pattern[i][j] != ' ') {
          cout << pattern[i][j];
        }else{
          cout << back[i][j];
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
