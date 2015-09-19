#include <bits/stdc++.h>
#define LSOne(x) ((x) & (-(x)))
using namespace std;

const int MN = 1000010;
int neg[MN], zero[MN];

int n, k;
int rsq(int ft[], int b) {
  int sum = 0;
  for(; b > 0; b -= LSOne(b))
    sum += ft[b];
  return sum;
}

int rsq(int ft[], int a, int b) {
  return rsq(ft, b) - (a == 1 ? 0 : rsq(ft, a - 1));
}

void update(int ft[], int k, int v) {
  for (; k < MN; k += LSOne(k))
    ft[k] += v;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  while (cin >> n >> k) {
    memset(neg, 0, sizeof neg);
    memset(zero, 0, sizeof zero);

    int x[n + 1]; x[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
      if (x[i] < 0)
      	update(neg, i, 1);
      if (x[i] == 0) 
	update(zero, i, 1);
    }

    string ans = "", cmd;
    while (k--) {
      cin >> cmd;
      if (cmd == "P") {
	int a, b;
	cin >> a >> b;
	
	int n_zeros = rsq(zero, a, b);
	int n_neg = rsq(neg, a, b);
	
	if (n_zeros > 0)
	  ans.push_back('0');
	else if (n_neg & 1)
	  ans.push_back('-');
	else
	  ans.push_back('+');
      } else if (cmd == "C") {
	int i, v;
	cin >> i >> v;
	if (v < 0) {
	  if (x[i] >= 0) // Neg replaces anything, neg +1
	    update(neg, i, 1);
	  if (x[i] == 0) // Neg replaces zero, zero -1
	    update(zero, i, -1);
	} else if (v == 0) {
	  if (x[i] != 0) // Zero replaces anything non-zero, zero +1
	    update(zero, i, 1);
	  if (x[i] < 0) // Zero replacez neg, neg -1
	    update(neg, i, -1);
	} else {
	  if (x[i] < 0) // Positive replaces neg, nec -1
	    update(neg, i, -1);
	  if (x[i] == 0) // Positive replaces zero, zero -1
	    update(zero, i, -1);
	}
	x[i] = v;
      }
    }

    cout << ans << endl;
  }
  
  return 0;
}
