#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
typedef long long llong;
 
const int MAXN = 500020;
llong tree[MAXN], A[MAXN], B[MAXN];
 
llong read(int idx){
 llong sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
 
void update(int idx ,llong val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}
 
int main(int argc, char *argv[]) {
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      memset(tree, 0, sizeof(tree));     
      for(int i = 0; i < N; ++i) {
         scanf("%lld",&A[i]);
         B[i] = A[i];
      }
      sort(B, B + N);
      for(int i = 0; i < N; ++i) {
         int rank = int(lower_bound(B, B + N, A[i]) - B);
         A[i] = rank + 1;
      }
      llong inv_count = 0;
      for(int i = N - 1; i >= 0; --i) {
         llong x = read(A[i] - 1);
         inv_count += x;
         update(A[i], 1);
      }
      printf("%lld\n",inv_count/2);
   }
   return 0;
}
