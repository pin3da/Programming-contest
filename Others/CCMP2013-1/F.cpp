using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#define For(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()
#define D(x) cout<<#x " = "<<(x)<<endl

string solve(string a, string b){
	int hasta = min(a.size(),b.size());
	string ans = "";	
	for (int i = 0; i < hasta; i++) {
		if(a[i] != b[i])
			break;
		ans+=a[i];
	}
	int pos = ans.size();
	if(pos == a.size()) return a;
	
	if(pos == a.size()-1){
		return ans+a[pos];
	}else{
		if(a[pos] == b[pos]-1){
			if(pos < b.size() -1){
				return ans+b[pos];
			}
			ans+=a[pos++];
			while(pos<a.size() && a[pos]=='Z')
				ans+=a[pos++];
			if(pos == a.size() -1){
				return ans+a[pos];
			}
			if(pos >= a.size())
				return ans;
			return ans+ ((char)(a[pos]+1));
		}else{
			ans+=(char)(a[pos]+1);
		}
	}
	
	return ans;
}


int main(){
	int n;
	while(cin>>n and n!=0){
		vector<string> todos(n);
		For(i,n)cin>>todos[i];
		sort(all(todos));
		int medio = n>>1;
		cout<<solve(todos[medio-1],todos[medio])<<endl;
	}
	return 0;
}
