#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,c,d,e,ans=-2000111222;

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}
int k[2][2];
int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    for(int i=0; i<=a; i++) {
        for(int j=0; j<=b; j++) {
            k[0][0]=i;
            k[1][1]=b-j;
            if(k[0][0]+j==a and k[1][1]+a-i==b) {
                k[0][1]=j;
                k[1][0]=a-i;
                ans = max(ans, k[0][0]*c+k[0][1]*e+k[1][0]*e+k[1][1]*d);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
