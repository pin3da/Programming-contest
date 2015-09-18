#include<bits/stdc++.h>
using namespace std;

int minchange(char a, char b){
    return min(abs(a - b),(26 - abs(a - b)));
}

int main(){
    int n,p;
    while( cin >> n >> p){
        int mid = n>>1;
        string s,a,b; cin >> s;
        a = s.substr(0,mid);
        b = (n & 1)?s.substr(mid + 1,mid) : s.substr(mid,mid);
        
        reverse(b.begin(), b.end());
       
        
        int idx;
        if(n & 1){
            if(p == (n >> 1) + 1) 
                 idx = n - p - 1;
            else idx = ( p >= mid ) ? n - p : p - 1;
        }else
            idx = ( p >= mid ) ? n - p : p - 1;
        
        int l = 0, r = mid - 1;
        
        while( r > idx && a[r] == b[r]) r--;
        while( l < idx && a[l] == b[l]) l++;
               
        int sol = 0;
        int it = idx;
        
        if(idx - l <= r - idx){
                        
            while(it >= l){
                if(it != idx) sol++;
                sol += minchange(a[it],b[it]);
                a[it] = b[it] = 'a';
                it --;
            }
            it++;
            while( it  <= r){        
                if(it != r) sol++;
                sol += minchange(a[it],b[it]);
                a[it] = b[it] = 'a';
                it ++;
            }    
        }else{
            while(it <= r){
                if(it != idx) sol++;
                sol += minchange(a[it],b[it]);
                a[it] = b[it] = 'a';
                it ++;
            }
            
            it--;
            while( it  >= l){        
                if(it != l) sol++;
                sol += minchange(a[it],b[it]);
                
                a[it] = b[it] = 'a';
                it --;
            }
        }
                 
        cout << sol  << endl;
    }
    
    
}


