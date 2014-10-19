#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int nujian,ngajah,maks;
int v[120],w[25],dp[10200];
char nama[255];
int main() {
    scanf("%d%d", &nujian, &maks);
    R(i,1,nujian+1) scanf("%d", &v[i]);
    scanf("%d", &ngajah);
    R(i,0,ngajah) {
        memset(dp,0,sizeof dp);
        scanf("%s", nama);
        R(j,1,nujian+1) scanf("%d", &w[j]);
        
        R(j,1,nujian+1)
            RV(k,maks,w[j])
               dp[k]=max(dp[k], dp[k-w[j]] + v[j]);
               
        double hasil=dp[maks];
        
        printf("%s %.1f\n", nama, hasil);
    }
    return 0;
}
