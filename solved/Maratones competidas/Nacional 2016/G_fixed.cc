#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl;
#define endl '\n'

const int BS = 1024;
const int T = BS - 1;

bool b[BS][BS];
bool p[BS]; // pending
bool zero[BS], one[BS];

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

int comp_top(int id) {
  if (id + 1 == last) {
    int ans = tot_len & T;
    if (ans == 0) return BS;
    return ans;
  }
  return BS;
}

int find_right(int id) {
  if (id >= tot_len) return -1;
  int bucket = id / BS;
  int end = (bucket + 1) * BS;
  if (p[bucket]) {
    if (zero[bucket]) {
      for (int i = id; i < end && i < tot_len; ++i) {
        int j = i & T;
        if (b[bucket][j] == 0) return i;
      }
    }
    return find_right((bucket + 1) * BS);
  } else {
    if (one[bucket]) {
      for (int i = id; i < end && i < tot_len; ++i) {
        int j = i & T;
        if (b[bucket][j] == 1) return i;
      }
    }
    return find_right((bucket + 1) * BS);
  }
  return -1;
}

int find_left(int id) {
  if (id < 0) return -1;
  int bucket = id / BS;
  int start = bucket * BS;
  if (p[bucket]) {
    if (zero[bucket]) {
      for (int i = id; i >= start; --i) {
        int j = i & T;
        if (b[bucket][j] == 0) return i;
      }
    }
    return find_left(bucket * BS - 1);
  } else {
    if (one[bucket]) {
      for (int i = id; i >= start; --i) {
        int j = i & T;
        if (b[bucket][j] == 1) return i;
      }
    }
    return find_left(bucket * BS - 1);
  }
  return -1;
}

int get(int id) {
  int x = id / BS;
  int y = id & T;
  return b[x][y] ^ p[x];
}

void fix(int bucket) {
  if (!p[bucket]) return;
  int top = comp_top(bucket);
  zero[bucket] = 0;
  one[bucket] = 0;
  for (int i = 0; i < top; ++i) {
    b[bucket][i] ^= 1;
    if (b[bucket][i]) one[bucket] = true;
    else zero[bucket] = true;
  }
  p[bucket] = 0;
}

void flip(int bucket, int from, int to) {
  zero[bucket] = 0;
  one[bucket] = 0;
  for (int i = from; i <= to; ++i) {
    b[bucket][i] ^= 1;
  }
  int top = comp_top(bucket);
  for (int i = 0; i < top; ++i)
    if (b[bucket][i]) one[bucket] = true;
    else zero[bucket] = true;
}

deque<int> printb() {
  deque<int> q;
  for (int i = 0; i < last; ++i) {
    int top = comp_top(i);;
    for (int j = 0; j < top; ++j) {
      q.push_back(b[i][j]);
    }
  }
  return q;
}

void dbg() {
  for (int i = 0; i < last; ++i) {
    int top = comp_top(i);
    if (i) cout << " | ";
    for (int j = 0; j < top; ++j)
      cout << b[i][j] << ' ';
  }
  cout << endl;
  for (int i = 0; i < last; ++i)
    cout << p[i] << ' ';
  cout << endl;
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
    last = (k + BS - 1) / BS;
    for (int i = 0; i < last; ++i) {
      for (int j = 0; j < BS; ++j) b[i][j] = 0;
      p[i] = false;
      zero[i] = true;
    }

    int offset = k - line.size() * 4;
    tot_len = k;
    for (size_t i = 0; i < line.size(); ++i) {
      vector<int> t = get_bits(line[i]);
      for (size_t j = 0; j < t.size(); ++j) {
        if (offset >= 0) {
          int x = offset / BS;
          int y = offset & T;
          b[x][y] = t[j];
          if (t[j]) one[x] = true;
          else zero[x] = true;
        }
        offset++;
      }
    }
    // dbg();
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
      int xl = a / BS, xr = b / BS;
      for (int j = xl + 1; j < xr; ++j) p[j] ^= 1;
      if (xl == xr) {
        fix(xl);
        flip(xl, a & T, b & T);
      } else {
        fix(xl);
        fix(xr);
        flip(xl, a & T, BS - 1);
        flip(xr, 0, b & T);
      }
      // dbg();
    }

    for (int i = 0; i < last; ++i) fix(i);
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
    if (res.size() == 0) res.push_front('0');
    while (res.size() > 1 && res.front() == '0') res.pop_front();
    for (size_t i = 0; i < res.size(); ++i)
      cout << res[i];
    cout << endl;
  }
  return 0;
}
