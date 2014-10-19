#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int teskes, n, ans = INF;
int memo[1000][102][52];

int rek(int ke, int a, int b, int c) {
    if(!memo[a][b][c]) {
        if(ke >= n) {
            return 0;
        }
        int ret = INF;
        if(a>=8) ret = min(ret, rek(ke+1, a-8, b, c)+8);
        if(a>=3 && b>=1) ret = min(ret, rek(ke+1, a-3, b-1, c)+4);
        if(b>=2) ret = min(ret, rek(ke+1, a+2, b-2, c)+2);
        if(c>=1) ret = min(ret, rek(ke+1, a+2, b, c-1)+1);
        if(a>=3 && c>=1) ret = min(ret, rek(ke+1, a-3, b+1, c-1)+4);
        return memo[a][b][c] = ret;
    }
    return memo[a][b][c];
    
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int a, b, c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        memset(memo, 0, sizeof memo); 
        ans = rek(0, a, b, c);
        printf("%d\n", ans);
    }

    return 0;
}
