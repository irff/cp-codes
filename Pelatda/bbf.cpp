#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD liburan = 0, total = 0;
LLD teskes, nseason, ep, durasi;

int main() {
    scanf("%lld", &teskes);
    for(LLD k=0; k<teskes; k++) {
        total = 0, ep = 0;
        scanf("%lld%lld", &nseason, &durasi);
        for(LLD i=0; i<nseason; i++) {
            LLD num;
            scanf("%lld", &num);
            ep+= ep + num;
        }
        scanf("%lld", &liburan);
        total = (LLD) ((LLD)ep * (LLD)durasi);
        if( liburan >= total ) {
            printf("YA\n");
        } else {
            printf("TIDAK\n");
        }
    }

    return 0;
}
