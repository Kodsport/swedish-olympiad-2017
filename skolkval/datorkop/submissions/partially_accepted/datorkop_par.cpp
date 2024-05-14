//NOTE: This is not the optimal solution, but it is considered sufficiently efficient for skolkvalet

//ANOTHER NOTE: This file was originally a .c file, and not .cpp.
#include <stdio.h>
#define MAXN 1000
#define MAXC 1000
#define MAXP 1000

int x,a,y,b,n;
int T[MAXC+1][MAXC+1];
int poscost[2*MAXC*MAXP+1];

int ceildiv(int p, int q) {
  return (p<=0) ? 0 : ( (p-1)/q + 1);
}

int possible(int cost) {
  int i,j,m,dx,dy;
  for(i=0;i<=x;i++) for(j=0;j<=y;j++) T[i][j]=-1;
  T[0][0]=0;
  for(dx=0;dx<=x && (dx-1)*a<cost;dx++) {
    dy=ceildiv(cost-dx*a, b);
    for(i=0;i<=x;i++) for(j=0;j<=y;j++) if(T[i][j]!=-1) {
	  if(i+dx<=x && j+dy<=y && T[i][j]+1>T[i+dx][j+dy])
	    T[i+dx][j+dy]=T[i][j]+1;
	}
  }
  m=0;
  for(i=0;i<=x;i++) for(j=0;j<=y;j++) if(T[i][j]>=m) m=T[i][j];
  return (m>=n);
}


int bsearch(int min, int max) {   //min possible, max not possible
  int now;
  if(max-min<=1) return min;
  now=(max+min)/2;
  if(possible(poscost[now])) return bsearch(now,max);
  else return bsearch(min,now);
}


int main() {
  int nposcost,icost,i,j;
  scanf("%d %d %d %d %d", &x, &a, &y, &b, &n);
  for(i=0;i<=2*MAXC*MAXP;i++) poscost[i]=0;
  for(i=0;i<=x;i++) for(j=0;j<=y;j++) poscost[i*a+j*b]=1;
  for(nposcost=0,j=0;j<=2*MAXC*MAXP;j++) if(poscost[j]) poscost[nposcost++]=j;
  icost=bsearch(0,nposcost);
  printf("%d\n", poscost[icost]);
  return 0;
}
