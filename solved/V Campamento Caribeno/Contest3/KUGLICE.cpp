using namespace std;
#include<bits/stdc++.h>

const int MN = 300003;
int n;
int out[MN];
int p[MN], vis[MN];

struct Reader {
    int b; Reader() { read(); }
    void read() { b = getchar_unlocked(); }
    void skip() { while (0 <= b && b <= 32) read(); }

    unsigned int next_u32() {
        unsigned int v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
    int next_int() {
        int v = 0; bool s = false;
        skip(); if (b == '-') { s = true; read(); }
        for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
    char next_char() { skip(); char c = b; read(); return c; }
    void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }

    bool has_next() { skip(); return b > 0; }
    bool has_next_u32() { skip(); return 48 <= b && b <= 57; }
    bool has_next_int() { skip(); return b == 45 || (48 <= b && b <= 57); }

    void skip_line() {
        for (; b != 10 && b != 13 && b >= 0; read());
        char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
    void next_line(char *s) {
        for (; b != 10 && b != 13 && b >= 0; read()) *s++ = b; *s = 0;
        while (b == 10 || b == 13) read(); }
    void next_real_line(char *s, int &l) {
        for (l = 0; b != 10 && b != 13 && b >= 0; read()) *s++ = b, ++l;
        *s = 0; char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
};

int find_set(int node) {
  int mm = 0;
  while (p[node] != -1) { // root
    if (p[node] == node) {
      for (int i = 0; i < mm; ++i)
        p[vis[i]] = node;
      return -1;
    }
    vis[mm++] = node;
    node = p[node];
  }
  for (int i = 0; i < mm; ++i)
        p[vis[i]] = node;

  return node;
}


void joint(int a, int b) {
  if (find_set(a) == -1) p[b] = p[a];
  if (find_set(b) != -1)
    p[find_set(b)] = find_set(a);
}

int main () {

  memset(out, 0, sizeof out);

  Reader rd;
  n = rd.next_int();
  for (int i = 0 ; i<  n; ++i) out[i+1] = rd.next_int();
  int q = rd.next_int();
  stack<pair<int,int> > st;
  int u,v;
  vector<int> visited(MN, 0);
  while (q--) {
    u = rd.next_int();
    v = rd.next_int();
    st.push(make_pair(u,v));
    if (u == 2) visited[v] = 1;
  }

  memset(p, -1, sizeof p);

  for (int i = 1; i < n+1; ++i)
    if (!visited[i] and out[i]) joint(out[i],i);

  stack<int> ans;

  while(!st.empty()) {
    int op = st.top().first;
    int node = st.top().second;st.pop();
    if (op == 1) {
        ans.push(find_set(node));
    } else {
      joint(out[node], node);
    }
  }
  while (!ans.empty()) {
    if (ans.top() == -1)
      printf("CIKLUS\n");
    else
      printf("%d\n", ans.top());
    ans.pop();
  }

  return 0;
}
