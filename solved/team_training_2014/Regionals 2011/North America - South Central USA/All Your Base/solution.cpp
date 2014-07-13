using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout<< #x " = "<<(x)<<endl


typedef deque<int> num;

num sum(const num &a, const num &b) {
  num ans;
  int mmin = min(a.size(), b.size());
  ans.push_back(0);
  for (int i = 0; i < mmin; ++i) {
    int base = i + 2;
    ans[i] += a[i] + b[i];
    ans.push_back(ans[i] / base);
    ans[i] %= base;
  }
  if (a.size() > b.size()) {
    for (int i = mmin; i < a.size(); ++i) {
      int base = i + 2;
      ans[i] += a[i];
      ans.push_back(ans[i] / base);
      ans[i] %= base;
    }
  } else if (b.size() > a.size()) {
    for (int i = mmin; i < b.size(); ++i) {
      int base = i + 2;
      ans[i] += b[i];
      ans.push_back(ans[i] / base);
      ans[i] %= base;
    }
  }
  while ((ans.size() > 1) and ans.back() == 0) ans.pop_back();
  return ans;
}

int cmp(const num &a, const num &b) {
  if (a.size() > b.size()) return 1;
  if (a.size() < b.size()) return -1;

  int i = 0;
  while (i < a.size()) {
    if (a[i] != b[i])
      return a[i] < b[i];
    ++i;
  }
  if (i == a.size()) return 0;
}

void dbg(num aa) {
  cout<<"== debug"<<endl;
  for (int i = 0; i < aa.size(); ++i)
    cout<<aa[i]<<" ";
  cout<<endl;
}

num sub(num a, num b) {  // a must be greater than b

  while (b.size() < a.size()) b.push_back(0);
  num ans;
  ans.push_back(0);

  for (int i = 0; i < b.size(); ++i) {
    int base = i + 2;
    while (a[i] < b[i]) {
      a[i + 1]--;
      a[i] += base;
    }
    ans[i] = a[i] - b[i];
    ans.push_back(0);
  }
  while ((ans.size() > 1) and ans.back() == 0) ans.pop_back();
  return ans;
}

int get_num(char c) {
  if (c >= '0' and c <= '9')
    return c - '0';
  return c - 'A' + 10;
}

int check(num a) {
  if (a.size() > 35) return 0;
  for (int i = 0; i < a.size(); ++i)
    if ((a[i] < 0) or (a[i] > (i + 1)))
      return 0;
  return 1;
}


void solve() {
  string a, b, op;
  cin>>a>>op>>b;

  int sa = (a[0] == '-');
  int sb = (b[0] == '-');


  num aa;
  for (int i = a.size() - 1; i >= 0 and (a[i] != '-'); --i)
    aa.push_back(get_num(a[i]));


  num bb;
  for (int i = b.size() - 1; i >= 0 and (b[i] != '-'); --i)
    bb.push_back(get_num(b[i]));

  if ( (!check(aa)) or (!check(bb)) ) {
    cout<<"Invalid"<<endl;
    return;
  }


  num ans;


  int h = 0;
  if (op == "+") {
    if (sa and sb)  {
      ans = sum(aa,bb);
      h = true ; //cout<<"-";
    } else if (sa or sb) {
      if (cmp(aa, bb) == 1) {
        ans = sub(aa,bb);
        if (sa)
          h = true ; //cout<<"-";
      } else if (cmp(aa,bb) == -1) {
        ans = sub(bb, aa);
        if (sb)
          h = true ; //cout<<"-";
      } else {
        ans.push_back(0);
      }
    } else {
      ans = sum(aa, bb);
    }
  } else {
    if (sa and sb) {
      if (cmp(aa, bb) == 1) {
        h = true ; //cout<<"-";
        ans = sub(aa,bb);
      } else if (cmp(aa, bb) == -1) {
        ans = sub(bb, aa);
      } else {
        ans.push_back(0);
      }
    } else if (sa or sb) {
      if (sa) {
        h = true ; //cout<<"-";
        ans = sum(aa, bb);
      } else {
        ans = sum(aa, bb);
      }
    } else {
      if (cmp(aa, bb) == 1) {
        ans = sub(aa, bb);
      } else if (cmp(aa, bb) == -1) {
        h = true ; //cout<<"-";
        ans = sub(bb, aa);
      } else {
        ans.push_back(0);
      }
    }
  }

  if (!check(ans)) {
    cout<<"Invalid"<<endl;
    return;
  }

  if (h) cout<<"-";
  for (int i = ans.size() - 1; i >= 0; --i) {
    char c = (ans[i] < 10) ? (ans[i] + '0') : (ans[i] + 'A' - 10);
    cout<<c;
  }
  cout<<endl;

}

int main() { ___

  int tc;cin>>tc;
  for (int i = 0; i < tc; ++i)
    solve();

  return 0;
}
