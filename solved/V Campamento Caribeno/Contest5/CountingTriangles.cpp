using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl


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
};


int n, sn;

const int MN = 1100009;

vector<pair<int,int> > x;
//set<pair<int,int> > HT[MN];
vector<pair<int, int> > HT[MN];
//int HT[MN];
vector<int> points[MN];

const int pri = 2503 ;

int hs(int xx, int yy) {
  return ((pri + xx)  * pri  + yy) % MN;
}

bool busca(int xx, int yy) {
  if (xx < 0 or xx > 100000 or yy < 0 or yy > 100000 )
    return 0;
  int h = hs(xx,yy);
  if (HT[h].size() == 0) return 0;
  for (int i = 0; i < HT[h].size(); ++i) {
    if (HT[h][i].first == xx and HT[h][i].second == yy ) return true;
  }
  return false;
  //return HT[h].count(make_pair(xx,yy)) == 1;
  //return HT[h] >= 1;
}

int main() {

  Reader rd;

  n = rd.next_int();
  sn = sqrt(n);
  int a,b;
  for (int i = 0 ; i < n; ++i) {
    a = rd.next_int();
    b = rd.next_int();
    x.push_back(make_pair(a,b));
    //HT[hs(a,b)]++;
    //HT[hs(a,b)].insert(make_pair(a,b));
    HT[hs(a,b)].push_back(make_pair(a,b));
  }

  sort(x.begin(), x.end());
  vector<int> base;

  for (int i = 0; i < n; ++i) {
    points[x[i].first].push_back(x[i].second);

    if (i == 0 or x[i].first != base.back()) {
      base.push_back(x[i].first);
    }
  }

  long long ans = 0;

  for (int i = 0 ; i < base.size(); i++) {
    vector<int>  &p  = points[base[i]];
    const int &pos = base[i];
    if (p.size() < sn) {
      for (int j = 0; j < p.size(); ++j) {
        for (int k = j + 1; k < p.size(); ++k) {
          int dy = fabs(p[j] - p[k]);
          int nx = pos + dy;
          int ny = p[j];
          if (busca(nx, ny)) ans++;

          nx = pos - dy;
          if (nx >= 0)
            if (busca(nx, ny)) ans++;

          nx = pos + dy;
          ny =  p[k];
          if (busca( nx, ny)) ans++;

          nx = pos - dy;
          if (nx >= 0)
            if (busca(nx, ny)) ans++;

        }
      }
    } else {
      for (int k  = 0; k < base.size(); ++k) {
        const int &ox = base[k];
        if (ox == pos) continue;
        vector<int> &ny = points[base[k]];
        int dx = fabs(ox - pos);
        for (int kk = 0 ; kk < ny.size(); ++kk) {
          if (busca(pos , ny[kk])) {
            if (busca( pos, (ny[kk] + dx))) ans++;
            if (busca( pos, (ny[kk] - dx))) ans++;
          }
        }
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
