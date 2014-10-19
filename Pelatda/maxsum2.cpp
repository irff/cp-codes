#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int a[200][200];
int main() {
    scanf("%d", &n);
    R(i,0,n) R(j,0,n) {
        scanf("%d", &a[i][j]);
    }
    R(i,0,n) R(j,0,n) {
        if(i>0) a[i][j]+=a[i-1][j];
        if(j>0) a[i][j]+=a[i][j-1];
        if(i>0 and j>0) a[i][j]-=a[i-1][j-1];
    }
    //R(i,0,n) { R(j,0,n) printf("%d ", a[i][j]); printf("\n"); }
    int maxsum = -2000111222;
    R(i,0,n) R(j,0,n) {
      R(k,i,n) R(l,j,n) {
          int sum = a[k][l];
          if(i>0) sum -= a[i-1][l];
          if(j>0) sum -= a[k][j-1];
          if(i>0 and j>0) sum += a[i-1][j-1];
          maxsum=max(maxsum,sum);
      }
    }
    printf("%d\n", maxsum);
    return 0;
}
