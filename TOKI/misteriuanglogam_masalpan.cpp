#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i,a,b) for(int i = (int)a, c = (int)b; i<=c; i++)
#define FORD(i,a,b) for(int i = (int)a, c = (int)b; i>=c; i--)
const int MAXX = 2000000000;

int X, L, K, lo[27], ke[27], DP[100007][2], z;

int F(int now, int gg)
{
    //printf("%d %d\n", now, gg); //scanf("%d", &z);
    if( now < 0 ) return MAXX;
    //printf("%d %d\n", now, gg);
    if( now == 0 &&  (gg & 1) ) return MAXX;
    if( now == 0 && !( gg& 1) ) return 0;
    int &dp = DP[now][gg];
    if( dp != -1 ) return dp;
    int Min = MAXX;
    FOR(i, 1, L) Min = min(Min, F(now - lo[i], (gg+1) & 1));
    FOR(i, 1, K) Min = min(Min, F(now - ke[i], gg));
    return (dp = Min + 1);
}

int main()
{
    scanf("%d%d%d", &X, &L, &K);
    memset(DP, -1, sizeof (DP) );
    FOR(i, 1, L) scanf("%d", &lo[i]);
    FOR(i, 1, K) scanf("%d", &ke[i]);
    int jwb = F(X, 0); if( jwb >= MAXX ) jwb = -1;
    printf("%d\n", jwb );
    return 0;
}
