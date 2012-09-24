#include <stdio.h>
#include <string.h>

#define MAX 28000
#define NUMS 40


int main(){
  int n, f, numbers[NUMS+1];
  unsigned char sum[NUMS/2+2][2*MAX+1];
  enum {NONE=0, P, N, Q};
  int i, j, k1, k2, field, index;

  while(1){
    scanf("%d %d", &n, &f); 
    if (n == 0 && f == 0)
      return 0;
  
    for(i = 0; i < n; i++)
      scanf("%d", &numbers[i]);
    
    index = 0;

    memset(sum, 0, (2*MAX+1)*(n/4+1)*sizeof(char));
    memset(sum[NUMS/4+1], 0, (2*MAX+1)*(n/4+1)*sizeof(char));

    sum[0][MAX+numbers[0]] = 1;
    sum[1][MAX+numbers[0]] |= P;
    
    sum[0][MAX-numbers[0]] = 1;
    sum[1][MAX-numbers[0]] |= N;

    for(i=1; i < n; i++){
		  for(j=0; j<=2*MAX; j++){
			if (!sum[11*index][j])
			  continue;
			field = i/4 + 1 + 11*!index;

			if(j+numbers[i] <= 2*MAX){
			  sum[11*!index][j+numbers[i]] = 1;
			
			  k1 = 11*index +1;
			  k2 = 11*!index +1;
		  	  while(k2 <= field){
				sum[k2][j+numbers[i]] |= sum[k1][j];
				k1++;
				k2++;
			  }
			  sum[field][j+numbers[i]] |= (P << 2*(i % 4));
			}
	
			if(j-numbers[i] >= 0){
			  sum[11*!index][j-numbers[i]] = 1;
			
			  k1 = 11*index +1;
			  k2 = 11*!index +1;
			  while(k2 <= field){
				sum[k2][j-numbers[i]] |= sum[k1][j];
				k1++;
				k2++;
			  }
			  sum[field][j-numbers[i]] |= (N << 2*(i % 4));
			}
		  }
		  memset(sum[11*index], 0, (2*MAX+1)*((n-1)/4+2)*sizeof(char));
		  index = !index;
    }

    if(!sum[11*index][MAX+f]){
      printf("*\n");
      continue;
    }

    field = 11*index+1;
    for(i=0; i < n; i++)
      switch((sum[field+i/4][MAX+f] >> 2*(i % 4)) & 3){
      case P: putchar('+'); break;
      case N: putchar('-'); break;
      default: putchar ('?'); break;
      }
    printf("\n");
  }
}
