using namespace std;
#include<bits/stdc++.h>


class ErasingCharacters {
	public:
	string simulate(string s) {
	    
	    int iid;
	    while((iid = test(s))!=-1){
	        string t;
	        for(int i = 0; i< s.size(); ++i){
	            if(i == iid or ((iid+1)==i))continue;
	            t.push_back(s[i]);
	        }
	        s = t;
	    }
	    
	    return s;
		
	}
	
	int test(string s){
	    for(int i = 0; i + 1< s.size(); ++i){
	        if(s[i] == s[i+1]) return i;
	    }
	    return -1;
	}
};
