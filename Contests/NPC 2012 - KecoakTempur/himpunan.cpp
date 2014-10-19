#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

int teskes, n;
int x[1000111];
int main() {
    x[1] = 1;
    R(i,2,1000111) {
        int n;
        for(int j=1; j*j<=i; j++) {
            if(i%j==0) {
                x[i] = (x[i]+x[i-j])%1000000007;
                if(j*j!=i) x[i] = (x[i]+x[i-(i/j)])%1000000007;
            }
        }
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        printf("%d\n", x[n]);
    }
    return 0;
}
