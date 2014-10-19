/*
    ID: irfan1
    LANG: C++
    TASK: concom
*/
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef vector<PII> VII;

VII out[120], in[120];
bool own[120][120], vis[120];
int E, V, now = 0;

void traverse(int v) {
     if(vis[v]) return ;
     //printf("%d %d\n", now, v);
     vis[v] = 1;
     int n_out = out[v].size();
     R(i,0,n_out) {
         int neigh = out[v][i].first;
         int n_in = in[ neigh ].size();
         int sum = 0;
         R(j,0,n_in) {
             //printf("in %d %d\n", now, in[i][j].first);
             if(own[now][ in[neigh][j].first ]) sum+=in[neigh][j].second;
         }
         //printf("%d\n", sum);
         if(sum>50) {
             own[now][neigh]=1;
             traverse(neigh);
         }
     }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    scanf("%d", &E);
    V = 100;
    R(i,0,E) {
        int va, vi, w;
        scanf("%d%d%d", &va, &vi, &w);
        va--; vi--;
        out[va].push_back(PII(vi,w));
        in[vi].push_back(PII(va,w));
    }
    R(i,0,100) own[i][i] = 1;
    R(i,0,100) {
        now = i;
        memset(vis,0,sizeof vis);
        traverse(i);
    }
    R(i,0,100) {
      R(j,0,100) {
          if(i!=j and own[i][j]) printf("%d %d\n", i+1, j+1);
      }
    }
    return 0;
}
