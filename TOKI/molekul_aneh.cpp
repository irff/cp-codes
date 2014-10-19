#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

char m[1200][1200];
int n, s;
LLD a, b;
LLD pkt[42];

int main() {
    pkt[0] = 1;
    R(i,1,40) pkt[i] = pkt[i-1]*3;
    //R(i,1,40) printf("%lld\n", pkt[i]);
    scanf("%d%d", &n, &s);
    scanf("%lld%lld", &a, &b); a--,b--;
    
    for(LLD i = a; i<a+s; i++) {
        for(LLD j = b; j<b+s; j++) {
            bool bisa = 1;
            for(int k = n; k>=1; k--) {
                LLD x = i%pkt[k], y = j%pkt[k];
                if( (x+y)%2 == 1) {
                    bisa = 0; break;
                }
            }
            if(bisa) printf("0");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}
