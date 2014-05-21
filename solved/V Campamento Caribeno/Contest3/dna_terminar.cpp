using namespace std;
#include<bits/stdc++.h>

map<string, int> cod;
map<int, string> rev;
vector<string> all;
int cur;
int g[1000][4];
int caida[1000];
int terminal[1000];
vector<string> todo;

int num(char c) {
  if (c == 'A') return 0;
  if (c == 'G') return 1;
  if (c == 'C') return 2;
  return 3;
}

void fun(string &cad) {
  int node = 0;
  string tmp;
  for (int i = 0; i < cad.size(); ++i) {
    tmp.push_back(cad[i]);
    int to = cod[tmp];
    int go = num(cad[i]);
    g[node][go] = to;
    //cout<<"From "<<rev[node]<<" to "<<rev[to]<<endl;
    node = to;
    if (i == cad.size() - 1) terminal[node] = true;
  }
}

string line;

int memo[1000][1000];

int dpcaida(int state) {
  if (state == 0) return 0;

  if (caida[state] =! -1) return caida[state];
  string tmp;
  string mio = rev[state];
  int ans = 0;
  for (int j = mio.size() - 1; j >= 1 ; --j ) {
    tmp = (mio[j]) + tmp;
    if (cod.count(tmp) != 0) {
      ans = cod[tmp];
    }
  }
  return caida[state] = ans;
}

int dp(int id, int state) {
  if (id == line.size() ) return 0;
  if (memo[id][state] != -1) return memo[id][state];
  int ans = 20000;
  for (int i = 0; i < 4; ++i) {
    int llevo = 1;
    if (num(line[id]) == i) llevo--;
    if (g[state][i] != -1) {
      if (!terminal[g[state][i]])
        ans = min(ans, llevo + dp(id + 1, g[state][i]));
    } else {
      int other = dpcaida(state);
      //cout<<"Caida desde "<<rev[state]<<" a "<<rev[other]<<endl;
      ans = min(ans, llevo +  dp(id + 1, g[other][i]));
    }
  }
  return memo[id][state] = ans;
}
int main() {
  int n;
  int caso = 0;
  while(cin>>n and n) {
    cur = 1; // 0 is for root
    cod.clear();
    all.resize(n);
    memset(terminal, 0, sizeof terminal);

    for (int i = 0; i< 1000; ++i) {
      caida[i]= 0;
      for (int j = 0; j < 4; ++j){
        g[i][j] = -1;
      }
    }

    for (int i = 0; i<  n; ++i) {
      cin>>all[i];
      string tmp;
      for (int j = 0; j<  all[i].size(); ++j) {
        tmp.push_back(all[i][j]);
        if (cod.count(tmp) == 0) {
          todo.push_back(tmp);
          rev[cur] = tmp;
          cod[tmp] = cur++;
        }
      }
    }
    for (int i = 0 ; i < n; ++i) fun(all[i]);

    cin>>line;
    /*for (int i = 0; i < cod.size() +1; ++i) {
      cout<<terminal[i]<<" ";
    }*/
    memset(memo, -1, sizeof memo);
    int ans = dp(0,0);
    if (ans == 20000) ans  = -1;
    cout<<"Case "<<++caso<<": "<<ans<<endl;
  }

}
