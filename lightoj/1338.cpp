using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>

int main(){
	int numcas;scanf("%d\n",&numcas);
	int cas=0;
	string n;
	while(numcas--){
		getline(cin,n);
		int vec[27];
		for(int i=0;i<27;++i)vec[i]=0;
		stringstream ss(n);
		string t;
		while(ss>>t){
			for(int i=0;i<t.size();++i)
				vec[tolower(t[i])-'a']++;
		}
		getline(cin,n);
		stringstream ss1(n);
		while(ss1>>t){
			for(int i=0;i<t.size();++i)
				vec[tolower(t[i])-'a']--;
		}
		int p=1;
		for(int i=0;i<27;++i)
			if(vec[i]!=0){p=0;break;}
		cout<<"Case "<<++cas<<": "<<((p)?"Yes":"No")<<endl;
	}
	return 0;
}
