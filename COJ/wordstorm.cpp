using namespace std;
#include<iostream>
#include<string>
#include<cstring>

int main(){
    string w;
    int n;
    int frec[26];
    while(cin>>w){
    	cin>>n;
    	string cad;
    	while(n--){
    	    cin>>cad;
    	    cout<<cad<<" is ";
    	    if(cad.size()>3 and cad.find(w[4])!=string::npos){
    	        int pin = 1;
    	        memset(frec,0,sizeof(frec));
    	        for(int i=0;i<w.size();++i)
    	            frec[w[i]-'A']++;
    	        for(int i=0;i<cad.size();++i){
    	            frec[cad[i]-'A']--;
    	            if(frec[cad[i]-'A'] < 0){
    	                pin = 0;
    	                break;
    	            }
    	        
    	        }
    	        cout<<((pin)?"valid":"invalid")<<endl;
    	    }else{
    	        cout<<"invalid"<<endl;
    	    }
    	}
    }
    return 0;
}
