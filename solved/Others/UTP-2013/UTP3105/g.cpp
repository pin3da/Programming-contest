/*
Manuel Pineda,

Fuerza bruta.
*/

using namespace std;
#include<iostream>
#include<string>

#define For(i,n) for(int i = 0; i < n; ++i)
#define DBG if(0)

int main(){
	int sk;
	string m1,m2,c;
	int cas=0;
	while(true){
		cin>>sk;
		if(!sk)break;
DBG		cout<<"case "<<++cas<<endl;
DBG		cout<<sk<<endl;
		cin>>m1>>m2>>c;
		int pin = 1;
		string ans;
		int mio = (c.size() < sk )?c.size():c.size() - sk +1;
		for(int i=0 ; i< mio;++i){
			//for here to all possibles keys
			for(int p=sk;p>1;--p){
				string k;
				for(int j=0; j<p ; ++j){
					k += ((c[i+j] - m1[j] - 1) < 0) ? (c[i+j] - m1[j]  + 'Z'): (c[i+j] - m1[j] -1 + 'A');
				}
				string cad;
				for(int i=0 ; i<c.size(); i+=p)
					for(int j =0; j< k.size() && i + j < c.size(); ++j)	
						cad += ((c[i+j] - k[j] -1 ) < 0) ? (c[i+j] - k[j]  + 'Z'): (c[i+j] - k[j] -1 + 'A');	
				if(cad.find(m2)!=string::npos){
					pin= (pin != 1)? (pin==0)?2:0:0;
					ans = cad;
				}
			}
		}
		if(pin==1)cout<<"impossible"<<endl;
		else if(pin == 2)cout<<"ambiguous"<<endl;
		else cout<<ans<<endl;
		
	}
	return 0;
}
