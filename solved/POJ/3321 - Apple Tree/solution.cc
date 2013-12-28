using namespace std;
#include <cassert>
#include <cstring>
#include <cstdio>
#define MN 100100

struct Edge{
    int v, next;
}edge[MN];

int edgeNumber, head[MN];

void addEdge(int u, int v){
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int n;
int l[MN], r[MN];
int label[MN];
int id;

void dfs(int node, int pi){
  label[node] = l[node] = id++;
  for(int i = head[node]; i!=-1; i = edge[i].next){
    int v = edge[i].v;
    if(v == pi) continue;
    dfs(v,node);
  }
  r[node] = id - 1;
}

int tree[MN];

void add(int where, long long what){
  for (where++; where <= MN; where += where & -where){
    tree[where] += what;
  }
}

int query(int where){
  int sum = tree[0];
  for (where++; where > 0; where -= where & -where){
    sum += tree[where];
  }
  return sum;
}

int query(int from, int to){
  return query(to) - query(from-1);
}

int main(){

  int u,v;
  while(scanf("%d",&n) == 1){
    edgeNumber = 0;
    memset(head, -1, sizeof(head));

    for(int i = 0; i < n - 1 ; ++i){
      scanf("%d%d",&u,&v);
      u--;v--;
      addEdge(u,v);
    }

    id = 0;
    dfs(0,-1);
/*
    for(int i = 0; i< n; ++i)
      cout<<"Node "<<i<<" Labeled "<<label[i]<<endl;
*/

    memset(tree, 0, sizeof tree);

    for(int i = 0; i < n; ++i ) add(label[i],1);

    int q;scanf("%d",&q);
    char op[5];
    int t;
    while(q--){
      scanf("%s%d",op,&t);
      t--;
      if(op[0] == 'Q'){
        printf("%d\n",query(l[t], r[t]));
      }else{
        if(query(label[t], label[t])) add(label[t], -1);
        else  add(label[t], 1);
      }
    }
  }

  return 0;
}
