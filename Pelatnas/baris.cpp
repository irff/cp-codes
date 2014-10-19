#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
const int MOD=1000003;
int ngajah,nquery,gajah[10200];
LLD fakt(int a) {
    LLD hasil=1;
    R(i,1,a+1) hasil=(hasil*i)%MOD;
    return hasil;
}
int main() {
    scanf("%d", &ngajah);
    R(i,0,ngajah) scanf("%d", &gajah[i]);
    
    sort(gajah,gajah+ngajah);
    
    scanf("%d", &nquery);
    R(i,0,nquery) {
        LLD res=1;
        int a,b,sama=1,last; scanf("%d%d", &a, &b);
        last=gajah[a-1];
        R(j,a,b) {
            if(gajah[j]==last) {
                sama++;
            } else {
                res=(res*fakt(sama))%MOD;
                sama=1;
                last=gajah[j];
            }
        }
        res=(res*fakt(sama))%MOD;
        printf("%lld\n", res);
    }
    return 0;
}
