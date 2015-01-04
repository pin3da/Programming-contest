using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int inf = 10000;


int left(long long a, long long b) {

  for (int i = 0; i < 32; ++i) {
    if (a == b) return i;
    long long tmp = (a >> 31) & 1;
    a = a << 1;
    a &= (1LL << 32) - 1;
    a |= tmp;
  }

  return inf;
}

int right(long long a, long long b) {
  for (int i = 0; i < 32; ++i) {
    if (a == b) return i;
    long long tmp = a & 1;
    a = a >> 1;
    a |= (tmp << 31);
    a &= (1LL << 32) - 1;
  }

  return inf;
}

long long next() {
  string line;
  cin >> line;
  long long ans = 0;
  for(int i = 0; i < line.size(); ++i) {
    ans *= 16;
    if (line[i] >= '0' and line[i] <=  '9') {
      ans += line[i] - '0';
    } else {
      line[i] = toupper(line[i]);
      ans += int(line[i] - 'A' + 10);
    }
  }
  return ans;
}

void solve() {
  long long a, b;

  a = next();
  b = next();

  string ans = "Not possible";
  int best = left(a, b);
  if (best != inf) {
    ans = "Left";
  }
  int other = right(a, b);
  if (other != inf) {
    if (other == best)
      ans = "Any";
    else if (other < best) {
      ans = "Right";
      best = other;
    }
  }
  if (best != inf)
    cout << best << " ";
  cout << ans << endl;


}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
