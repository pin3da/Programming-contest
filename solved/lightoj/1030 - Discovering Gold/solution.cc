#include <cstdio>
#include <iostream>
#include <algorithm>

#define rep(i,N) for (int i=0; i<(N); i++)

using namespace std;

double expected[150];
double r[150];
int N;

void fill() {
  expected[N-1] = r[N-1];
  for (int i=N-2; i>=0; i--) {
    expected[i]=r[i];
    int tope = min(6,N-i-1);
    for (int j=1; j<=tope; j++) {
      expected[i] += (1.0/tope)*expected[i+j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int c=0; c<tc; c++) {
    cin >> N;
    rep(i,N) cin >> r[i];
    fill();
    printf("Case %d: %.8lf\n",c+1,expected[0]);
  }
}
