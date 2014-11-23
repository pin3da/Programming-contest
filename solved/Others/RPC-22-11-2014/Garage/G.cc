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

  int a, b, c, d;
  
  cin >> a >> b >> c >> d;
  
  int cc = 2 * c;
  int dd = 2 * d;
  
  int m1 = a % cc;
  int m2 = b % dd;
  
  int w = (a / cc) + (m1 >= c ? 1 : 0); 
  int h = (b / dd) + (m2 >= d ? 1 : 0);
  
  cout <<  w * h << endl;
  
  return 0;
}
