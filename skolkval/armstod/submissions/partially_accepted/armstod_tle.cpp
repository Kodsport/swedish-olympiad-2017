#include <stdio.h>


int main() {
  char rad[101];
  int i,j,n,num,max,v,h;
  scanf("%d", &n);
  scanf("%s", rad);
  max=0;
  for(i=0;i<(1<<n);i++) {
    num=0;
    for(j=0;j<n;j++) {
      v=(i>>j)&1;
      h=1-((i>>((j+1)%n))&1);
      //printf("%d%d ",v,h);
      if((v && (rad[j]=='V')) || (h && (rad[j]=='H')) || ((v || h) && rad[j]=='A') || ((v && h) && rad[j]=='B') || (rad[j]=='I')) num++;
    }
    //printf("     num=%d\n",num);
    if(num>max) max=num;
  }
  printf("%d\n", max);
  return 0;
}
