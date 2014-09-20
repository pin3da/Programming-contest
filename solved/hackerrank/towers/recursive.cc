using namespace std;
#include<bits/stdc++.h>

const int MN = 15;
int sizes[MN];
int k;

long long go(int n) {
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;
  long long ans = 0;
  for (int i = 0; i < k; ++i)
    ans += go(n - sizes[i]);
  return ans;
}

int main() {

  long long n;
  cin >> n >> k;
  for (int i = 0; i < k; ++i)
    cin >> sizes[i];

  for (int i = 0; i <= n; ++i) {
    cout << i << " ";
    cout << go(i) << endl;
  }

  return 0;
}
