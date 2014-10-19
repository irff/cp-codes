#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> PII;

const int INF = 2000111;

int teskes, n, kasus = 1;
int V, E, pulsa, cost[12000];

vector<int> adj[10010];
bool vis[10010];
int now = 2000111222, bangun = 0, kom = 0;
int orang, leni = 0;
int p[10010], x[10010];
void dfs(int a) {
    vis[a] = 1;
    now = min(now, cost[a]);
    orang++;
    int len = adj[a].size();
    R(i,0,len) {
        if(!vis[ adj[a][i] ]) {
            dfs(adj[a][i]);
        }
    }
}
int rek(int ke, int sisa) {
    if(sisa<0) return 0;
    if(ke>=leni) return 0;
    
    int maks = 0;
    
    if(sisa - x[ke] >= 0) maks=max(maks, rek(ke+1, sisa-x[ke])+p[ke]);
    
    maks=max(maks, rek(ke+1, sisa));
    
    return maks;
}

int rec(int ke, int sisa) {
    if(sisa == 0) return 0;
    if(sisa < 0) return  -INF;
    if(ke >= leni) return -INF;
    int mins = -INF;
    
    if(sisa - p[ke] >= 0) mins = max(mins, rec(ke+1, sisa-p[ke])+x[ke]);
    mins = max(mins, rec(ke+1, sisa));
    return mins;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        bangun = 0; kom = 0;
        scanf("%d%d%d", &V, &E, &pulsa);
        R(i,0,V+1) vis[i] = 0;
        R(i,0,V+1) adj[i].clear();
        R(i,0,V) scanf("%d", &cost[i]);
        R(i,0,E) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        R(i,0,V) {
            if(!vis[i]) {
                orang = 0;
                now = 2000111222;
                dfs(i);
                p[kom] = orang;
                x[kom] = now;
                kom++;
            }
        }
        leni = kom; int ans = 0;
        int maks_orang = rek(0,pulsa);
        R(i,0,leni) x[i]*=-1;
        int mins_pulsa = rec(0,maks_orang) * -1;
        printf("Kasus #%d: %d %d\n", kasus, maks_orang, mins_pulsa);
        kasus++;
    }
    return 0;
}
