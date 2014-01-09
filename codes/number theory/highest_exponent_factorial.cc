/**
 * Returns the highest exponent of a prime p dividing n!.
 * reference: http://math.stackexchange.com/questions/141196/highest-power-of-a-prime-p-dividing-n
 * */

int highest_exponent(int p, const int &n){
  int ans = 0;
  int t = p;
  while(t <= n){
    ans += n/t;
    t*=p;
  }
  return ans;
}
