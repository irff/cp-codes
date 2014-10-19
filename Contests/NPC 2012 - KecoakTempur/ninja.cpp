#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

int teskes, n;
long long m[2000][2000], bukit = 0, lembah = 0, now = 0;
bool vis[2000][2000];
bool low = 0, high = 0;

void dfs(int a, int b) {
    if(a>=0 and a<n and b>=0 and b<n) {
        if(m[a][b] < now) { low = 1; return ; }
        else if(m[a][b] > now) { high = 1; return ; }
        
        if(vis[a][b]) return ;
        
        vis[a][b] = 1;
        dfs(a-1,b-1);
        dfs(a-1,b);
        dfs(a-1,b+1);
        dfs(a,b+1);
        
        dfs(a+1,b+1);
        dfs(a+1,b);
        dfs(a+1,b-1);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d", &teskes);
    R(k,0,teskes) {
        memset(vis, 0, sizeof vis);
        bukit = 0, lembah = 0;
        scanf("%d", &n);
        R(i,0,n) {
            R(j,0,n) {
                scanf("%lld", &m[i][j]);
            }
        }
        R(i,0,n) {
          R(j,0,n) {
            if(!vis[i][j]) {
                low = 0, high = 0;
                now = m[i][j];
                dfs(i,j);
                if(low and !high) bukit = bukit+1;
                else if(high and !low) lembah = lembah+1;
                else if(!low and !high) lembah = lembah+1, bukit = bukit+1;
            }
          }
        }
        printf("%lld %lld\n", bukit, lembah);
    }
    return 0;
}
