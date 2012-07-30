using namespace std;
#include<iostream>
#include<string>

int main(){
	int numcas;cin>>numcas;
	int cas=0;
	string n;
	while(numcas--){
		cin>>n;
		int p=1;
		int sz = n.size();
		for(int i =0; i<=(sz/2)+1;++i)
			if(n[i]!=n[sz - 1-i]){
				p=0;break;
			}
		cout<<"Case "<<++cas<<": "<<((p)?"Yes":"No")<<endl;
	}
	return 0;
}

