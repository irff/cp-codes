#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
typedef long long LLD;

LLD memo[31][4][4], hasil = 0;
int n;

LLD rek(int ke, int a, int b) {
    if(ke >= n-1) return 1;
    if(memo[ke][a][b]==0) {
      LLD result = 0;
      if( (a!=1 or b!=2) and (a!=2 or b!=1)) result += rek(ke+1, b, 3);
      if( (a!=1 or b!=3) and (a!=3 or b!=1)) result += rek(ke+1, b, 2);
      if( (a!=2 or b!=3) and (a!=3 or b!=2)) result += rek(ke+1, b, 1);
      return memo[ke][a][b]=result;
    }
    return memo[ke][a][b];
}

int main() {
    scanf("%d", &n);
    if(n==1) { printf("3\n"); return 0; }
    R(i,1,3+1) R(j,1,3+1) {
        hasil+=rek(1,i,j);
    }
    printf("%lld\n", hasil);
    return 0;
}
