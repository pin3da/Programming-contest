#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl;
#define endl '\n'

const int MN = 1234567;

bool b[MN];

vector<int> get_bits(char a) {
  vector<int> ans(4);
  int tmp;
  if (isdigit(a))  tmp = a - '0';
  else  tmp = a - 'A' + 10;
  for (int i = 0; i < 4; ++i) {
    ans[3 - i] = (tmp & 1);
    tmp >>= 1;
  }
  return ans;
}

int last;
int tot_len;
int BS;

int find_right(int id) {
  for (int i = id; i < tot_len; ++i)
    if (b[i] == 1) return i;
  return -1;
}

int find_left(int id) {
  for (int i = id; i >= 0; --i)
    if (b[i] == 1) return i;
  return -1;
}

int get(int id) {
  return b[id];
}


void flip(int from, int to) {
  for (int i = from; i <= to; ++i)
    b[i] ^= 1;
}

deque<int> printb() {
  deque<int> q;
  for (int i = 0; i < tot_len; ++i) {
    q.push_back(b[i]);
  }
  return q;
}


char get_char(int a) {
  if (a < 10) return a + '0';
  a -= 10;
  return a + 'A';
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int k, m; cin >> k >> m;
    string line;
    cin >> line;
    memset(b, 0, sizeof b);

    int offset = k - line.size() * 4;
    tot_len = k;
    for (size_t i = 0; i < line.size(); ++i) {
      vector<int> t = get_bits(line[i]);
      for (size_t j = 0; j < t.size(); ++j) {
        if (offset >= 0) {
          b[offset] = t[j];
        }
        offset++;
      }
    }
    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b;
      a--; b--;
      if (get(a) == 0) {
        int l = find_left(a);
        if (l >= 0) a = l;
      }
      if (get(b) == 0) {
        int r = find_right(b);
        if (r >= 0 && r < tot_len) b = r;
      }
      flip(a, b);
    }

    deque<int> ans = printb();
    while (ans.size() % 4) ans.push_front(0);
    deque<char> res;
    for (size_t i = 0; i < ans.size(); i += 4) {
      int tmp = 0;
      for (int j = 0; j < 4; ++j) {
        tmp <<= 1;
        tmp |= ans[i + j];
      }
      res.push_back(get_char(tmp));
    }
    while (res.size() > 1 && res.front() == '0') res.pop_front();
    for (size_t i = 0; i < res.size(); ++i)
      cout << res[i];
    cout << endl;
  }
  return 0;
}
