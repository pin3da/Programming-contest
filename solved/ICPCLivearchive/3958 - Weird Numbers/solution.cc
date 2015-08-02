using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long eval(const deque<int> &s, int base) {
  long long ans = 0;
  base *= -1;
  for (int i = 0; i < s.size(); ++i) {
    ans *= base;
    ans += s[i];
  }
  return ans;
}

deque<int> conv(long long val, int base) {
  base *= -1;
  deque<int> ans;
  while (val != 0) {
    int q = val / base;
    int r = val % base;
    if (r < 0) {
      q++;
      r -= base;
    }
    ans.push_front(r);
    val = q;
  }
  while (ans.size() > 0 && ans.front() == 0) ans.pop_front();
  if (ans.size() == 0) ans.push_back(0);
  return ans;
}

int main() {
  //ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line and line != "end") {
    stringstream ss(line);
    getline(ss, line, '-');
    if (line == "from") {
      getline(ss, line);
      int base = atoi(line.c_str());
      string num; cin  >> num;
      deque<int>  t;
      for (int i = 0; i < num.size(); ++i) {
        t.push_back(num[i] - '0');
      }
      cout << eval(t, base) << endl;
    } else {
      getline(ss, line);
      int base = atoi(line.c_str());
      string num; cin >> num;
      deque<int> ans = conv(atoi(num.c_str()), base);
      for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
      }
      cout << endl;
    }
  }


  return 0;
}

