#include <stdio.h>
long long MIN(long long p, long long q) {if(p<q) return p; else return q;}

int main() {
  long long a[60];
  long long c[60], price, q,rem,x,nuse;
  int i,N,M,j;
  scanf("%d %d", &N,&M);
  for(i=0;i<N;i++) scanf("%lld", &a[i]);
  for(i=0;i<M;i++) {
    scanf("%lld", &price);
    rem=0;
    for(j=N-1;j>=0;j--) {
      q=(long long)1<<j;
      x=price/q+rem*2;
      price%=q;
      nuse=MIN(a[j],x);
      a[j]-=nuse;
      rem=x-nuse;
    }
    if(rem!=0) {printf("nej\n"); return 0; }
  }
  printf("ja\n");
  return 0;
}
