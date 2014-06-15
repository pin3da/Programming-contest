using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 1010;

int main() {

  char line[555];
  while (scanf("%s", line)) {
    if (line[0] == '#')
      break;

    vector<int> frec(26,0);
    for (int i = 0; line[i] != '\0'; ++i)
      frec[line[i] - 'a']++;

    int odd = 0;
    for (int i = 0; i < 26; ++i)
      if  ((frec[i] & 1) != 0) odd++;

    for (int i = 0; i < 26; ++i)
      if  (((frec[i] & 1) != 0) and (odd > 1)) {
        printf("%c",('a' + i));
        odd--;
      }

    puts("");


  }

  return 0;
}
