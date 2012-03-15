using namespace std;
#include<iostream>
#include<sstream>
#include<algorithm>

char dicc[]="PQWERTYUIOJ#SZK*?F@DIHNM&LXGABCV";

int main(){
	int numcas,tcid;
	cin>>numcas;
	long double base=0.0000152587890625;
	long double n1;
	while(numcas--){
		cin>>tcid;
		cin>>n1;
		stringstream ss;
		string cad;
		string cad2="00000000000000000";
		if(-1.0>n1 || n1>=1.0){
			cout<<tcid<<" INVALID VALUE"<<endl;
			continue;
		}
		if(n1<0)cad2[0]='1',n1+=1;
		int num= n1/base;
		while(num>0){
			ss<<(num&1);
			num>>=1;
		}
		ss>>cad;
		for(int i=1;i<18;i++){
			if(i!=17 && i-1<cad.size())
				cad2[17-i]=cad[i-1];
		}
		int pos=0;
		for(int i=0;i<5;i++)pos=((cad2[i]-'0')+pos*2);
		cout<<tcid<<" "<<dicc[pos];
		pos=0;
		for(int i=5;i<16;i++)pos=((cad2[i]-'0')+ pos*2);
		cout<<" "<<pos<<" ";
		if(cad2[16]=='1')
			cout<<"D";
		else
			cout<<"F";
		cout<<endl;
	}
	return 0;
}
