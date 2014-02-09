using namespace std;
#include<iostream>
#include<string>

int main(){
	string key, mess;
	while(true){
		cin>>key;
		if(key=="0")break;
		cin>>mess;
		int lk = key.size();
		int lm = mess.size();
		for(int i = 0; i< lm ; ++i)
			cout<< (char) ((mess[i]- 'A' + key[i%lk] - 'A' + 1)%26 + 'A');
		cout<<endl;	
	}

}
