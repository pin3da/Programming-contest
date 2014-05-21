using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x) << endl

const int MN = 1000001;

vector<int> sieve[MN];
int totient[MN];
int divs[MN];

void manuel() {
  int count = 0;
  for (int i = 2; i < MN; ++i)
    if (sieve[i].size() == 0)
      for (int j = i; j < MN; j+=i)
        sieve[j].push_back(i);
}

int getnum(int mio, int mask, int tope) {
  int act = 1;
  int pos = 0;
  while (mask) {
    if (mask & 1) act *= sieve[mio][pos];
    pos++;
    mask >>= 1;
  }
  return act;
}
int pop_count(int mask) {
  int ans = 0;
  while(mask) {
    if (mask & 1) ans++;
    mask>>=1;
  }
  return ans;
}

int main() {

  manuel();
  int n,m;

  scanf("%d", &m);
  vector<int> nums(m);
  for (int i = 0; i < m; ++i){
    scanf("%d", &nums[i]);
  }

  int tope = 1<<sieve[nums[nums.size() - 1]].size();
  int mio = nums[nums.size() - 1];
  for (int mask = 1; mask < tope; ++mask) {
    int act = getnum(mio,mask, tope);
    divs[act]++;
  }

  long long ans = 0;
  for (int i = nums.size() - 2; i >= 0; --i) {
    int tope = 1<<sieve[nums[i]].size();
    int cuenta = 0;
    for (int mask = 1; mask < tope; ++mask) {
      int act = getnum(nums[i], mask, tope);
      //assert(act <= 1000000);
      int pari = pop_count(mask);
      if ((pari & 1)) cuenta += divs[act];
      else  cuenta -= divs[act];
    }

    for (int mask = 1; mask < tope; ++mask) {
      int act = getnum(nums[i], mask, tope);
      divs[act]++;
    }

    ans += (nums.size() - i - 1) - cuenta;
  }
  printf("%lld\n", ans);
  return 0;
}
