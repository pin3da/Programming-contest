// http://codeforces.com/contest/219/problem/A

using namespace std;
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define all(x) x.begin(),x.end()

int main(){
	int k;cin>>k;
	string cad;cin>>cad;
	int ocu[26];
	memset(ocu,0,sizeof(ocu));
	for(int i=0;i<cad.size();++i)
		ocu[cad[i]-'a']++;
	for(int i=0; i<26 ; ++i){
		//cout<<(char)('a'+i)<<"  "<<ocu[i]<<endl;
		if(ocu[i]%k!=0){
			cout<<-1<<endl;
			return 0;
		}else
			ocu[i]/=k;
	}
	for(int i=0;i<k;++i)
		for(int j=0;j<26;++j)
			for(int k=0;k<ocu[j];++k)
				cout<<(char)(j+'a');
			
	cout<<endl;
}

