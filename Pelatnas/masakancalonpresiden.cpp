#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int nmasakan,maks;
int w[10200],v[10200],dp[10200];
int main() {
    scanf("%d%d", &nmasakan, &maks);
    int id=1;
    R(i,0,nmasakan) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        while(c--) w[id]=a,v[id]=b,id++;
    }
    R(i,1,id+1) RV(j,maks,w[i])
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    printf("%d\n", dp[maks]);
    return 0;
}
