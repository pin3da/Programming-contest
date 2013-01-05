/**
* Not solved yet
*/

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<limits>


#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
template <class T> string toStr(const T &x){ stringstream s; s << x; return s.str(); }


typedef long long int lli;

lli gcd (lli a, lli b) {
  lli tmp;
  while (b) {
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }
  return a;
}

// a % b (valor positivo)
lli mod (lli a, lli b) {
  return ((a % b) + b) % b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
lli extended_euclid (lli a, lli b, lli &x, lli &y) {
  lli xx = y = 0;
  lli yy = x = 1;
  while (b) {
    lli q = a / b;
    lli t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}


lli lcm (lli a, lli b) {
  return a / gcd (a, b) * b;
}

// finds all solutions to ax = b (mod n)
lli modular_linear_equation_solver (lli a, lli b, lli n) {
  lli x, y;
  lli d = extended_euclid (a, n, x, y);
  if (!(b % d)) {
    x = mod (x * (b / d), n);
    //for (lli i = 0; i < d; i++)
      return (mod (x  * (n / d), n));
  }
  return -1;
}


int main(){
  int a,b;cin>>a>>b;
  vector<lli> nums(a);
  lli min = numeric_limits<int>::max();
  int pos;
  For(i,a){
    cin>>nums[i];
    if(nums[i]<min){
      pos=i;
      min=nums[i];
    }
  }
  pos++;
  int desp;
  if(pos == b ) desp=0;
  else if(pos < b) desp = b-pos;
  else desp = a - (pos - b);
//  D(desp);
//  lli mio = modular_linear_equation_solver(1,b,desp);
//  D(mio);
  lli mio = desp + min*a;
//  D(mio);

  for(int i=pos+1; i-pos <= desp + min==0?0:a;++i){
    nums[((i-1)%a)]-= max(min,1LL);
  }
  nums[pos-1]=mio;
  For(i,a)cout<<nums[i]<<" ";
  cout<<endl;
	return 0;
}
