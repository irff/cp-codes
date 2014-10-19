#include <cstdio>
#include <algorithm>
using namespace std;

int a[11][120000], n;
int main() {
    scanf("%d", &n);
    for(int i=0; i<10; i++) a[i][1]=1;
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
          if(j==0) {
            a[j][i]=a[1][i-1];
          } else
          if(j==1) {
            a[j][i]=a[0][i-1]+a[2][i-1]+a[4][i-1];
          } else
          if(j==2) {
            a[j][i]=a[1][i-1]+a[3][i-1]+a[5][i-1];
          } else
          if(j==3) {
            a[j][i]=a[2][i-1]+a[6][i-1];
          } else
          if(j==4) {
            a[j][i]=a[1][i-1]+a[5][i-1]+a[7][i-1];
          } else
          if(j==5) {
            a[j][i]=a[2][i-1]+a[4][i-1]+a[6][i-1]+a[8][i-1];
          } else
          if(j==6) {
            a[j][i]=a[3][i-1]+a[5][i-1]+a[9][i-1];
          } else
          if(j==7) {
            a[j][i]=a[4][i-1]+a[8][i-1];
          } else
          if(j==8) {
            a[j][i]=a[5][i-1]+a[7][i-1]+a[9][i-1];
          } else
          if(j==9) {
            a[j][i]=a[6][i-1]+a[8][i-1];
          }
          a[j][i]+=a[j][i-1];
          a[j][i]%=1000000;
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++) ans = (ans+a[i][n])%1000000;
    printf("%d\n", ans);
    return 0;
}
