#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD sol[32000];
int n, duit, a[45], ctr = 0;
bool memo[45][32099];

void rek(int ke, LLD bit, int sisa) {
    if(ke>=n and sisa!=duit) return ;
    if(ke>=n and sisa==duit) {
        sol[ctr]=bit;
        ctr++;
    }
    if(!memo[ke][sisa+16000]) {
        memo[ke][sisa+16000] = 1;
        rek(ke+1, bit|(1<<ke),sisa+a[ke]);
        rek(ke+1, bit, sisa-a[ke]);
    }
}

int main() {
    scanf("%d%d", &n, &duit);
    while(!(n==0 and duit==0)) {
        R(i,0,n) scanf("%d", &a[i]);
        rek(0,0,0);
        R(i,0,ctr) {
            R(j,0,6) {
                printf("%d", (sol[i]&(1<<j))>0);
            }
            printf("\n");
        }
        printf("%d\n", ctr);
        scanf("%d%d", &n, &duit);
    }
    return 0;
}
