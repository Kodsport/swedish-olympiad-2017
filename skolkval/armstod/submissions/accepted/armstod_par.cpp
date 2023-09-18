#include <stdio.h>

int n;
char rad[101];

int numsat(int occfirst, int occlast) {
  int occ, num, i,v,h;
  occ=occfirst;
  num=0;
  for(i=0;i<n;i++) {
    v=(rad[i]=='V' || rad[i]=='B' || (rad[i]=='A' && !occ));
    h=(rad[i]=='H' || rad[i]=='B' || (rad[i]=='A' && occ));
    if(occ && v) occ=0;
    else {
      occ=h;
      num++;
    }
  }
  if(occ && occlast) num--;
  return num;
}

int main() {
  int i,num1,num2;
  scanf("%d", &n);
  scanf("%s", rad);
  num1=numsat(0,1); //Assume first person uses border rest
  num2=numsat(1,0); //Assume last person uses border rest
  printf("%d\n", (num1>num2) ? num1 : num2);  //Output maximum of these
  return 0;
}
