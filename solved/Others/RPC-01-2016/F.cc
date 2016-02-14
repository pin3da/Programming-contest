#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl

const int MN = 1000005;

int p[MN];
bool source[MN];

int find_s(int x) {
  return (p[x] == x ? p[x] : p[x] = find_s(p[x]));
}

void merge_s(int x, int y) {
  int px = find_s(x), py = find_s(y);
  if (source[px] or source[py]) {
    source[py] = true;
    source[px] = true;
  }
  p[px] = py;
}

int main(){
  int t; cin >> t;
  while(t--){
    int n,m,pp,c,x,y; cin >> n >> m >> pp >> c;
    char tm;

    for(int i = 0; i < MN; i++){
      p[i] = i;
      source[i] = false;
    }

    for(int i = 0; i < pp; i++){
      cin >> x >> y;
      x++; y++;
      int newc = x * 200 + y;
      source[newc] = true;
    }

    for(int i = 0; i < c; i++){
      cin >> x >> y >> tm;
      x++;y++;
      int newc = x * 200 + y;
      int newcc = 0;
      if(tm == 'R'){
        newcc = (x + 1) * 200 + y;
      }else{
        newcc = x * 200 + (y + 1);
      }

      if(find_s(newc) != find_s(newcc)){
        merge_s(newc, newcc);
      }

    }

    set<int> ans;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int newc = i * 200 + j;
        if (!source[find_s(newc)])
          ans.insert(find_s(newc));
      }
    }


    cout << ans.size() << endl;
  }
  return 0;
}
