#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, len, memo[30][30][30*31], ans = 0;
int rek(int ke, int ch, int sisa) {
    //printf("%d %d\n", ke, sisa);
    if(ke >= len) {
        if(sisa==0) {
            return memo[ke][ch][sisa] = 1;
        }
        return 0;
    } else
    if(sisa > 0) {
        if(!memo[ke][ch][sisa]) {
            int hasil = 0;
            R(i,ch+1,27) {
                hasil+=rek(ke+1, i, sisa-i);
            }
            return memo[ke][ch][sisa] = hasil;
        } else {
            return memo[ke][ch][sisa];
        }
    }
    return 0;
}
int main() {
    int kasus = 1;
    scanf("%d%d", &len, &n);
    while(len !=0 or n!=0) {
        printf("Case %d: ", kasus);
        kasus++;
        if(len > 26) {
            printf("0\n");
        } else {
            memset(memo,0, sizeof memo);
            ans = rek(0,0,n);
            printf("%d\n", ans);
        }
        scanf("%d%d", &len, &n);
    }
    return 0;
}
