#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll ans;

void solve(vector<ll> &v,int mask){
	if(v.size() == 7){
		ans = min(ans, v[6]);
		return;
	}
	
	for(int i = 0; i < v.size(); i++){
		if((mask & (1 << i)) != 0) continue;
		for(int j = 0; j < v.size(); j++){
			if(i == j) continue;
			if((mask & (1 << j)) == 0){
				vector<ll> aux = v;
				int idx = aux.size()- 4;

				if(s[idx] == '*'){
					aux.push_back(v[i] * v[j]);
					
				}else{
					aux.push_back(v[i] + v[j]);
				}
				int maskt = mask;
				maskt |= 1<<i;
				maskt |= 1<<j;
				solve(aux,maskt);
			} 
		}
	}
	
}


int main(){
	ll x;
    vector<ll> v(4);
    for(int i = 0; i < 4; i++){ cin >> v[i];}
    string c; 
    for(int i = 0; i < 3; i++){ cin >> c; s += c;}
	
	ans = 10000000000000;
	solve(v,0);

	cout << ans << endl;

}




