/**
 * Wrong Answer
 * */
using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

int n;
vector<deque<int> > data;

bool game() {
  For (i, data.size()) {
    if (data[i].size()) return 1;
  }
  return 0;
}


int fun(int i, int turn) {
  if (data[i].size() == 0) return -1;
  if (turn) {
    return data[i].back();
  }
  return data[i].front();
}

int mmax(int turn) {
  int ans = -1;
  For (i, data.size()) {
    ans = max(ans, fun(i, turn));
  }
  return ans;
}


void rem(int i, int turn) {
  if (turn) data[i].pop_back();
  else data[i].pop_front();
}


int main() { ___
  cin>>n;

  For (i, n) {
    int t; cin>>t;
    deque<int> tmp;
    int tt;
    For (j, t) {
      cin>>tt;
      tmp.push_back(tt);
    }
    data.push_back(tmp);
  }

  int ciel = 0, jiro = 0;

  int turn  = 0;
  while (game()) {

    int tar = mmax(turn);
    For (i, data.size()) {
      if (fun(i,turn) == tar) {
        rem(i,turn);
        break;
      }
    }

    (turn ? jiro : ciel) += tar;

    turn ^= 1;
  }

  cout<<ciel<<" "<<jiro<<endl;
  return 0;
}
