#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> num;
#define tope 1000000000

bool isSuperLucky(ll x){
	int s = 0, c = 0;
	while(x){
		s += (x%10 == 7);
		c += (x%10 == 4);
		x /= 10;
	}
	return s==c;
}

void genLuckyNumbers(ll currLucky){
	
	if(isSuperLucky(currLucky))
		num.push_back(currLucky);
	
	if(currLucky > tope) return;
	
	ll tmp = currLucky * 10 + 7;
	genLuckyNumbers(tmp);
	tmp = currLucky * 10 + 4;
	genLuckyNumbers(tmp);

}

int main(){
	ll x;
	
	genLuckyNumbers(0);
	sort(num.begin(), num.end());
	
	while( cin >> x){
		auto lucky = lower_bound(num.begin(), num.end(), x);
		cout << *lucky << endl;
	}
}
