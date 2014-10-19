#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

const int INF = 2000111222;

int N, m[400][400], build[400];
int memo[400][400], minbuild = INF;
bool nemu = 0;
long long ans = 0;

int main() {
    scanf("%d", &N);
    R(i,0,N) scanf("%d", &build[i]);
    R(i,0,N) memo[i] = INF;
    R(i,0,N) R(j,0,N) scanf("%d", &m[i][j]);
    R(i,0,N) m[i][i] = build[i];
    R(k,0,N) R(i,0,N) R(j,0,N) memo[i] = min(memo[i], m[i][j]);
    
    R(i,0,N) ans += memo[i];
    printf("%lld\n", ans);
    return 0;
}
