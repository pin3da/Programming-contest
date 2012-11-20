#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

#define D(x) //cout << #x " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) rep(i,0,n)

typedef vector<int> vi;
typedef vector<string> vs;

struct Trie {
  struct Node {
    int ch[26];
    int n;
    Node() {
      n = 0;
      memset(ch,0,sizeof(ch));
    }
  };
  int sz;
  vector < Node > nodes;
  vi isend;
  void init() {
    nodes.clear();
    nodes.resize(1);
    isend.resize(1);
    sz = 1;
  }
  void insert(const char * s) {
    int idx, cur = 0;

    for (; * s; ++s) {
      idx = * s - 'a';
      if (!nodes[cur].ch[idx]) {
        nodes[cur].ch[idx] = sz++;
        nodes.resize(sz);
	isend.resize(sz);
      }

      cur = nodes[cur].ch[idx];
    }
    isend[cur] = 1;
  }
};

int main(){
  int n;
  while(cin >> n){
    Trie T; T.init();
    vs words;
    REP(i,n){
      string w;
      cin >> w;
      words.push_back(w);
      T.insert(w.c_str());
    }

    int total = 0;
    REP(i,n){
      int cnt = 1;
      string w = words[i];

      int cur = 0;
      cur = T.nodes[cur].ch[w[0] - 'a'];
      rep(j,1,w.size()){
	    int possibles = 0;
	    REP(k,26) if(T.nodes[cur].ch[k]) possibles++;
	    if(possibles > 1 || T.isend[cur]) cnt++;
	    cur = T.nodes[cur].ch[w[j] - 'a'];
      }
      D(cnt);
      total += cnt;
    }
    double ans = total; ans /= n;
    printf("%.2lf\n",ans);
  }
  return 0;
}
