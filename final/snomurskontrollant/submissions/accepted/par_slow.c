#include <stdio.h>
#include <assert.h>

int ok() {
  int W,H,B,i,j,st,le,h,under[100000],over[100000],now;
  scanf("%d %d\n", &W,&H);
  assert(W <= 1000 && H <= 1000);
  for(i=0;i<W;i++) under[i]=1;
  for(h=0;h<H;h++) {
    scanf("%d", &B);
    now=0;
    for(i=0;i<W;i++) over[i]=0;
    for(i=0;i<B;i++) {
      scanf("%d %d", &st, &le);
      if(st<now) return 0;              //Overlap check, not needed
      if(i==0 && st!=0) return 0;       //Left edge check, not needed
      if(i==B-1 && st+le!=W) return 0;  //Right edge check, not needed
      now=st+le;
      if(i>0 && (!under[st] || !under[st-1])) return 0;
      if(i<B-1 && (!under[st+le] || !under[st+le-1])) return 0;
      for(j=st;j<st+le;j++) over[j]=1;
    }
    for(i=0;i<W;i++) {
      if(!under[i] && !over[i]) return 0;
      under[i]=over[i];
    }
  }
  return 1;
}

int main() {
  if(ok()) printf("YES\n");
  else printf("NO\n");
  return 0;
}
      
