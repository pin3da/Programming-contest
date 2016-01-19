#include <stdlib.h>
#include <stdio.h>
#include <cmath>

struct Square {
  int x, y, l;

  void moveNear(Square B) {
    int aux = l;
    l = l/2;
    if (x <= B.x) {
      if (x + l <= B.x) 
        x += l;   
      else 
        x = B.x;
    } else {
      if (x-l >= B.x) 
        x -= l;
      else 
        x = B.x;
    }

    if (y <= B.y) {
      if (y + l <= B.y) 
        y += l;   
      else 
        y = B.y;
    } else {
      if (y-l >= B.y) 
        y -= l;
      else 
        y = B.y;
    }
    l = aux;
  }
};

int main() {
  int n, aah;
  scanf("%d %d", &n, &aah);

  Square Old;
  for (int i = 0; i < n; i++) {
    Square P;
    scanf("%d %d %d", &(P.x), &(P.y), &(P.l));
   /* Square Aux;
    Aux.x = P.x;
    Aux.y = P.y;
    Aux.l = P.l;*/
    if (i != 0 && (std::abs(P.x - Old.x) - Old.l/2 - P.l/2 > 0 ||
          std::abs(P.y - Old.y) - Old.l/2 - P.l/2 > 0)) {
      //Old.moveNear(P); 
      //P.moveNear(Old);
      double h = 
        std::sqrt(std::pow(Old.y - P.y, 2) + std::pow(Old.x - P.x,2));
      double theta = std::atan(std::abs(Old.y - P.y) / std::abs(Old.x - P.x));
      double hll = (std::abs(Old.x - P.x) - P.l/2)/std::cos(theta);
      double hl = (Old.l/2)/std::cos(theta);
      double distance = hll - hl;

      if (distance > aah) { 
        printf("OUCH\n");
        return 0;
      }
      
    }
    Old.x = P.x;
    Old.y = P.y;    
    Old.l = P.l;
  }
  
  printf("YEAH\n");
  return 0;
}
