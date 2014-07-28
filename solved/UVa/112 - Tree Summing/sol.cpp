using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MN = 11111;
int n;
int cur;
struct node{
  int val;
  vector<int> a;
};

node g[MN];
string line;
int parse(int i) {

  int j = i + 1;

  if (line[i + 1] == ')') {
    return -1;
  }

  int num = 0;
  int neg;
  if (line[j] == '-') {
    neg = true;
    j++;
  } else {
    neg = false;
  }

  while ((line[j] >= '0') and (line[j] <= '9')) {
    num *= 10;
    num += line[j] - '0';
    j++;
  }

  if (neg) num *= -1;

  int izq = parse(j);

  int cc = 1;
  int k;
  for  (k = j + 1;cc != 0; ++k) {
    if (line[k]=='(') cc++;
    if (line[k]==')') cc--;
  }

  int der = parse(k);
  g[cur].val = num;
  if (izq != -1)
    g[cur].a.push_back(izq);
  if (der != -1)
    g[cur].a.push_back(der);
  return cur++;
}

int dfs(int node, int sum) {
  if (g[node].a.size() == 0) {
    return sum == n;
  }

  for (int i = 0; i < g[node].a.size(); ++i)
    if (dfs(g[node].a[i], sum + g[g[node].a[i]].val))
      return 1;

  return 0;
}

int main() { ___

  while (cin>>n) {

    for (int i = 0; i < MN; ++i) {
      g[i].a.clear();
      g[i].val = 0;
    }
    cur = 0;
    string chunk;
    int open = 0;
    line = "";

    while (cin>>chunk) {
      for(int i = 0; i < chunk.size(); ++i) {
        if (chunk[i] == '(') open++;
        else if (chunk[i] == ')') open--;
      }
      line += chunk;
      if (open == 0) {
        int idx = parse(0);
        if (idx == -1) {
          cout<<"no"<<endl;
          break;
        }
        int ans = dfs(idx, g[idx].val);
        if (ans)
          cout<<"yes"<<endl;
        else
          cout<<"no"<<endl;
        break;
      }
    }

  }

  return 0;
}
