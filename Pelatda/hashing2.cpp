#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, len, memo[30][30*31], ans = 0;
void rek(int ke, int ch, int sum) {
    if(ch>=27) return ;
    //printf("%d %d\n", ke, ch);
    memo[ke][sum]++;
    R(i,ch+1,27) {
        rek(ke+1,i,sum+i);
    }
}
int main() {
    int kasus = 1;
    rek(0,0,0);
    //R(i,0,150) printf("%d\n", memo[15][i]);
    scanf("%d%d", &len, &n);
    while(len !=0 or n!=0) {
        printf("Case %d: ", kasus);
        kasus++;
        if(len > 26) {
            printf("0\n");
        } else {
            printf("%d\n", memo[len][n]);
        }
        scanf("%d%d", &len, &n);
    }
    return 0;
}
