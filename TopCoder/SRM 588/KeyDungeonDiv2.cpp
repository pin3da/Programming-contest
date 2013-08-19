using namespace std;
#include<bits/stdc++.h>

class KeyDungeonDiv2 {
	public:
		
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {		    
	    int ans = 0;
	    for(int index = 0; index < doorG.size(); ++index){
	        int a = max(doorR[index] - keys[0],0);
	        a += max(doorG[index] - keys[1],0);
	        if(keys[2] >= a) ans++;
        }
        return ans;
	}
};
