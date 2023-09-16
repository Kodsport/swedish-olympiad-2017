#include <stdio.h>

int main() {
  int n,s,i,b;
  scanf("%d", &n);
  s=0;
  for(i=0;i<n;i++) {scanf("%d", &b); s += ( (b>7)?7:b ) -  (  (i%2==0)?2:3 ) ; }
  printf("%d\n",s);
  return 0;
}
