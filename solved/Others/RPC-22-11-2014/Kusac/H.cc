using namespace std;
#include<bits/stdc++.h>


struct frac{
  int x, y;
  frac(){ y = 1;}
  frac(int a) :  x(a) , y(1) {}
  frac(int a, int b) :  x(a) , y(b) {
    int g = __gcd(x, y);
    x /= g;
    y /= g;
  }
  bool operator < (const frac & o) const {
    return x * o.y < o.x * y;
  }
  frac operator + (const frac & o) const {
    return frac(x * o.y + y * o.x, y * o.y);
  }
  frac operator - (const frac & o) const {
    return frac(x * o.y - y * o.x, y * o.y);
  }
};

int main() {

  int n, m, ans = 0;
  cin >> n >> m;
  
  if (n > m)
   n %= m;
  
  frac req(n, m);
    
  priority_queue<frac> q;
  
  for (int i = 0; i < n; ++i) {
    q.push(frac(1));
  }
  
  while (!q.empty()) {
    frac cur(0);
   
    while (cur < req) {
      cur = cur + q.top();
      q.pop();
    }
    
    if (frac(0) < cur - req ) {
      ans++;
      frac tmp = (cur - req);
      q.push(tmp);
    }
  } 
  cout << ans << endl;
  return 0;
}
