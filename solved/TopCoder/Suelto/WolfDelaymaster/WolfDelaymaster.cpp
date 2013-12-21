using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl


class WolfDelaymaster {
    public:
    
    int count(string &s, int pos){
        int ans = pos;
        while(ans < s.size() and s[ans]=='w')
            ans++;
        return ans-pos;
    }
    
    int get(string &s, int pos,int h, char c){
        if(pos + h > s.size()) return 0;
        for(int i = pos; i < (pos + h); ++i){
            if(s[i]!=c)return 0;
        }
        return 1;
    }
    //wolfwwoollffwwwooolllfffwwwwoooollllffff	
	string check(string str) {
	    int ok = 1;
        int pos = 0;
        while(pos < str.size()){
            int cuantos = count(str,pos);
            if(cuantos == 0) 
                ok = 0;
            if(!get(str,(pos=pos+cuantos),cuantos,'o') or !get(str,(pos=pos+cuantos),cuantos,'l') or !get(str,(pos=pos+cuantos),cuantos,'f'))
                ok = 0;
            if((pos == str.size()-1) or !ok) break;
            pos+=cuantos;
        }
        if(ok) return "VALID";
        return "INVALID";

	}
};
