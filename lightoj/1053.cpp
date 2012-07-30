using namespace std;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

int dist(int a,int b){
	return sqrt(a*a + b*b);
}

int main(){
	int numcas;cin>>numcas;
	int cid=0,a,b,c;
	while(numcas--){
		cin>>a>>b>>c;
		cout<<"Case "<<++cid<<": ";
		if(dist(a,b)==c or dist(a,c)==b or dist(c,b)=a)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
}

