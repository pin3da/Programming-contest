using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 55
#define MS 100001

template<typename T> int toInt(T t){stringstream ss; ss<<t; int r; ss>>r; return r;}

int gid(const char &c){
  if(c >= 'A' and c <= 'Z') return c - 'A';
  return (c - 'a') + 26;
}

struct trie{
  struct node{
    int c;
    int a[MN];
  };

  node tree[MS];
  void clear(){
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  int nodes;

  void init(){
    nodes = 0;
    clear();
  }

  int add(const string &s, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = gid(s[i]);
      if(tree[cur_node].a[id] == -1){
        if(query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if(!query) tree[cur_node].c++;
    return tree[cur_node].c;
  }

};

string buffer;

int nextInt(){
  getline(cin,buffer);
  return toInt(buffer);
}

trie tree;
int solve(){
  int n = nextInt();
  tree.init();
  string line;
  while(n--){
    getline(cin,line);
    if(line.size() > 2) sort(line.begin()+1,line.end()-1);
    tree.add(line);
  }
  n = nextInt();
  int ans;
  while(n--){
    getline(cin,line);
    ans = 1;
    stringstream ss(line);
    while(ss>>line){
      if(line.size() > 2) sort(line.begin()+1,line.end()-1);
      ans *= tree.add(line,1);
    }
    printf("%d\n",ans);
  }
}

int main(){ ___
  int tc = nextInt();
  for(int i = 0; i< tc; ++i){
    printf("Case %d:\n",i+1); solve();
  }
  return 0;
}
