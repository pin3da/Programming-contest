using namespace std;
#include<iostream>

int main(){
	int numcas;cin>>numcas;
	for(int i=1; i<=numcas ; ++i){
		int moves;cin>>moves;
		string name;cin>>name;
		cout<<"Case "<<i<<": ";
		if(name=="Alice" and (moves-1)%3==0)cout<<"Bob"<<endl;
		else if(name=="Alice")cout<<"Alice"<<endl;
		else if(name=="Bob" and moves%3==0)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
		
	}

}
