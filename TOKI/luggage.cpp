#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[1000];
int a[30], nbarang = 0, sum = 0;
bool bisa = 0, memo[22][4200];

void rek(int ke, int sisa) {
    if(!memo[ke][sisa]) {
        memo[ke][sisa] = 1;
        if(bisa) return ;
        if(ke>=nbarang and sisa>0) return ;
        if(ke>=nbarang and sisa==0) bisa = 1;
        if(sisa-a[ke]>=0) rek(ke+1, sisa-a[ke]);
        rek(ke+1, sisa);
    }
}

int main() {
    scanf("%d\n", &teskes);
    while(teskes--) {
        memset(memo, 0, sizeof memo);
        nbarang = 0; sum = 0;
        gets(s);
        char *str = strtok(s, " ");
        while(str!=NULL) {
            a[nbarang++] = atoi(str);
            sum+=a[nbarang-1];
            str = strtok(NULL, " ");
        }
        if(sum&1) printf("NO\n");
        else {
            sum/=2;
            bisa = 0;
            rek(0, sum);
            if(bisa) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
