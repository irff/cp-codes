#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, ctr = 0, len = 0;
char s[2000];
char memo[2000][100];

void rek(int ke, char s[]) {
     if(ke >= len) {
         strcpy(memo[ctr++],s);
     } else {
         R(i,1,3) {
             s[ke] = i + '0';
             rek(ke+1,s);
         }
     }
}
int main() {
    R(k,1,10) {
        len = k;
        R(i,1,3) {
            s[0] = i + '0';
            rek(1,s);
        }
        if(ctr > 1000) break;
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        printf("%s\n", memo[n-1]);
    }
    return 0;
}
