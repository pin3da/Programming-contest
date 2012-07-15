using namespace std;
#include<iostream>
#include<string>
#include<algorithm>

const string mio = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	int t;cin>>t;
	int n,k,cas=0;
	while(t--){
		cin>>n>>k;
		string ord = mio.substr(0,n);
		k--;
		cout<<"Case "<<++cas<<":"<<endl;
		do{
			cout<<ord<<endl;
		}while(next_permutation(ord.begin(),ord.end()) && k--);
	}
	return 0;
}
