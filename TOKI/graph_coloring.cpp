#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)

int teskes;
int V, E, maks = 0;
int udah = 0;
vector<int> adj[120];
int vis[120];
int ans[120];

int rek(int ke, int now, bool black, int udah) {
    if(ke>=V) {
        if(maks < udah) {
            R(i,1,V+1) {
                if(vis[i]==2) ans[i] = 1;
                else ans[i] = 0;
            }
            maks = udah;
        }
    }
    //printf("%d %d %d\n", now, black, udah);
    int len = adj[now].size();
    R(i,0,len) {
        if(!vis[adj[now][i]]) {
            if(black) {
                vis[adj[now][i]] = 1;
                rek(ke+1, adj[now][i], 0, udah);
            } else {
                vis[adj[now][i]] = 2;
                rek(ke+1, adj[now][i], 1, udah+1);
                vis[adj[now][i]] = 1;
                rek(ke+1, adj[now][i], 0, udah);
            }
            vis[adj[now][i]] = 0;
        }
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(adj, 0, sizeof adj);
        udah = 0, maks = 0;
        scanf("%d%d", &V, &E);
        R(i,0,E) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        adj[0].pb(1);
        memset(vis, 0, sizeof vis);
        rek(0,0,0,0);
        printf("%d\n", maks);
        bool tamax=0;
        R(i,1,V+1) {
            if(ans[i]) {
                if(tamax) printf(" ");
                else tamax=1;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
