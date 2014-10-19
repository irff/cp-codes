#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int teskes, n, m;
int a[12000];
bool bisa = 0;
bool memo[10111][310];
void rek(int ke, int val) {
    if(bisa) return ;
    if(ke >= n-1 and !memo[ke][val+150]) {
        //printf("ke = %d, val = %d\n", ke, val);
        memo[ke][val+150] = 1;
        if(val % m == 0) bisa = 1;
        return ;
    }
    if(!memo[ke][val+150]) {
        //printf("ke = %d, val = %d\n", ke, val);
        memo[ke][val+150] = 1;
        rek(ke+1, (val+a[ke+1]) % m);
        rek(ke+1, (val-a[ke+1]) % m);
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(memo, 0, sizeof memo);
        bisa = 0;
        scanf("%d%d", &n, &m);
        R(i,0,n) {
            scanf("%d", &a[i]);
            a[i]%=m;
            //printf("%d ", a[i]);
        }
        //printf("\n");
        rek(0,a[0]);
        if(bisa) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;  
}
