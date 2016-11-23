#include <stdio.h>

int v[100],h[100],n;

int numsat(int occfirst, int occlast) {
  int occ, num, i;
  occ=occfirst;
  num=0;
  for(i=0;i<n;i++) {
    if(occ && v[i]) {
      occ=0;
    }
    else {
      occ=h[i];
      num++;
    }
  }
  if(occ && occlast) num--;
  return num;
}

int main() {
  char rad[101];
  int i,num1,num2;
  scanf("%d", &n);
  scanf("%s", rad);
  for(i=0;i<n;i++) {
    v[i]=(rad[i]=='V' || rad[i]=='B');
    h[i]=(rad[i]=='H' || rad[i]=='B');
  }
  num1=numsat(0,1); //Assume first person uses border rest
  num2=numsat(1,0); //Assume last person uses border rest
  printf("%d\n", (num1>num2) ? num1 : num2);
  return 0;
}
