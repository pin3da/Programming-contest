using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl

const int MN = 500;
int nums[MN * MN + 10];

char buff[100];

class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};


int main() {
  int n;scanf("%d", &n);
  int k = 0;
  int row;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%s", buff);
      if (buff[0] == '#') {
        row = i;
        continue;
      }
      nums[k++] = atoi(buff);
    }
  }

  int m = n*n + 10;
  FenwickTree tree(m);

  long long ans  = 0;
  int tope = n*n - 1;
  for (int i = 0; i < tope; ++i) {
    ans += tree.query(nums[i], m - 1);
    tree.add(nums[i], 1);
  }

  if (n & 1) {
    if (ans & 1)
     puts("unsolvable");
    else
      puts("solvable");
  } else {
    ans += row;
    if (ans & 1)
      puts("solvable");
    else
      puts("unsolvable");
  }
  return 0;
}
