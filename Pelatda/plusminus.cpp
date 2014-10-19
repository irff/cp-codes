#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

int n;
bool nemu = 0;
char s[200];
int setbit(int num, int pos) {
    int ans = num | (1<<pos);
    return ans;
}

void checkbit(int num) {
    for(int i=0; i<=20; i++) {
        printf("%d", (num&(1<<i))>0);
    }
}

bool istrue(int num, int pos) {
    return (num&(1<<pos))>0;
}

void rek(int ke, int num, int bm) {
    if(ke == n) {
        if(num==0) {
            nemu = 1;
            for(int i=0; i<n; i++) {
                if(i>0) {
                    printf("%c", istrue(bm,i)?'-':'+');
                }
                printf("%d", i+1);
            }
            printf("\n");
        }
        return ;
    }
    rek(ke+1, num+(ke+1), bm);
    //minus
    if(ke > 0) {
        bm = setbit(bm,ke);
        rek(ke+1, num-(ke+1), bm);
    }
    
}

int main() {
    gets(s);
    scanf("%d", &n);
    rek(0,0,0);
    if(!nemu) printf("-1\n");
    return 0;
}
