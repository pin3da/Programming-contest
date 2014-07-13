using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout<< #x " = "<<(x)<<endl

const int inf = 1<<30;
vector<string> ele;
string word;

int op[5555];
pair<int, int> memo[5555];
pair<int, int> mull = make_pair(-1,-1);
int paila;

pair<int, int> dp(int i) {
  if (i == word.size()) return make_pair(0,0);

  if (memo[i] != mull) return memo[i];

  pair<int, int> ans = make_pair(inf, inf);
  int empate = false;
  int disp = word.size() - i;
  for (int j = 0; j < ele.size(); ++j) {
    if (ele[j].size() > disp) continue;
    int match = 1;
    for (int k = 0; k < ele[j].size() and match; ++k)
      if (word[i + k] != ele[j][k]) match = 0;

    if (match) {
      pair<int, int> other = dp(i + ele[j].size());
      other.first++;
      other.second += j;
      if (other < ans) {
        op[i] = j;
        ans = other;
        empate = false;
      } else if (other == ans) {
        empate = true;
        op[i] = inf;
      }
    }
  }
  if (i== 0 and empate) paila = true;
  return memo[i] = ans;
}

void mp(string &s) {
  cout<<"[";
  cout<<(char)(toupper(s[0]));
  for (int i = 1; i < s.size(); ++i)
    cout<<s[i];
  cout<<"]";
}

void solve() {
  int ne;cin>>ne;
  ele.resize(ne);
  for (int i = 0; i < ne; ++i) {
    cin>>ele[i];
    for (int j = 0; j < ele[i].size(); ++j)
      ele[i][j] = tolower(ele[i][j]);
  }
  int nw;cin>>nw;

  for (int i = 0; i < nw; ++i) {
    cin>>word;
    paila = false;
    for (int j = 0; j < 5555; ++j)
      memo[j] = mull;

    memset(op, -1, sizeof op);
    for (int j = 0; j < word.size(); ++j)
      word[j] = tolower(word[j]);

    assert(dp(0).first < inf);

    if (!paila) {
      int cur = 0;
      while (cur < word.size()) {
        mp(ele[op[cur]]);
        cur += ele[op[cur]].size();
      }
      cout<<endl;
    } else {
      cout<<"Too Obvious"<<endl;
    }
  }
}

int main() { ___

  int tc;cin>>tc;
  for (int i = 0; i < tc; ++i)
    solve();


  return 0;
}
