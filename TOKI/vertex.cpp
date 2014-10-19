#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)
typedef vector<int> VI;

bool adj[120][120];

int V, Q, start, to, awal;
bool vis[120];
int ans[120];
int len[120];

void dfs(int a) {
    R(i,1,V+1) {
        if(adj[a][i] and !vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    while(scanf("%d", &V), V) {
        R(i,1,V+1) R(j,1,V+1) adj[i][j] = 0;
        while(scanf("%d", &start), start) {
            while(scanf("%d", &to), to) {
                adj[start][to] = 1;
            }
        }
        scanf("%d", &Q);
        while(Q--) {
            R(i,1,V+1) vis[i] = 0;
            scanf("%d", &awal);
            dfs(awal);
            int ctr = 0;
            R(i,1,V+1) {
                if(!vis[i]) {
                    ans[ctr++] = i;
                }
            }
            printf("%d", ctr);
            R(i,0,ctr) {
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
