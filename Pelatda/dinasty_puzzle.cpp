#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, ans = 0;
char s[500111][12];
int len[500111];
void rek(int ke, char awal, char akhir, int total) {
    if(ke > n) {
        if(awal==akhir) ans = max(ans, total);
        return ;
    }
    //printf("%d %c %c %d\n", ke, awal, akhir, total);
    if(awal=='#') {
        rek(ke+1, s[ke][0], s[ke][len[ke]-1], total+(len[ke]));
    } else
    if(akhir == s[ke][0]) {
        rek(ke+1, awal, s[ke][len[ke]-1], total+(len[ke]-1));
    }
    rek(ke+1, awal, akhir, total);
    
}

int main() {
    scanf("%d", &n);
    R(i,0,n) { scanf("%s", &s[i]); len[i] = strlen(s[i]); }
    rek(0, '#', '*', 0);
    printf("%d\n", ans);
    return 0;
}
