using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int mod = 1e9 + 7;
int r, g, H;


int ho(int h, int red) {
  int blocks = r +  g - (( h * (h - 1) ) >> 1);
  int green = blocks - red;

  D(h);
  D(green);
  D(red);

  if (red < h and green < h) {
    return h;
  }

  int ans = 0;
  if (red >= h)
    ans = max(ans, ho(h + 1, red - h));
  if (green >= h)
    ans = max(ans, ho(h + 1, red));

  return H = ans;

}

int go(int h, int red) {

  if (h == H + 1) return 1;
  // int green = r + g - red;
  int blocks = r +  g - (( h * (h - 1) ) >> 1);
  int green = blocks - red;
  int ans = 0;
  if (red >= h)
    ans = ( ans + go(h + 1, red - h)) % mod;
  if (green >= h)
    ans = (ans + go(h + 1, red)) % mod;
  return ans;
}

int main() {
  cin >> r >> g;

  int sq = sqrt(r + g) + 1;

  int ans = 0;
  //for (H = 1; H <= sq; ++H) {
  ho(1, r);
  D(H);
  ans = go(1, r);
  cout << ans << endl;

  return 0;
}
